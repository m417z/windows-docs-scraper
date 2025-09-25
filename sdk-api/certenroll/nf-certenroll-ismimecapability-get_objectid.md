# ISmimeCapability::get_ObjectId

## Description

The **ObjectId** property retrieves the object identifier (OID) of the symmetric encryption algorithm.

This property is read-only.

## Parameters

## Remarks

Call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ismimecapability-initialize) method to specify the **ObjectId** property. The following encryption OIDs are currently supported:

* XCN_OID_NIST_AES128_CBC (2.16.840.1.101.3.4.1.2)
* XCN_OID_NIST_AES192_CBC (2.16.840.1.101.3.4.1.22)
* XCN_OID_NIST_AES256_CBC (2.16.840.1.101.3.4.1.42)
* XCN_OID_NIST_AES128_WRAP (2.16.840.1.101.3.4.1.5)
* XCN_OID_NIST_AES192_WRAP (2.16.840.1.101.3.4.1.25)
* XCN_OID_NIST_AES256_WRAP (2.16.840.1.101.3.4.1.45)
* XCN_OID_OIWSEC_desCBC (1.3.14.3.2.7)
* XCN_OID_RSA_DES_EDE3_CBC (1.2.840.113549.3.7)
* XCN_OID_RSA_RC2CBC (1.2.840.113549.3.2)
* XCN_OID_RSA_RC4 (1.2.840.113549.3.4)
* XCN_OID_RSA_SMIMEalgCMS3DESwrap (1.2.840.113549.1.9.16.3.6)
* XCN_OID_RSA_SMIMEalgCMSRC2wrap (1.2.840.113549.1.9.16.3.7)

## See also

[ISmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapabilities)

[ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability)

[IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities)