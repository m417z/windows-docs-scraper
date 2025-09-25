## Description

The **BCRYPT_ECCKEY_BLOB** structure is used as a header for an elliptic curve [public key](https://learn.microsoft.com/windows/desktop/secgloss/p-gly) or [private key](https://learn.microsoft.com/windows/desktop/secgloss/p-gly) [BLOB](https://learn.microsoft.com/windows/desktop/secgloss/b-gly) in memory.

## Members

### `dwMagic`

Specifies the type of key this BLOB represents. The possible values for this member depend on the type of BLOB this structure represents. The following keys use the NIST 256-bit prime curve defined in FIPS 186-2.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ECDH_PUBLIC_P256_MAGIC** | The key is a 256 bit elliptic curve Diffie-Hellman public key. |
| **BCRYPT_ECDH_PRIVATE_P256_MAGIC** | The key is a 256 bit elliptic curve Diffie-Hellman private key. |
| **BCRYPT_ECDH_PUBLIC_P384_MAGIC** | The key is a 384 bit elliptic curve Diffie-Hellman public key. |
| **BCRYPT_ECDH_PRIVATE_P384_MAGIC** | The key is a 384 bit elliptic curve Diffie-Hellman private key. |
| **BCRYPT_ECDH_PUBLIC_P521_MAGIC** | The key is a 521 bit elliptic curve Diffie-Hellman public key. |
| **BCRYPT_ECDH_PRIVATE_P521_MAGIC** | The key is a 521 bit elliptic curve Diffie-Hellman private key. |
| **BCRYPT_ECDSA_PUBLIC_P256_MAGIC** | The key is a 256 bit elliptic curve DSA public key. |
| **BCRYPT_ECDSA_PRIVATE_P256_MAGIC** | The key is a 256 bit elliptic curve DSA private key. |
| **BCRYPT_ECDSA_PUBLIC_P384_MAGIC** | The key is a 384 bit elliptic curve DSA public key. |
| **BCRYPT_ECDSA_PRIVATE_P384_MAGIC** | The key is a 384 bit elliptic curve DSA private key. |
| **BCRYPT_ECDSA_PUBLIC_P521_MAGIC** | The key is a 521 bit elliptic curve DSA public key. |
| **BCRYPT_ECDSA_PRIVATE_P521_MAGIC** | The key is a 521 bit elliptic curve DSA private key. |

### `cbKey`

The length, in bytes, of the key.

## Remarks

This structure is used as a header for a larger buffer. An elliptic curve [public key BLOB](https://learn.microsoft.com/windows/win32/secgloss/p-gly) (BCRYPT_ECCPUBLIC_BLOB) has the following format in contiguous memory. The X and Y coordinates are unsigned integers encoded in big-endian format.

```syntax
BCRYPT_ECCKEY_BLOB
BYTE X[cbKey] // Big-endian.
BYTE Y[cbKey] // Big-endian.
```

An elliptic curve [private key BLOB](https://learn.microsoft.com/windows/desktop/secgloss/p-gly) (BCRYPT_ECCPRIVATE_BLOB) has the following format in contiguous memory. The X and Y coordinates and d value are unsigned integers encoded in big-endian format.

```syntax
BCRYPT_ECCKEY_BLOB
BYTE X[cbKey] // Big-endian.
BYTE Y[cbKey] // Big-endian.
BYTE d[cbKey] // Big-endian.
```

## See also

[BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_key_blob)

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkey)