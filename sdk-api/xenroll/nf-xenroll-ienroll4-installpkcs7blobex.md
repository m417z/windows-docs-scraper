# IEnroll4::InstallPKCS7BlobEx

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **InstallPKCS7BlobEx** method processes a certificate or chain of certificates, placing them into the appropriate [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The **InstallPKCS7BlobEx** method is the same as
[InstallPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll2-installpkcs7blob) except that it returns the number of certificates actually installed in local stores.

## Parameters

### `pBlobPKCS7` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a certificate or chain of certificates.

### `plCertInstalled` [out]

Returns the number of certificates installed into local stores.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)