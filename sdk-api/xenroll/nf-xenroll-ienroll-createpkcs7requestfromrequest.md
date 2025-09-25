# IEnroll::CreatePKCS7RequestFromRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **CreatePKCS7RequestFromRequest** method creates a PKCS #7 request from an existing certificate request. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `pRequest` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the existing request.

### `pSigningCertContext` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the certificate used to sign the request.

### `pPkcs7Blob` [out]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that receives the returned PKCS #7 certificate request.

When you have finished using this memory, free it by passing the **pbData** member of this structure to the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll)

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)