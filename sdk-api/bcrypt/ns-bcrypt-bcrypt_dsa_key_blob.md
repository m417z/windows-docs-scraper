# BCRYPT_DSA_KEY_BLOB structure

## Description

The **BCRYPT_DSA_KEY_BLOB** structure is used as a header for a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) in memory.

## Members

### `dwMagic`

Determines the type of key this structure represents. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_DSA_PUBLIC_MAGIC**<br><br>0x42505344 | The structure represents a DSA public key. |
| **BCRYPT_DSA_PRIVATE_MAGIC**<br><br>0x56505344 | The structure represents a DSA private key. |

### `cbKey`

The length, in bytes, of the key.

### `Count`

The number of iterations, in big-endian format, used to generate *q*.

### `Seed`

The seed value, in big-endian format, used to generate *q*.

### `q`

The 160-bit prime factor, in big-endian format.

## Remarks

The structure applies to DSA keys that equal or exceed 512 bits in length but are less than or equal to 1024 bits.

This structure is used as a header for a larger buffer. A DSA [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_DSA_PUBLIC_BLOB) has the following format in contiguous memory. The Modulus, Generator, and Public numbers are in big-endian format.

``` syntax

BCRYPT_DSA_KEY_BLOB
Modulus[cbKey]    // Big-endian.
Generator[cbKey]  // Big-endian.
Public[cbKey]     // Big-endian.

```

A DSA [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_DSA_PRIVATE_BLOB) has the following format in contiguous memory. The Modulus, Generator, Public, and PrivateExponent numbers are in big-endian format.

``` syntax

BCRYPT_DSA_KEY_BLOB
Modulus[cbKey]        // Big-endian.
Generator[cbKey]      // Big-endian.
Public[cbKey]         // Big-endian.
PrivateExponent[20]   // Big-endian.

```

## See also

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkeypair)