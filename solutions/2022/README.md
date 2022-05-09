# Nyuszik

Oldja meg az alábbi feladatot C nyelven, ami egy Linux rendszeren tud futni. (Ez lehet a tárgy  kiszolgálója (opsys.inf.elte.hu) vagy egy saját lokális Linux rendszer!) Az eredményt (csak a C forrásfájlt, pl: alma.c) töltse fel maximum 1.5 óra után a kezdést követően. A feladatokat a gyakorlatvezetők fogják értékelni és az eredményt bejegyzik. A dolgozat eredménye elégséges ha az első feladat kész, közepes ha az első kettő stb.

A Húsvét elmúlt, és a húsvéti locsoló verseny győztese átveszi a hatalmat és Ő lesz az új "Főnyuszi".  Ahogy végigsétál a birodalmán, látja a tavasz "gyümölcseit", akik vidáman szaladgálnak a frissen kizöldült határban. Elhatározza, hogy "nyusziszámlálást" kell tartani.

"Főnyuszi" (szülő) nem tart teljes népszámlálást, választ kettőt a területek( Barátfa, Lovas, Kígyós-patak , Káposztás , Szula, Malom telek, Páskom) közül, ahova nyuszi számláló biztost (gyerek) küld.

1. Főnyuszi felkéri a nyuszi számláló biztosokat, Tapsit és Fülest (létrehozza a gyerekeket) és megvárja, amíg a biztosok felkészülnek a feladatra, amit jelzéssel (tetszőleges) nyugtáznak. Miután főnyuszi fogadta a jelzéseket üzenetsoron továbbítja mindkét számláló biztosnak a kiválasztott területet, ahol fel kell mérni az állományt. Tapsi is és Füles is kiírja a feladatul kapott terület-nevet a képernyőre, majd befejezik aznapra a tevékenységüket( terminálnak), amit Főnyuszi megvár, majd képernyőre írja, hogy Tapsi is és Füles is nyugovóra tért, majd Ő is befejezi aznapra a munkát.
2. Miután Tapsi és Füles képernyőre írja a kapott terület-nevet, elkezdik a nyuszik számlálását.  Az eredményeket (véletlenszám 50 és 100 között) szintén üzenetsoron küldik vissza Főnyuszinak, aki a képernyőre írja azokat.  Főnyuszinak rendelkezésre áll az előző nyusziszámlálás eredménye (véletlenszám 50 és 100 között minden területre), így rögtön összehasonlítja, hogy nyuszifogyás vagy gyarapodás történt-e az adott területen,  aminek eredményét szintén képernyőre írja.
3. Ha nyuszifogyás történt a területen,  akkor Főnyuszi "Keress_meg" jelzést, különben "Hazaterhet" jelzést küld Tapsinak és Fülesnek. Ha "Hazaterhet" jelzést kapott valamelyik biztos, akkor befejezi tevékenységét, ha "Keress_meg" jelzést kap, akkor újra körbe megy a területen és az új számlálás eredményét (70 és 100 közötti véletlenszám) üzenetsoron újra visszaküldi, amit Főnyuszi képernyőre ír.
4. Főnyuszi a  két területi minta eredményét osztott memóriába és a képernyőre is kiírja,  és ezek alapján állapítsa meg, hogy  népességfogyás vagy gyarapodás volt tapasztalható a nyusziszámlálás során.  Az osztott memóriába történő írást védje szemaforral.

## Fordítási utasítások

```
gcc -Wall -fsanitize=address -pthread -lrt main.c fradilib/*.c
```
