# ICspAlgorithm::get_MaxLength

## Description

The **MaxLength** property retrieves the maximum permitted length for a key. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The [DefaultLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_defaultlength), [IncrementLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_incrementlength), **MaxLength**, and [MinLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_minlength) properties can vary by algorithm and provider. The following table lists a few example maximum, minimum and default key sizes.

| Algorithm OID | Cryptographic provider | Key length (bits) |
| --- | --- | --- |
| XCN_OID_OIWSEC_desCBC<br><br>(1.3.14.3.2.7) | Microsoft Base DSS and Diffie-Hellman Cryptographic Provider<br><br>Microsoft Enhanced Cryptographic Provider v1.0<br><br>Microsoft DH Schannel Cryptographic Provider<br><br>Microsoft Enhanced RSA and AES Cryptographic Provider | Minimum: 56<br><br>Maximum: 56<br><br>Default: 56 |
| XCN_OID_RSA_DES_EDE3_CBC<br><br>(1.2.840.113549.3.7) | Microsoft Base DSS and Diffie-Hellman Cryptographic Provider<br><br>Microsoft Enhanced Cryptographic Provider v1.0<br><br>Microsoft DH Schannel Cryptographic Provider<br><br>Microsoft Enhanced RSA and AES Cryptographic Provider<br><br>Microsoft Exchange Cryptographic Provider v1.0 | Minimum: 168<br><br>Maximum: 168<br><br>Default: 168 |
| XCN_OID_RSA_RSA<br><br>(1.2.840.113549.1.1.1) | Microsoft Enhanced Cryptographic Provider v1.0<br><br>Microsoft Enhanced RSA and AES Cryptographic Provider<br><br>Microsoft RSA Schannel Cryptographic Provider<br><br>Microsoft Strong Cryptographic Provider | Minimum: 384<br><br>Maximum: 16,384<br><br>Default: 1,024<br><br>Increment: 8 |
| XCN_OID_X957_DSA<br><br>(1.2.840.10040.4.1) | Microsoft Base DSS and Diffie-Hellman Cryptographic Provider<br><br>Microsoft Base DSS Cryptographic Provider<br><br>Microsoft DH Schannel Cryptographic Provider<br><br>Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider | Minimum: 512<br><br>Maximum: 1,024<br><br>Default: 1,024<br><br>Increment: 64 |

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)

[MinLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_minlength)