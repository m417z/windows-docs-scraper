# DHPRIVKEY_VER3 structure

## Description

The **DHPRIVKEY_VER3** structure contains information specific to the particular [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) contained in the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

## Members

### `magic`

This must always be set to 0x34484400, the [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) encoding of "DH4".

### `bitlenP`

Number of bits in the DH key BLOB's prime, P.

### `bitlenQ`

Number of bits in the DH key BLOB's prime, Q. If Q is not available then this value should be 0.

### `bitlenJ`

Number of bits in the DH key BLOB's prime, J. If J is not in the BLOB, then this value should be 0.

### `bitlenX`

Number of bits in the DH key BLOB private exponent, X.

### `DSSSeed`

Seed structure holding the seed and counter values used to generate the primes Q and P. If values in the [DSSSEED](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-dssseed) structure are not available, then the counter element of the structure should be 0xFFFFFFFF.

## Remarks

**DSSPRIVKEY_VER3** is an alias for this structure.

## See also

[BLOBHEADER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc)

[DSSSEED](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-dssseed)