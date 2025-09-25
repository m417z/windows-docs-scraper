# AlgorithmType enumeration

## Description

The **AlgorithmType** enumeration type specifies the intended purpose of a [cryptographic algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) supported by a cryptographic provider. Algorithms are typically classified by use into the following general categories:

* Signing
* Hashing
* Asymmetric encryption
* Symmetric encryption
* Key exchange

This enumeration is used in the [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) interface.

## Constants

### `XCN_BCRYPT_UNKNOWN_INTERFACE:0`

The algorithm type is not defined.

### `XCN_BCRYPT_CIPHER_INTERFACE:0x1`

The algorithm is used for symmetric encryption. This includes the [RC2](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), [RC4](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), [Data Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DES), 3DED, and [AES](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) algorithms.

### `XCN_BCRYPT_HASH_INTERFACE:0x2`

The algorithm is used for hashing. This includes the [MD2](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly), [MD4](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly), SHA1, SHA256, SHA384, SHA512 MAC, and [Hash-Based Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) (HMAC) hash algorithms.

### `XCN_BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE:0x3`

The algorithm is used for [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) encryption. This includes RSA.

### `XCN_BCRYPT_SIGNATURE_INTERFACE:0x5`

The algorithm is used for signing. This includes the [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) algorithm, [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA), and ECDSA algorithm.

### `XCN_BCRYPT_SECRET_AGREEMENT_INTERFACE:0x4`

The algorithm is used for key exchange. This includes the [Diffie-Hellman algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) and ECDH algorithm.

### `XCN_BCRYPT_RNG_INTERFACE:0x6`

The algorithm is used to generate a random number.

### `XCN_BCRYPT_KEY_DERIVATION_INTERFACE:0x7`

## See also

[AlgorithmOperationFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-algorithmoperationflags)

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)