# PROV_ENUMALGS structure

## Description

The **PROV_ENUMALGS** structure is used with the [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function when the **PP_ENUMALGS** parameter is retrieved to contain information about an algorithm supported by a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Members

### `aiAlgid`

One of the [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) values that identifies the algorithm.

### `dwBitLen`

The default [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), in bits, of the algorithm.

### `dwNameLen`

The length, in **CHAR**s, of the **szName** string. This length includes the terminating null character.

### `szName`

A null-terminated ANSI string that contains the name of the algorithm.