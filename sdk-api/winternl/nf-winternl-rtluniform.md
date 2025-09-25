# RtlUniform function

## Description

Generates a uniform random number using D.H. Lehmer's 1948 algorithm.

## Parameters

### `Seed` [in, out]

The seed value.

## Return value

 The function returns a random number uniformly distributed over [0..MAXLONG].

## Remarks

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## See also

[CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom)