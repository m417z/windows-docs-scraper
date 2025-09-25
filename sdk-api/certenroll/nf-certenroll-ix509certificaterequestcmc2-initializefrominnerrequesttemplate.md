# IX509CertificateRequestCmc2::InitializeFromInnerRequestTemplate

## Description

The **InitializeFromInnerRequestTemplate** method initializes the certificate request from an inner request object and a template.

## Parameters

### `pInnerRequest` [in]

Pointer to an [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface that represents the inner request object. This can be a PKCS #10 or a CMC request.

### `pPolicyServer` [in]

Pointer to an [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object that represents the certificate enrollment policy (CEP) server that contains the template specified by the *pTemplate* parameter.

### `pTemplate` [in]

Pointer to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) object that represents the template to use during initialization.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CRYPT_E_INVALID_MSG_TYPE**** | The request object passed to the *pInnerRequest* parameter must be a PKCS #10 or a CMC request. |
| **E_POINTER** | The *pInnerRequest*, *pPolicyServer*, and *pTemplate* parameters cannot be **NULL**. |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The request object has already been initialized. |

## Remarks

By specifying a template, you can add information to the outer request object that may not be contained in the inner request. For example, if the inner request does not contain the necessary extensions, you can supply a template that does.

The **InitializeFromInnerRequestTemplate** method:

* Creates an empty [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection.
* Creates an empty [IX509NameValuePairs](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepairs) collection.
* Creates an empty [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* Creates an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection for critical extensions and adds the XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2 object identifiers (OIDs).
* Creates an empty [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection of OIDs to be suppressed from the request object.
* Creates an empty [ISignerCertificates](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificates) collection.
* Retrieves private key flags from the template.
* Sets the [ArchivePrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_archiveprivatekey) property if required by the template flags or settings.
* Retrieves the encryption algorithm from the template if one is specified and sets the [EncryptionAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_encryptionalgorithm) property.
* Sets the [EncryptionStrength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_encryptionstrength) property if possible.

## See also

[IX509CertificateRequestCmc2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc2)