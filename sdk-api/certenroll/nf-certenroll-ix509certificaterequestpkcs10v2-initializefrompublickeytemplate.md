# IX509CertificateRequestPkcs10V2::InitializeFromPublicKeyTemplate

## Description

The **InitializeFromPublicKeyTemplate** method initializes a null-signed certificate request by using an [IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey) object and a template.

## Parameters

### `Context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies whether the requested certificate is intended for an end user, a computer, or an administrator acting on behalf of the computer. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is being requested for an end user. |
| **ContextMachine** | The certificate is being requested for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

### `pPublicKey` [in]

Pointer to an [IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey) interface that represents the public key.

### `pPolicyServer` [in]

Pointer to an [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object that represents the certificate enrollment policy (CEP) server that contains the template specified by the *pTemplate* parameter.

### `pTemplate` [in]

Pointer to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) object that represents the template to use during initialization.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **E_POINTER** | The *pPublicKey*, *pPolicyServer*, or *pTemplate* parameters are **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The certificate request object has already been initialized. |

## Remarks

The **InitializeFromPublicKeyTemplate** method performs the following actions:

* Adds the extensions specified in the template, if any, to the [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* Creates a [CriticalExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_criticalextensions) collection and populates it with the default XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2 object identifiers. If the template indicates that these OIDs are not critical, they are removed from the collection. The OIDs marked critical by the template, if any, are added.
* Sets the [SmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_smimecapabilities) property if the template supports symmetric algorithms.
* Sets the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_alternatesignaturealgorithm) property if the template requires a discrete signature algorithm OID.
* Creates an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Creates a hash algorithm OID if the algorithm is specified in the template and sets it on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Creates an asymmetric encryption algorithm OID if the algorithm is specified in the template and sets it on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.

If the [CSPInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations) property is not specified, the method creates an [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations) collection from the providers installed on the computer.

The method does not create a private key. The use of this method implies that the request is null-signed. Therefore, the method sets the [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) property on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.

## See also

[IX509CertificateRequestPkcs10V2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10v2)