# KERB_CRYPTO_KEY structure

## Description

The **KERB_CRYPTO_KEY** structure contains information about a [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) cryptographic [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Members

### `KeyType`

Indicates the type of [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) stored in the structure. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **KERB_ETYPE_DES_CBC_CRC** | Use [DES](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) encryption in [cipher-block-chaining](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) mode with a CRC-32 checksum. |
| **KERB_ETYPE_DES_CBC_MD4** | Use DES encryption in cipher-block-chaining mode with a MD4 checksum. |
| **KERB_ETYPE_DES_CBC_MD5** | Use DES encryption in cipher-block-chaining mode with a MD5 checksum. |
| **KERB_ETYPE_NULL** | Use no encryption. |
| **KERB_ETYPE_RC4_HMAC_NT** | Use the RC4 [stream cipher](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) with a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly)-based [Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MAC). |
| **KERB_ETYPE_RC4_MD4** | Use the RC4 stream cipher with the MD4 hash function. |

Values greater than 127 are reserved for local values and may change without notice.

### `Length`

Specifies the length, in bytes, of the cryptographic [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `Value`

Contains the cryptographic session key.