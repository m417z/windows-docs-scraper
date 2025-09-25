# BCRYPT_DH_KEY_BLOB structure

## Description

The **BCRYPT_DH_KEY_BLOB** structure is used as a header for a Diffie-Hellman [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) in memory.

## Members

### `dwMagic`

Determines the type of key this structure represents. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_DH_PUBLIC_MAGIC**<br><br>0x42504844 | The structure represents a Diffie-Hellman public key. |
| **BCRYPT_DH_PRIVATE_MAGIC**<br><br>0x56504844 | The structure represents a Diffie-Hellman private key. |

### `cbKey`

The length, in bytes, of the key.

## Remarks

This structure is used as a header for a larger buffer. A Diffie-Hellman [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_DH_PUBLIC_BLOB) has the following format in contiguous memory. The Modulus, Generator, and Public numbers are in big-endian format.

``` syntax

BCRYPT_DH_KEY_BLOB
Modulus[cbKey] // Big-endian.
Generator[cbKey] // Big-endian.
Public[cbKey] // Big-endian.

```

A Diffie-Hellman [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_DH_PRIVATE_BLOB) has the following format in contiguous memory. The Modulus, Generator, Public, and PrivateExponent numbers are in big-endian format.

``` syntax

BCRYPT_DH_KEY_BLOB
Modulus[cbKey] // Big-endian.
Generator[cbKey] // Big-endian.
Public[cbKey] // Big-endian.
PrivateExponent[cbKey] // Big-endian.

```

## See also

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkey)