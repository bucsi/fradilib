
![FradiLib](header.png)
# `fradilib`

Segéd-headerek az ELTE IK operációs rendszerek tárgyához.

**FIGYELEM!**
A projekt fejlesztés alatt áll, bármikor készülhet dokumentálatlan, visszafelé nem kompatibilis módosítás. Ha ezzel készülsz valamelyik számonkérésre, érdemes egy lokális másolatot használni.

A tárgy előadójának tájékoztatása szerint mivel a projekt nyílt forráskódú, és az interneten szabadon elérhető, plágiumgyanú nélkül használható a számonkéréseken.

## to do
- [ ] Memory leak a `cso_letrehoz` miatt
<summary>
<details>

```
==908616==ERROR: LeakSanitizer: detected memory leaks
==908615==ERROR: LeakSanitizer: detected memory leaks


Direct leak of 8 byte(s) in 1 object(s) allocated from:
Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f96f6e8e459 in __interceptor_malloc /build/gcc/src/gcc/libsanitizer/asan/asan_malloc_linux.cpp:145
    #0 0x7f96f6e8e459 in __interceptor_malloc /build/gcc/src/gcc/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x55f175280c77 in cso_letrehoz (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x2c77)
    #1 0x55f175280c77 in cso_letrehoz (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x2c77)
    #2 0x55f17528066b in main (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x266b)
    #2 0x55f17528066b in main (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x266b)
    #3 0x7f96f6c0e151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)
    #3 0x7f96f6c0e151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)


Direct leak of 8 byte(s) in 1 object(s) allocated from:
Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f96f6e8e459 in __interceptor_malloc /build/gcc/src/gcc/libsanitizer/asan/asan_malloc_linux.cpp:145
    #0 0x7f96f6e8e459 in __interceptor_malloc /build/gcc/src/gcc/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x55f175280c77 in cso_letrehoz (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x2c77)
    #1 0x55f175280c77 in cso_letrehoz (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x2c77)
    #2 0x55f17528065a in main (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x265a)
    #2 0x55f17528065a in main (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x265a)
    #3 0x7f96f6c0e151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)
    #3 0x7f96f6c0e151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)


SUMMARY: AddressSanitizer: 16 byte(s) leaked in 2 allocation(s).
SUMMARY: AddressSanitizer: 16 byte(s) leaked in 2 allocation(s).

=================================================================
==908614==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f96f6e8e459 in __interceptor_malloc /build/gcc/src/gcc/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x55f175280c77 in cso_letrehoz (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x2c77)
    #2 0x55f17528066b in main (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x266b)
    #3 0x7f96f6c0e151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f96f6e8e459 in __interceptor_malloc /build/gcc/src/gcc/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x55f175280c77 in cso_letrehoz (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x2c77)
    #2 0x55f17528065a in main (/media/data/szerver/bucs/ELTE/IK/opre/opre-segedanyag/fradilib/src/a.out+0x265a)
    #3 0x7f96f6c0e151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)

SUMMARY: AddressSanitizer: 16 byte(s) leaked in 2 allocation(s).```
```

</summary>

- [ ] Színes kimenet a `coloredoutput.c`-vel
- [ ] Dokumentáció
- [ ] További ZH-k megoldása mintaként
