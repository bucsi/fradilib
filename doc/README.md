![FradiLib](../header.png)
# `fradilib`
## Szignál
### Metódusok
#### `szignalkuldes(pid_t kinek, int mit)`
Wrapper a `kill()` függvény köré, `kinek` küld egy `mit` jelzést.
#### `void handler(int sign)`
Példa jelzéskezelő függvény, kiírja, hogy melyik process milyen kódú jelzést kapott.
#### `int numberSignal(int signal)`
Példa jelzéskezelő függvény, egész számok jelzésen keresztüli fogadását teszi lehetővé.
#### `void numOverSignal(int signal)`
A `numberSignal` kibővítése a mintafeladat megoldására.
### Használat
```c
//* közös programrész
signal(SIGUSR1, handler) // Linuxon 10-es kódú jelzés elkapása

for(int i=0; i<5; i++){
    signal(SIGRTMIN+i, numberSignal)
    // SIGRTMIN..SIGRTMIN+4 közötti jelzések elkapása, ezzel 0..4 közötti integert tud egy processnek a jelzés átadni
}
```

``` c
//gyerek folyamat
szignalkuldes(getppid(), SIGUSR1);
```

``` c
//szülő folyamat
pid_t gyerek = fork()
...
szignalkuldes(gyerek, SIGRTMIN+3); //3-mat küld a gyereknek jelzésen keresztül
```

## Cső
> Jelenleg fejlesztés alatt!

A `csobe_string` és `csobol_string` függvények használata ajánlott, ha a feladat vagy algoritmus nem igényel mást. Életszerű maximum méretig (1024 byte) tetszőleges hosszú szövegekre működik.

A `csobe_adat` és `csobol_adat` függvények egyelőre csak wrapperek a `read()` és `write()` köré, hogy ne kelljen emlékezni a szükséges paraméterek sorrendjére, hasonlóan a [`szignalkuldes` függvényhez](#szignalkuldespid_t-kinek-int-mit).