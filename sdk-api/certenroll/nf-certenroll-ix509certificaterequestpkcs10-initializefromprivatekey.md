# IX509CertificateRequestPkcs10::InitializeFromPrivateKey

## Description

The **InitializeFromPrivateKey** method initializes the certificate request by using an [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object and, optionally, a template. This method is web enabled.

## Parameters

### `Context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies whether the requested certificate is intended for an end user, a computer, or an administrator acting on behalf of the computer. This can be one of the following values. However, if the [MachineContext](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_machinecontext) property of the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) is set, you must specify the **ContextMachine** enumeration value.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is being requested for an end user. |
| **ContextMachine** | The certificate is being requested for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

### `pPrivateKey` [in]

Pointer to an [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface that represents the private key.

### `strTemplateName` [in, optional]

A **BSTR** variable that contains the Common Name (CN) of the template as it appears in Active Directory or the dotted decimal [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly). This is an optional parameter.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The certificate request object has already been initialized. |

## Remarks

If you specify a template, the **InitializeFromPrivateKey** method performs the following actions:

* Adds the extensions specified by the template to an [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.
* Creates an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) collection and populates it with the default XCN_OID_KEY_USAGE and XCN_OID_BASIC_CONSTRAINTS2 object identifiers. If the template indicates that these OIDs are not critical, they are removed from the collection. The OIDs marked critical by the template are added.
* Sets the [SmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_smimecapabilities) property if the template supports symmetric algorithms.
* Sets the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_alternatesignaturealgorithm) property if the template requires a discrete signature algorithm OID.
* Creates an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Creates a hash algorithm OID if the algorithm is specified in the template and sets it on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Retrieves an asymmetric encryption algorithm OID, if it exists, from the template and sets it on the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object.
* Populates many of the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) properties from the template settings.

Whether you specify a template or not, if the [CSPInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations) property is not specified, the method creates an [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations) collection from the providers installed on the computer.

No private key is created at this point. If the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object passed to the method does not represent an existing key, a key is created when the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method is called. The key will be created by using the default provider if no template was specified and the [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername) property on the **IX509PrivateKey** is not set. When a private key exists, it is set on the [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_privatekey) property.

## See also

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)