# IX509CertificateRequestPkcs7V2::InitializeFromTemplate

## Description

The **InitializeFromTemplate** method initializes the certificate request by using a template.

## Parameters

### `context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies whether the requested certificate is intended for an end user, a computer, or an administrator acting on behalf of the computer. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is being requested for an end user. |
| **ContextMachine** | The certificate is being requested for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

### `pPolicyServer` [in]

Pointer to an [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object that represents the certificate enrollment policy (CEP) server that contains the template specified by the *pTemplate* parameter.

### `pTemplate` [in]

Pointer to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) object that represents the template to use during initialization.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **E_POINTER** | The *pTemplate* parameter cannot be **NULL**. |
| **ERROR_ALREADY_INITIALIZED** | The certificate request object has already been initialized. |

## Remarks

The **InitializeFromTemplate** method creates a PKCS #7 request object and sets the following properties to the values that existed before this method was called:

* [CspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations)
* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_parentwindow)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_uicontextmessage)

The method creates the following collections:

* An [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection.
* An [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* An [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection populated with the default XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2 object identifiers.
* An empty [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection for attribute and extension OIDs to be suppressed from the new request.

The method then examines the template and performs the following actions:

* Adds the extensions specified by the template to the [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* Removes the default critical extensions (XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2) from the collection if the template indicates that they are not critical. The OIDs marked critical by the template are added.
* Sets the [SmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_smimecapabilities) property if the template supports symmetric algorithms.
* Sets the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_alternatesignaturealgorithm) property if the template requires a discrete signature algorithm OID.
* Creates an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Creates a hash algorithm OID if the algorithm is specified in the template and sets it on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Creates an asymmetric encryption algorithm OID if the algorithm is specified in the template and sets it on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Populates many of the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) properties from the template settings.

If the [CSPInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations) property is **NULL**, the method creates an [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations) collection from the providers installed on the computer.

Finally, the method sets the initialized PKCS #10 request as the inner request object.

## See also

[IX509CertificateRequestPkcs7V2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7v2)