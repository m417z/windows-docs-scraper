# ICEnroll4::InstallPKCS7Ex

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **InstallPKCS7Ex** method processes a certificate or chain of certificates, placing them into the appropriate [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The **InstallPKCS7Ex** method is the same as
[InstallPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-installpkcs7) except that it returns the number of certificates actually installed in local stores. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `PKCS7` [in]

A string that contains a certificate or chain of certificates.

### `plCertInstalled` [out]

Returns the number of certificates installed into local stores.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

A **Long** that contains the number of certificates installed into local stores.

## Remarks

When this method is called from script, the method displays a user interface that asks whether the user will allow installation of a certificate.

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[InstallPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-installpkcs7)

[acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)