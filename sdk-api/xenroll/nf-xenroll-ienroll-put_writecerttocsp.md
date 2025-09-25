# IEnroll::put_WriteCertToCSP

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WriteCertToCSP** property sets or retrieves a Boolean value that determines whether a certificate should be written to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

This property was first defined by the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

This property is typically used with smart cards, where the certificate is written to the smart card in addition to being written to the "MY" store.

The default value is **true**, which means that the Certificate Enrollment Control will try to write the certificate to the CSP but will not fail unless a hardware token error is encountered. If this value is **true**, but no smart card or other hardware-dependent CSP is installed, then hardware token errors will be ignored.

To explicitly force that the Certificate Enrollment Control not attempt to write to the CSP, set this value to false.

**WriteCertToCSP** affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)