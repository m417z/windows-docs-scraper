# PROV_ENUMALGS_EX structure

## Description

The **PROV_ENUMALGS_EX** structure is used with the [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function when the **PP_ENUMALGS_EX** parameter is retrieved to contain information about an algorithm supported by a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Members

### `aiAlgid`

One of the [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) values that identifies the algorithm.

### `dwDefaultLen`

The default [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), in bits, of the algorithm.

### `dwMinLen`

The minimum [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), in bits, of the algorithm.

### `dwMaxLen`

The maximum [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), in bits, of the algorithm.

### `dwProtocols`

Zero or a combination of one or more of the [Protocol Flags](https://learn.microsoft.com/windows/desktop/SecCrypto/protocol-flags) values that identifies the protocols supported by the algorithm.

### `dwNameLen`

The length, in **CHAR**s, of the **szName** string. This length includes the terminating null character.

### `szName`

A null-terminated ANSI string that contains the name of the algorithm.

### `dwLongNameLen`

The length, in **CHAR**s, of the **szLongName** string. This length includes the terminating null character.

### `szLongName`

A null-terminated ANSI string that contains the long name of the algorithm.