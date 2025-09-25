# IX509CertificateRequestPkcs7::InitializeFromInnerRequest

## Description

The **InitializeFromInnerRequest** method initializes the certificate request from the inner PKCS #10 object. This method is web enabled.

## Parameters

### `pInnerRequest` [in]

Pointer to an [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface that represents the request.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CRYPT_E_INVALID_MSG_TYPE**** | The request object specified on input is not a PKCS #10 request. |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The request object has already been initialized. |

## Remarks

This method sets the inner request object to the PKCS #10 request specified on input.

## See also

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)