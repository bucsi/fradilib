# Állatklinika
A `main.c` a 2021. 05. 10-i zárthelyi feladat megoldása. A megoldás publikálásáért köszönet Arkinak!

Oldja meg az alábbi feladatot C nyelven, ami egy Linux rendszeren tud futni. (Ez lehet a tárgy  kiszolgálója (opsys.inf.elte.hu) vagy egy saját lokális Linux rendszer!) Az eredményt (csak a C forrásfájlt, pl: alma.c) töltse fel maximum 1.5 óra után a kezdést követően ezen a Canvas oldalon. A feladatokat a gyakorlatvezetők fogják értékelni és az eredményt bejegyzik. A feladatban kért jelzés, cső vagy üzenetsor típusa, ha a feladat konkrétan nem nevesíti,  bármelyik tanult lehet.A dolgozat eredménye elégséges ha az első feladat kész, közepes ha az első kettő stb.

Az állatok körében (is) arat a vírus. Hála Oroszlán gondoskodásának már minden állatklinikán ott van a megfelelő vakcina, így Dr. Bubó (szülő) , asszisztense Ursula (gyerek) és a rend rendíthetetlen híve Csőrmester(másik gyerek) segítik a gyors és hatékony "vakcináció" folyamatát.

1. Dr. Bubó megkezdi rendelését. Ursulát és Csőrmestert megkéri foglalják el állásaikat(gyerekfolyamatok elindulnak), és jelezzenek vissza(signal), hogy kezdődhet az "oltakozás".  Dr. Bubó parancssori argumentumként kapja meg, hogy hány várakozó páciens van a rendelőben. Igazságosan elosztja őket, és csővezetéken elküldi Ursulának is, Csőrmesternek is, hogy hány oltást kell végezniük. Páratlan várakozó esetén, mindíg Csőrmester kapja az egyel több pácienst. Ursula is, Csőrmester is kiolvassa a csővezetékből a kapott oltásra várók számát, amit nyugtázásként a képernyőre ír, majd ezután befejezik tevékenységüket. Miután Dr Bubó bevárta, hogy az asszisztencia elment(befejezte tevékenységét), Ő is befejezi a tevékenységet.

2. Miután a két asszisztens Ursula és Csőrmester megkapják csővezetéken az adatot, elkezdik az oltást. Mielőtt beoltanák a pácienst megvizsgálják nem lázas, beteg-e? 20% valószinűséggel betegek, így nem kaphatnak oltást. A nap végén így, miután képernyőre írta, hogy hány páciens érkezett hozzá, üzenetsoron visszaküldik Dr. Bubónak, hogy hányan voltak betegek és azt is, hogy így hányan kaptak valójában oltást, majd befejezik tevékenységüket. Dr Bubó ezeket az adatokat képernyőre írja, majd bezárja a rendelőt.

3. Miután az asszistensek üzenetsoron megírták, hogy hány beteg nem kapott és hány páciens kapott oltást, ezt pedig Dr Bubó a képernyőre írta, emellett erről Oroszlánnak jelentést, jegyzőkönyvet kell írni. Fájlba írja, hogy milyen napon a Dr. Bubó klinika az oltásra érkezettekből hányan nem kaptak és hányan kaptak oltást!

4. Nem csak Dr. Bubó klinikája írja jelentését ebbe a fájlba, ezért védje szemaforral Dr Bubó fájl írását!

## Fordítási utasítások

```
gcc -Wall -fsanitize=address -pthread -lrt main.c fradilib/*.c
```