# IEnroll2::InstallPKCS7Blob

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **InstallPKCS7Blob** method processes a certificate or chain of certificates, placing them into the appropriate [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method differs from the [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob) method in that **InstallPKCS7Blob** does not receive a request certificate. This method was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

## Parameters

### `pBlobPKCS7` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a certificate or chain of certificates.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## See also

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)