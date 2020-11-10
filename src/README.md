# Könyvesbolt
A `main.c` a 2020 05.14-i zárthelyi feladat megoldása.

Oldja meg az alábbi feladatot C nyelven, ami egy Linux rendszeren tud futni. (Ez lehet a tárgy  kiszolgálója (opsys.inf.elte.hu) vagy egy saját lokális Linux rendszer!) Az eredményt (csak a C forrásfájlt, pl: alma.c) töltse fel maximum 1.5 óra után a kezdést követően. A feladatokat a gyakorlatvezetők fogják értékelni és az eredményt bejegyzik. A dolgozat eredménye elégséges ha az első feladat kész, közepes ha az első kettő stb.

A kisebb boltokba egyszerre csak két vevő (gyerekek) tartózkodhat és maga az eladó (szülő). Az eladó akkor zárhatja be a boltot, ha mindkét vásárló elment. (Várja be a gyerekek befejeződését)

1.  Reggel nyitáskor a bolt üres. Megérkezéskor a két vásárló beszól a boltba, hogy bemehetnek-e. (jelzést küldenek). Az eladó mindkettőnek csövön át küldi az üzenetet, hogy kinyitott, bemehetnek. Ezt az üzenetet a vásárlók kiírják a képernyőre és kilépnek.

2. Az eladó mindkettőnek köszön (üzenetsoron át), amit azok viszonoznak is. (képernyőre írnak)

3. A két vevő elmondja, hogy mit szeretnének (véletlen megnevezés egy árulistából) és a kívánságukat beírják az osztott memóriába, ahonnan az eladó kiolvassa és kiírja a képernyőre. Szemaforral védje az olvasás-írás műveletet!

4. Az eladó megnézi a készletet a raktárban és mindkét vásárlónak visszajelez, hogy hány darab található a kért áruból. (Jelzés, véletlenszám 0-2) Azok fogadják az adatot és 0 esetén azt írják ki, hogy Kár, hogy nincs, egyébként pedig a köszönöm, kérek egyet.

## Fordítási utasítások
```
gcc -Wall -fsanitize=address -pthread -lrt main.c fradilib/*.c
```