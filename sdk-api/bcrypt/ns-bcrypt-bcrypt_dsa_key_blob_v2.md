# BCRYPT_DSA_KEY_BLOB_V2 structure

## Description

The **BCRYPT_DSA_KEY_BLOB_V2** structure is used as a header for a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) in memory.

## Members

### `dwMagic`

Determines the type of key this structure represents. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_DSA_PUBLIC_MAGIC_V2**<br><br>0x32425044 | The structure represents a DSA public key. |
| **BCRYPT_DSA_PRIVATE_MAGIC_V2**<br><br>0x32565044 | The structure represents a DSA private key. |

### `cbKey`

The length, in bytes, of the key.

### `hashAlgorithm`

A [HASHALGORITHM_ENUM](https://learn.microsoft.com/windows/desktop/api/bcrypt/ne-bcrypt-hashalgorithm_enum) enumeration value that specifies the hashing algorithm to use.

### `standardVersion`

A [DSAFIPSVERSION_ENUM](https://learn.microsoft.com/windows/desktop/api/bcrypt/ne-bcrypt-dsafipsversion_enum) enumeration value that specifies the Federal Information Processing Standard (FIPS) to apply.

### `cbSeedLength`

Length of the seed used to generate the prime number *q* in bytes.

### `cbGroupSize`

Size of the prime number *q* in bytes. Currently, when the key exceeds 1024 bits in length, *q* is 32 bytes long.

### `Count`

The number of iterations performed to generate the prime number *q* from the seed. For more information, see NIST standard FIPS186-3.

## Remarks

The structure applies to DSA keys that exceed 1024 bits in length but are less than or equal to 3072 bits.

This structure is used as a header for a larger buffer. A DSA [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_DSA_PUBLIC_BLOB) has the following format in contiguous memory. The Seed, q, Modulus, Generator, and Public numbers are in big-endian format.

``` syntax

BCRYPT_DSA_KEY_BLOB_V2
Seed[cbSeedLength]  // Big-endian.
q[cbGroupSize]      // Big-endian.
Modulus[cbKey]      // Big-endian.
Generator[cbKey]    // Big-endian.
Public[cbKey]       // Big-endian.

```

A DSA [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_DSA_PRIVATE_BLOB) has the following format in contiguous memory. The Seed, q, Modulus, Generator, Public, and PrivateExponent numbers are in big-endian format.

``` syntax

BCRYPT_DSA_KEY_BLOB_V2
Seed[cbSeedLength]              // Big-endian.
q[cbGroupSize]                  // Big-endian.
Modulus[cbKey]                  // Big-endian.
Generator[cbKey]                // Big-endian.
Public[cbKey]                   // Big-endian.
PrivateExponent[cbGroupSize]    // Big-endian.

```

## See also

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkeypair)