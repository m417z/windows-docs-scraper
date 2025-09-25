# DHPUBKEY_VER3 structure

## Description

The **DHPUBKEY_VER3** structure contains information specific to the particular [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) contained in the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

## Members

### `magic`

This must always be set to 0x33484400, the [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) encoding of "DH3".

### `bitlenP`

Number of bits in the DH key BLOB's prime, P.

### `bitlenQ`

Number of bits in the DH key BLOB's prime, Q. If Q is not available, then this value should be 0.

### `bitlenJ`

Number of bits in the DH key BLOB's prime, J. If J is not in the BLOB, then this value should be 0.

### `DSSSeed`

Seed structure holding the seed and counter values used to generate the primes Q and P. If values in the [DSSSEED](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-dssseed) structure are not available, then the counter element of the structure should be 0xFFFFFFFF.

## Remarks

**DSSPUBKEY_VER3** is an alias for this structure.

## See also

[BLOBHEADER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc)

[DSSSEED](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-dssseed)