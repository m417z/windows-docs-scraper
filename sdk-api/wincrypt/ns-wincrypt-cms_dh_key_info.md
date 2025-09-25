# CMS_DH_KEY_INFO structure

## Description

The **CMS_DH_KEY_INFO** structure is used with the **KP_CMS_DH_KEY_INFO** parameter in the [CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) function to contain [Diffie-Hellman](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) key information.

## Members

### `dwVersion`

The size, in bytes, of this structure.

### `Algid`

One of the [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) values that identifies the algorithm for the key to be converted.

### `pszContentEncObjId`

The address of a null-terminated ANSI string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the content encryption algorithm.

### `PubInfo`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains additional public information. This member is optional and the **cbData** member of this structure can be zero if this is not needed.

### `pReserved`

Reserved for future use and must be **NULL**.

## See also

[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam)