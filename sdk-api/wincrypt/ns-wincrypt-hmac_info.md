# HMAC_INFO structure

## Description

The **HMAC_INFO** structure specifies the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) algorithm and the inner and outer strings that are to be used to calculate the [HMAC](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) hash.

## Members

### `HashAlgid`

Specifies the hash algorithm to be used.

### `pbInnerString`

A pointer to the inner string to be used in the HMAC calculation. The default inner string is defined as the byte 0x36 repeated 64 times.

### `cbInnerString`

The count of bytes in **pbInnerString**. The CSP uses the default inner string if **cbInnerString** is equal to zero.

### `pbOuterString`

A pointer to the outer string to be used in the HMAC calculation. The default outer string is defined as the byte 0x5C repeated 64 times.

### `cbOuterString`

The count of bytes in **pbOuterString**. The CSP uses the default outer string if **cbOuterString** is equal to zero.

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)

[CryptSetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsethashparam)