# ISmimeCapability::get_BitCount

## Description

The **BitCount** property retrieves the length, in bits, of the encryption key.

This property is read-only.

## Parameters

## Remarks

Call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ismimecapability-initialize) method to specify the **BitCount** property. The following symmetric encryption algorithms and key lengths are supported by the Certificate Enrollment API.

| OID | Key Length |
| --- | --- |
| XCN_OID_OIWSEC_desCBC1.3.14.3.2.7 | 56 |
| XCN_OID_RSA_DES_EDE3_CBC1.2.840.113549.3.7 | 168 |
| XCN_OID_RSA_RC2CBC1.2.840.113549.3.2 | 40 to 128 |
| XCN_OID_RSA_RC41.2.840.113549.3.4 | 40 to 128 |
| XCN_OID_RSA_SMIMEalgCMS3DESwrap1.2.840.113549.1.9.16.3.6 | 168 |
| XCN_OID_RSA_SMIMEalgCMSRC2wrap1.2.840.113549.1.9.16.3.7 | 128 |
| XCN_OID_NIST_AES128_CBC2.16.840.1.101.3.4.1.2 | 128 |
| XCN_OID_NIST_AES192_CBC2.16.840.1.101.3.4.1.22 | 192 |
| XCN_OID_NIST_AES256_CBC2.16.840.1.101.3.4.1.42 | 256 |
| XCN_OID_NIST_AES128_WRAP2.16.840.1.101.3.4.1.5 | 128 |
| XCN_OID_NIST_AES192_WRAP2.16.840.1.101.3.4.1.25 | 192 |
| XCN_OID_NIST_AES256_WRAP2.16.840.1.101.3.4.1.45 | 256 |

## See also

[ISmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapabilities)

[ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability)

[IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities)