# ICEnroll::put_WriteCertToCSP

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WriteCertToCSP** property sets or retrieves a Boolean value that determines whether a certificate should be written to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

This property was first defined by the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

This property is typically used with smart cards, where the certificate is written to the smart card in addition to being written to the "MY" store.

The default value is **true**, which means that the Certificate Enrollment Control will try to write the certificate to the CSP but will not fail unless a hardware token error is encountered. If this value is **true**, but no smart card or other hardware-dependent CSP is installed, then hardware token errors will be ignored.

To explicitly force that the Certificate Enrollment Control not attempt to write to the CSP, set this value to false.

**WriteCertToCSP** affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

#### Examples

```cpp
BOOL     bWriteCSP;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the WriteCertToCSP value
hr = pEnroll->get_WriteCertToCSP( &bWriteCSP );
if (FAILED( hr ))
    printf("Failed get_WriteCertToCSP - %x\n", hr );
else
    printf( "WriteCertToCSP: %d\n", bWriteCSP );

// set the WriteCertToCSP value
hr = pEnroll->put_WriteCertToCSP( TRUE );
if (FAILED( hr ))
    printf("Failed put_WriteCertToCSP - %x\n", hr );
else
    printf( "WriteCertToCSP set to TRUE\n" );
```