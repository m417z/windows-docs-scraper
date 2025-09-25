# DHPUBKEY structure

## Description

The **DHPUBKEY** structure contains information specific to the particular Diffie-Hellman [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) contained in the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

## Members

### `magic`

This must always be set to DH1 (0x31484400) when used for [public key BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and to DH2 (0x32484400) when used for [private key BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

Notice that the hexadecimal values are simply an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) encoding of DH1 and DH2.

### `bitlen`

Number of bits in the prime modulus, P.

## Remarks

**DSSPUBKEY** is an alias for this structure.

## See also

[PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc)