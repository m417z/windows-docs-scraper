# AlgorithmOperationFlags enumeration

## Description

The **AlgorithmOperationFlags** enumeration type specifies the operations that an algorithm can perform. This enumeration is used in the following interfaces to retrieve the operational capabilities of a cryptographic provider or status information based on those capabilities.

* [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)
* [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)
* [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)
* [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)

The binary format of the flags are as follows.

``` syntax
XCN_NCRYPT_NO_OPERATION                     = 00000000 00000000 00000000
XCN_NCRYPT_CIPHER_OPERATION                 = 00000000 00000000 00000001
XCN_NCRYPT_HASH_OPERATION                   = 00000000 00000000 00000010

XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION  = 00000000 00000000 00000100
XCN_NCRYPT_SECRET_AGREEMENT_OPERATION       = 00000000 00000000 00001000
XCN_NCRYPT_SIGNATURE_OPERATION              = 00000000 00000000 00010000
XCN_NCRYPT_ANY_ASYMMETRIC_OPERATION         = 00000000 00000000 00011100

XCN_NCRYPT_RNG_OPERATION                    = 00000000 00000000 00100000

XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION  = 00100000 00000000 00000000
XCN_NCRYPT_PREFER_NON_SIGNATURE_OPERATION   = 01000000 00000000 00000000
XCN_NCRYPT_EXACT_MATCH_OPERATION            = 10000000 00000000 00000000
XCN_NCRYPT_PREFERENCE_MASK_OPERATION        = 11100000 00000000 00000000

```

## Constants

### `XCN_NCRYPT_NO_OPERATION:0`

No operation is specified.

### `XCN_NCRYPT_CIPHER_OPERATION:0x1`

The algorithm can be used for [symmetric encryption](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This includes the [RC2](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), [RC4](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), [Data Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DES), 3DED, and [AES](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) algorithms.

### `XCN_NCRYPT_HASH_OPERATION:0x2`

The algorithm can be used for hashing. This includes the [MD2](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly), [MD4](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly), SHA1, SHA256, SHA384, SHA512 MAC, and [Hash-Based Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) (HMAC) [hashing algorithms](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

### `XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION:0x4`

The algorithm can be used for [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) encryption. This includes [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

### `XCN_NCRYPT_SECRET_AGREEMENT_OPERATION:0x8`

The algorithm can used for key exchange. This includes the [Diffie-Hellman algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) and ECDH algorithm.

### `XCN_NCRYPT_SIGNATURE_OPERATION:0x10`

The algorithm can be used for signing. This includes the RSA algorithm, [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA), and ECDSA algorithm.

### `XCN_NCRYPT_RNG_OPERATION:0x20`

The algorithm can be used to generate a random number.

### `XCN_NCRYPT_KEY_DERIVATION_OPERATION:0x40`

### `XCN_NCRYPT_ANY_ASYMMETRIC_OPERATION`

The algorithm can be used for public key encryption, key exchange, and signing. This is a bitwise-**OR** combination of the following constants:

* XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION
* XCN_NCRYPT_SECRET_AGREEMENT_OPERATION
* XCN_NCRYPT_SIGNATURE_OPERATION

### `XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION:0x200000`

Signature algorithms are preferred but not required. An encryption algorithm may be chosen instead. This is used when searching for [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) status information based on supported operational capability.

### `XCN_NCRYPT_PREFER_NON_SIGNATURE_OPERATION:0x400000`

An encryption algorithm (such as that identified by the **XCN_NCRYPT_ANY_ASYMMETRIC_OPERATION** or **XCN_NCRYPT_SECRET_AGREEMENT_OPERATION** flags) is preferred but not required. A signature algorithm may be chosen instead. This is used when searching for CSP status information based on supported operational capability.

### `XCN_NCRYPT_EXACT_MATCH_OPERATION:0x800000`

Only an algorithm that exactly matches the specified operations is selected.

### `XCN_NCRYPT_PREFERENCE_MASK_OPERATION:0xe00000`

Use to mask the algorithm operation preference.

## See also

[AlgorithmType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-algorithmtype)

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)