# IEnroll::get_HashAlgorithmWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **HashAlgorithmWStr** property sets or retrieves only the signature [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) used to sign the PKCS #10 certification request.

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

This signature hashing algorithm is not to be confused with the hashing algorithm used to sign the certificate. The enrollment control currently supports any OID for hashing algorithms, plus the following display name values: SHA1 (the default), MD2, and MD5. When retrieving this property, the retrieved value is in OID format (that is, SHA1 appears as 1.3.14.3.2.29). When setting this property, the corresponding OID format can be used as an alternative to the text shown for the defined friendly values.

The Certificate Enrollment Control considers the value of the **HashAlgorithmWStr** property as a hint to the hashing algorithm to use for signing the PKCS #10 certification request. If the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) supports the algorithm specified in the **HashAlgorithmWStr** property, the algorithm will be used. Otherwise, the Certificate Enrollment Control will try to use SHA1. If SHA1 is not supported by the CSP, then MD5 will be tried. If neither SHA1 nor MD5 is supported, the Certificate Enrollment Control will try to use the first hashing algorithm returned from the CSP.

The **HashAlgorithmWStr** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)

If both the
[HashAlgID](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll2-get_hashalgid) and **HashAlgorithmWStr** properties are set, whichever is last updated will specify which hashing algorithm will be used to sign the PKCS #10 certification request.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)