# Libakrypt: abstract

Libakrypt is a free and open source library (software crypto module) distributed under
the MIT License. This library written in C99 and provides some interfaces for
key management, data encryption, integrity checking, signing messages and verifying
of digital signatures. The main goal of Libakrypt is implementation a lot of Russian
crypto mechanisms, decribed by national standards and methodological recomendations
in accordance with R 1323565.1.012-2017
"Basic principles of creating and modernization for crypto modules".

We have implementation of:

 1. GOST R 34.12-2015 block ciphers "Magma" & "Kuznechik" with 64 bit and 128 bit block sizes respectively;
 2. GOST R 34.13-2015 modes for block ciphers including CMAC algorithm;
<!---
 3. ACPKM encryption mode described by R 1323565.1.017-2018;
 4. New russian AEAD mode (MGM, Multilinear Galois mode) for authenticated encryption;
--->
 5. GOST R 34.11-2012 hash functions from Streebog family;
 6. Montgomery arithmetic for prime fileds;
 7. Group operations on elliptic curves in short Weierstrass form for all elliptic curves
    described by R 50.1.114-2016;
 8. GOST R 34.10-2012 digital signature generation and verification algorithms;
 9. R 50.1.113-2016 crypto algorithms such as HMAC;
10. National variant of password-based key derivation function (PBKDF2) described by R 50.1.111-2016;
11. A some set of pseudo random generators for various operation systems including R 1323565.1.006-2017 mechanism.

Library can be used successfully under `Linux`, `Windows`, `FreeBSD` and `MacOS` operation systems.
Also we have positive runs on mobile devices under [Sailfish OS](https://sailfishos.org/).

We support various architecture such as `x86`, `x64`, `arm32v7`, `arm32v7eb`, `mips32r2` and `mips64r2`.


## Compilation

The library can be compiled with many compilers,
such as `gcc`, `clang`, `Microsoft Visual C`, `TinyCC` and `icc`.
You can get the last version of source codes from github.com

    git clone https://github.com/axelkenzo/libakrypt-0.x

The build system for libakrypt is [cmake](https://cmake.org/).

### Unix
On Unix platforms you can compile & build library with following commands

    mkdir build
    cd build
    cmake -DCMAKE_C_FLAGS="-march=native" ../libakrypt-0.x
    make

If you want to compile and build a set of test programs you may run

    cmake -DLIBAKRYPT_INTERNAL_TESTS=ON ../libakrypt-0.x
    make && make test

### Windows
On Windows you may to install [phtreads library](https://sourceware.org/pthreads-win32/).
Installing of `pthreads` library is optional.

After you can run a Microsoft Visual 20XX Console and execute a following sequence

    mkdir build
    cd build
    cmake.exe -G "NMake Makefiles" -DCMAKE_C_FLAGS="-march=native" ../libakrypt-0.x
    nmake.exe

## Information

The full list of compile & build options and full documentation you can find
in `doc` directory or libakrypt-doc-0.x.pdf (in russian).

## Attention

Since this version still under development we don't recomended to use it
in real security applications.
