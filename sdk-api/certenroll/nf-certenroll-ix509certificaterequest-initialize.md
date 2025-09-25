# IX509CertificateRequest::Initialize

## Description

The **Initialize** method initializes the request object for a user or a computer.

## Parameters

### `Context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies whether the certificate is intended for an end user, a computer, or an administrator acting on behalf of a computer. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is being requested for an end user. |
| **ContextMachine** | The certificate is being requested for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

The **Initialize** method initializes various objects depending on the type of certificate request being created. If you call this method from an [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object, a private key object is created and the following objects are initialized:

* An empty [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection.
* An empty [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* An [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection that contains the default critical extension object identifiers, XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2. This collection can be retrieved by calling the [CriticalExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_criticalextensions) property.
* An empty [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection for the [SuppressOids](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_suppressoids) property.
* An [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations) object that contains the values you specified in the [CSPInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations) property or a collection of all providers installed on the computer. This collection is used to create a private key.

If you call this method from an [IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc) object, an inner PKCS #10 request is created as above and the following objects are initialized:

* An empty [ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes) collection.
* An empty [IX509NameValuePairs](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepairs) collection.
* An empty [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* An [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection that contains the default critical extension object identifiers, XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2. This collection can be retrieved by calling the [CriticalExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_criticalextensions) property.
* An empty IObjectIds collection for the [SuppressOids](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_suppressoids) property.
* An empty [ISignerCertificates](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificates) collection.

If you call this method from an [IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7) object, an inner PKCS #10 request is created as above.

The following properties can be called before you call this method.

* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_parentwindow)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_uicontextmessage)

You must call the [CSPInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations) property before calling this method if you want to specify an [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations) collection.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)