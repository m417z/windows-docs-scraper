# ICEnroll3::InstallPKCS7

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **InstallPKCS7** method processes a certificate or chain of certificates, placing them into the appropriate [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method differs from the [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7) method in that **InstallPKCS7** does not receive a request certificate. This method was first defined in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

## Parameters

### `PKCS7` [in]

A string that contains a certificate or chain of certificates.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When this method is called from script, the method displays a user interface that asks whether the user will allow installation of a certificate.

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[ICEnroll::acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)