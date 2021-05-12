#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

#include "../../cso.h"
#include "../../szemafor.h"
#include "../../szignal.h"
#include "../../uzenet.h"

#define OLTAKOZAS SIGUSR1

int main(int argc, char **argv) {
    sem_t *szemafor = szemafor_letrehozas("/jegyzokonyv", 0);
    if (argc != 2) {
        printf("Add meg, hogy hany beteg jon ma!\n");
        exit(1);
    }
    int arg = atoi(argv[1]);
    signal(OLTAKOZAS, handler);

    pid_t csormester = -1;
    pid_t ursula = -1;

    int *csormester_cso = cso_letrehoz();
    int *ursula_cso = cso_letrehoz();

    key_t kulcs = ftok(argv[0], 1);

    int csor_uzenetsor = uzenetsor_letrehoz(kulcs);
    int urs_uzenetsor = uzenetsor_letrehoz(kulcs);

    csormester = fork();
    if (csormester == 0) {
        printf("%d folyamat a Csormester\n", getpid());
        szignalkuldes(getppid(), OLTAKOZAS);
        int oltandok;
        csobol_adat(csormester_cso, &oltandok, sizeof(int));
        printf("%d darab oltando erkezett csormesterhez\n", oltandok);

        int oltottak = 0;
        srand(time(NULL) + getpid());
        for (int i = 0; i < oltandok; ++i) {
            if (rand() % 100 < 80) {
                oltottak++;
            }
        }
        char *eredmeny = calloc(100, sizeof(char));
        sprintf(eredmeny, "Csormester beoltott %d/%d allatot.", oltottak, oltandok);
        uzenet_kuld(csor_uzenetsor, eredmeny);

        exit(0);
    }

    ursula = fork();
    if (ursula == 0) {
        printf("%d folyamat az Ursula\n", getpid());
        sleep(1);
        szignalkuldes(getppid(), OLTAKOZAS);
        int oltandok;
        csobol_adat(ursula_cso, &oltandok, sizeof(int));
        printf("%d darab oltando erkezett ursulahoz\n", oltandok);

        int oltottak = 0;
        srand(time(NULL) + getpid());
        for (int i = 0; i < oltandok; ++i) {
            if (rand() % 100 < 80) {
                oltottak++;
            }
        }
        char *eredmeny = calloc(100, sizeof(char));
        sprintf(eredmeny, "Ursula beoltott %d/%d allatot.", oltottak, oltandok);
        uzenet_kuld(urs_uzenetsor, eredmeny);
        exit(0);
    }

    pause();
    pause();
    int argurs;
    int argcsor;

    if (arg % 2 == 1) {
        arg--;
        argurs = arg / 2;
        argcsor = arg / 2 + 1;

    } else {
        argurs = arg / 2;
        argcsor = arg / 2;
    }
    csobe_adat(ursula_cso, &argurs, sizeof(int));
    csobe_adat(csormester_cso, &argcsor, sizeof(int));
    char uzenet1[100];
    char uzenet2[100];
    uzenet_fogad(csor_uzenetsor, uzenet1);
    uzenet_fogad(urs_uzenetsor, uzenet2);
    // ha lenne mas program ami feloldana, akkor itt kene egy sem_wait
    FILE *jegyzokonyv = fopen("jk.txt", "a");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(jegyzokonyv, "Oltas ekkor: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900,
            tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    fprintf(jegyzokonyv, "%s\n%s\n-------------\n", uzenet1, uzenet2);

    fclose(jegyzokonyv);

    szemafor_mehet(szemafor); // felteteleztem, hogy a tobbi jegyzokonyvbe iro folyamat sem_wait-tel
                              // elsobbseget ad Dr. Bubonak. Mivel nincs masik folyamat, nem
                              // irhattam meg ugy, hogy var a szem-re, mert akkor sosem lenne vege.

    waitpid(csormester, NULL, 0);
    waitpid(ursula, NULL, 0);
}