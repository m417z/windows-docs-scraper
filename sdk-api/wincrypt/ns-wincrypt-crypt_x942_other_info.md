# CRYPT_X942_OTHER_INFO structure

## Description

The **CRYPT_X942_OTHER_INFO** structure contains additional key generation information.

## Members

### `pszContentEncryptionObjId`

OID of the content encryption algorithm.

### `rgbCounter`

Array of BYTES of length **CRYPT_X942_COUNTER_BYTE_LENGTH**. The value is stored in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) order.

### `rgbKeyLength`

Array of BYTES of length **CRYPT_X942_KEY_LENGTH_BYTE_LENGTH**. The value is stored in little-endian order.

### `PubInfo`

Optional [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) for additional information.