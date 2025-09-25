# ICspAlgorithm::get_DefaultLength

## Description

The **DefaultLength** property retrieves the default length of a key. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

You can use this property to retrieve the default size, in bits, of a key. The **DefaultLength**, [IncrementLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_incrementlength), [MaxLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_maxlength), and [MinLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_minlength) properties can vary by algorithm and provider. The following table lists a few algorithms for which multiple key sizes can be set. The list is not inclusive.

| Algorithm OID | Cryptographic provider | Key length (bits) |
| --- | --- | --- |
| XCN_OID_RSA_RSA(1.2.840.113549.1.1.1) | Microsoft Smart Card Key Storage Provider<br><br>Microsoft Base Smart Card Crypto Provider | Minimum: 1,024<br><br>Maximum: 4,096<br><br>Default: 1,024<br><br>Increment: 512 |
| XCN_OID_RSA_RSA(1.2.840.113549.1.1.1) | Microsoft Software Key Storage Provider<br><br>Microsoft Base Cryptographic Provider v1.0<br><br>Microsoft Enhanced Cryptographic Provider v1.0<br><br>Microsoft Enhanced RSA and AES Cryptographic Provider<br><br>Microsoft RSA Schannel Cryptographic Provider<br><br>Microsoft Strong Cryptographic Provider | Minimum: 384<br><br>Maximum: 16,384<br><br>Default: 1,024<br><br>Increment: 8 |
| XCN_OID_X957_DSA(1.2.840.10040.4.1) | Microsoft Software Key Storage Provider<br><br>Microsoft Base DSS and Diffie-Hellman Cryptographic Provider<br><br>Microsoft Base DSS Cryptographic Provider<br><br>Microsoft DH Schannel Cryptographic Provider<br><br>Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider | Minimum: 512<br><br>Maximum: 1,024<br><br>Default: 1,024<br><br>Increment: 64 |
| XCN_OID_ANSI_X942_DH(1.2.840.10046.2.1) | Diffie-Hellman key exchange algorithm. | Minimum: 512<br><br>Maximum: 1,024<br><br>Default: 1,024<br><br>Increment: 64 |
| XCN_OID_ANSI_X942_DH(1.2.840.10046.2.1) | Microsoft DH Schannel Cryptographic Provider<br><br>Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider | Minimum: 512<br><br>Maximum: 4,096<br><br>Default: 1,024<br><br>Increment: 64 |
| XCN_OID_RSA_RC2CBC(1.2.840.113549.3.2) | Microsoft Software Key Storage Provider<br><br>Microsoft Smart Card Key Storage Provider<br><br>Microsoft Base Smart Card Crypto Provider<br><br>Microsoft DH Schannel Cryptographic Provider<br><br>Microsoft Enhanced Cryptographic Provider v1.0<br><br>Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider<br><br>Microsoft Enhanced RSA and AES Cryptographic Provider<br><br>Microsoft RSA Schannel Cryptographic Provider<br><br>Microsoft Strong Cryptographic Provider | Minimum: 40<br><br>Maximum: 128<br><br>Default: 128<br><br>Increment: 8 |

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)

[IncrementLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_incrementlength)