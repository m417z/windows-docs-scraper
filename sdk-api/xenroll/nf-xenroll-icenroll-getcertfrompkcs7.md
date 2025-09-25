# ICEnroll::getCertFromPKCS7

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getCertFromPKCS7** method retrieves the certificate, contained in a PKCS #7 message, that was issued in response to a PKCS #10 certificate request. This method was first defined by the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This method retrieves the single certificate that was issued even though a PKCS #7 message may contain many certificates that specify the certification chain of authority that issued the certificate.

## Parameters

### `wszPKCS7` [in]

Specifies the PKCS #7 from which the issued certificate is being retrieved.

### `pbstrCert` [out]

A pointer to a **BSTR** variable to receive the issued certificate. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The string that contains the issued certificate.