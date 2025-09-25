# IX509Enrollment::InitializeFromRequest

## Description

The **InitializeFromRequest** method initializes the enrollment object from an existing [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) object. This method is web enabled.

## Parameters

### `pRequest` [in]

Pointer to the [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The enrollment object has already been initialized. |

## Remarks

The **InitializeFromRequest** method:

* Verifies that the request is a PKCS #10, PKCS #7, or CMC request object.
* Retrieves the template, if any, associated with the request.
* Validates the template.
* Sets the request object on the [Request](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_request) property.
* Retrieves the signature count, issuance policies, and application policies from the template.
* Retrieves the renewal certificate if one exists.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)