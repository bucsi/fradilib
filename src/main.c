#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //sleep, fork
#include <sys/types.h> //fork, ftok
#include <sys/ipc.h> //ftok

#include <wait.h>
#include <time.h>
#include <signal.h>

#include "fradilib/cso.h"
#include "fradilib/szignal.h"
#include "fradilib/uzenet.h"
#include "fradilib/szemafor.h"
#include "fradilib/osztmem.h"






int main(int argc, char* argv[]){

    const char termekek[6][200] = {
        "Illés Zoltán: a C# programozási nyelv (zöld-fehér borítós kiadás)",
        "Bucsánszki Tamás: Miért ne C nyelven tanítsák az Operációs Rendszerek tárgyat (bővített kiadás)",
        "O'Reilly Media: Learning Python, 5. kiadás",
        "Kerninghan, Ritchie: A C programozási nyelv",
        "Wikibooks - Non-programmers guide to python3 (nyomtatott kiadás)",
        "Gerely Viktor András: A Javascript nyelv és a Stockholm-szindróma"
    };

    pid_t vasarlo1, vasarlo2; // a két gyerek process
    int* szemet; // a waitpid paramétere
    char buffer [1024]; // buffer a beolvasásokhoz

    key_t kulcs = ftok(argv[0], 1); // kulcs az üzenetsorhoz és az osztott memóriához
    
    int uzenetsor = uzenetsor_letrehoz(kulcs);

    char* s = memoria_letrehoz(kulcs);
    char* s2 = memoria_letrehoz(kulcs);

    sem_t* semid = szemafor_letrehozas("/vasarlas1",0);
    sem_t* semid2 = szemafor_letrehozas("/vasarlas2",0);

    int* v1cso = cso_letrehoz();
    int* v2cso = cso_letrehoz();


    srand(time(0));

    vasarlo1 = fork();
    if(vasarlo1 == 0){
        //gyerek1
        
        //signal handlerek beállítása
        signal(SIGRTMIN, numOverSignal);
        signal(SIGRTMIN+1, numOverSignal);
        signal(SIGRTMIN+2, numOverSignal);
        sleep(2);

        printf("%d: Be szeretnék menni\n", getpid());
        
        // signal a boltosnak, hogy készen áll
        kill(getppid(), SIGUSR1);

        // beengedi őket a boltos?
        cso_olvas(v1cso, buffer);
        printf("%d: Ezt mondta a boltos: %s\n",getpid(),  buffer);
        sleep(2);

        // köszön neki a boltos
        uzenet_fogad(uzenetsor);
        // visszaköszön
        uzenet_kuld(uzenetsor, "Jó napot kívánok!");
        sleep(4);


        printf("%d választ könyvet, amit meg szeretne venni...\n", getpid());
        
        srand(time(0));
        memoria_ir(s, termekek[rand()%6]);
        szemafor_mehet(semid);
        pause();


        return 0;
    }else{
        vasarlo2 = fork();
        if(vasarlo2 == 0){
            //gyerek2

            //signal handlerek beállítása
            signal(SIGRTMIN, numOverSignal);
            signal(SIGRTMIN+1, numOverSignal);
            signal(SIGRTMIN+2, numOverSignal);
            sleep(2);

            printf("%d: Én is bemennék\n", getpid());
            
            // signal a boltosnak, hogy készen áll
            kill(getppid(), SIGUSR1);

            // beengedi őket a boltos?
            cso_olvas(v2cso, buffer);
            printf("%d: Nekem ezt: %s\n",getpid(),  buffer);
            sleep(2);

            // köszön neki a boltos
            uzenet_fogad(uzenetsor);
            // visszaköszön
            uzenet_kuld(uzenetsor, "Szia!");
            sleep(4);


            printf("%d választ könyvet, amit meg szeretne venni...\n", getpid());
            srand(time(0));
            memoria_ir(s2, termekek[rand()%6]);
            szemafor_mehet(semid2);
            pause();

            return 0;
        }else{
            printf("Eladó (szülő) %d, vásárlók(gyerekek) %d és %d PID-ű folyamatok.\n", getpid(), vasarlo1, vasarlo2);
            signal(SIGUSR1, handler);
            pause();

            //vásárlók beengedése
            cso_ir(v1cso, "kinyitottam, bejöhettek\0");
            cso_ir(v2cso, "kinyitottam, bejöhettek\0");
            sleep(1);

            //köszönés a vásárlóknak
            uzenet_kuld(uzenetsor, "Csodálatos, szép jó napot kívánok önnek!");
            uzenet_kuld(uzenetsor, "Örülök, hogy újra látom, jó reggelt!");
            sleep(2);

            //vásárlók köszönésének fogadása
            uzenet_fogad(uzenetsor);
            uzenet_fogad(uzenetsor);
            sleep(2);

            //várakozás az első vásárló választására
            szemafor_var(semid);
            printf("%d: Az első vevő ezt szeretné megvenni: %s\n", getpid(), s);

            szemafor_var(semid2);
            printf("%d: A második vevő ezt szeretné megvenni: %s\n", getpid(), s);

            //visszajelzés: 0-1-2 darab könyv van hátra
            kill(vasarlo1, SIGRTMIN + rand()%2);
            kill(vasarlo2, SIGRTMIN + rand()%2);
        }
    }

    waitpid(vasarlo1, szemet, 0);
    waitpid(vasarlo2, szemet, 0);


    return 0;
}