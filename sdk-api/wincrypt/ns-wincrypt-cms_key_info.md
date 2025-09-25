# CMS_KEY_INFO structure

## Description

The **CMS_KEY_INFO** structure is not used.

## Members

### `dwVersion`

The size, in bytes, of this structure.

### `Algid`

One of the [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) values that identifies the algorithm for the key to be converted.

### `pbOID`

The address of a buffer that contains additional public information. This member is optional and can be **NULL** if this is not needed.

### `cbOID`

The size, in bytes, of the **pbOID** buffer. This member should be zero if **pbOID** is not used.