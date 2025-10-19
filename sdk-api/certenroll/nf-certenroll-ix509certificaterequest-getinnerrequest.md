# IX509CertificateRequest::GetInnerRequest

## Description

The **GetInnerRequest** method retrieves a nested request object.

## Parameters

### `Level` [in]

 A value of an [InnerRequestLevel](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-innerrequestlevel) enumeration that specifies the envelopment level of the data to retrieve. You can use the *LevelNext* value to iterate through the nested levels or the *LevelInnermost* value to retrieve the most deeply nested request object. You cannot specify *LevelNext* for a PKCS #10 request.

### `ppValue` [out]

Address of a variable that receives a pointer to an [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface that contains the nested request. Call the [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_type) property to determine whether the inner request object is a PKCS #10 or a CMC request. Then call **QueryInterface** to retrieve the appropriate pointer.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | You specified a value of *LevelNext* PKCS #10 request. |

## Remarks

A top-level request object can be a PKCS #10, PKCS #7, or CMC request. The following rules apply to inner request objects:

* A PKCS #10 request cannot contain an inner request object.
* A PKCS #7 request can contain only a PKCS #10 inner request object.
* A CMC request can contain a CMC or a PKCS #10 inner request object. For a CMC request that contains an inner CMC request, there is no theoretical limit to the number of nested levels that can exist before the final inner PKCS #10 request is reached. That is, a top-level CMC request can contain an inner CMC request that also contains an inner CMC request and so on.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)