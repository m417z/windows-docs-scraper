# RSAPUBKEY structure

## Description

The **RSAPUBKEY** structure contains information specific to the particular public key contained in the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

## Members

### `magic`

Set to RSA1 (0x31415352) for public keys and to RSA2 (0x32415352) for private keys.

**Note** The hexadecimal values are the [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) encoding of RSA1 and RSA2.

### `bitlen`

Number of bits in the modulus. In practice, this must always be a multiple of eight.

### `pubexp`

The public exponent.

## See also

[DSSPUBKEY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381982(v=vs.85))

[DSSSEED](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-dssseed)

[PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc)