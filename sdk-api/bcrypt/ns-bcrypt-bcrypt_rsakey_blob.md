# BCRYPT_RSAKEY_BLOB structure

## Description

The **BCRYPT_RSAKEY_BLOB** structure is used as a header for an RSA [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) in memory.

## Members

### `Magic`

Specifies the type of RSA key this BLOB represents. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_RSAPUBLIC_MAGIC** | The key is an RSA public key. |
| **BCRYPT_RSAPRIVATE_MAGIC** | The key is an RSA private key. |
| **BCRYPT_RSAFULLPRIVATE_MAGIC** | The key is a full RSA private key. |

### `BitLength`

The size, in bits, of the key.

### `cbPublicExp`

The size, in bytes, of the exponent of the key. As of Windows 10 version 1903, public exponents larger than (2^64 - 1) are no longer supported.

### `cbModulus`

The size, in bytes, of the modulus of the key.

### `cbPrime1`

The size, in bytes, of the first prime number of the key. This is only used for private key BLOBs.

### `cbPrime2`

The size, in bytes, of the second prime number of the key. This is only used for private key BLOBs.

## Remarks

This structure is used as a header for a larger buffer. An RSA [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_RSAPUBLIC_BLOB) has the following format in contiguous memory. All of the numbers following the structure are in big-endian format.

``` syntax

BCRYPT_RSAKEY_BLOB
PublicExponent[cbPublicExp] // Big-endian.
Modulus[cbModulus] // Big-endian.

```

An RSA [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (BCRYPT_RSAPRIVATE_BLOB) has the following format in contiguous memory. All of the numbers following the structure are in big-endian format.

``` syntax

BCRYPT_RSAKEY_BLOB
PublicExponent[cbPublicExp] // Big-endian.
Modulus[cbModulus] // Big-endian.
Prime1[cbPrime1] // Big-endian.
Prime2[cbPrime2] // Big-endian.

```

A full RSA private key BLOB (BCRYPT_RSAFULLPRIVATE_BLOB) has the following format in contiguous memory. All of the numbers following the structure are in big-endian format.

Note that in different versions of Windows, the value that PrivateExponent takes from a call of [BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey) may be different as there are several mathematically equivalent representations of the PrivateExponent in cbModulus bytes. Notably, in some versions the PrivateExponent will be exported modulo (Prime1 - 1) \* (Prime2 - 1), and in others it will be exported modulo LeastCommonMultiple(Prime1 - 1, Prime2 - 1).

``` syntax

BCRYPT_RSAKEY_BLOB
PublicExponent[cbPublicExp] // Big-endian.
Modulus[cbModulus] // Big-endian.
Prime1[cbPrime1] // Big-endian.
Prime2[cbPrime2] // Big-endian.
Exponent1[cbPrime1] // Big-endian.
Exponent2[cbPrime2] // Big-endian.
Coefficient[cbPrime1] // Big-endian.
PrivateExponent[cbModulus] // Big-endian.

```

## See also

[BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_key_blob)

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkey)