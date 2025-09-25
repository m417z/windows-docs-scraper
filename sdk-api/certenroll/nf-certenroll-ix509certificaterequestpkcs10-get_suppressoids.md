# IX509CertificateRequestPkcs10::get_SuppressOids

## Description

The **SuppressOids** property retrieves a collection of the default extension and attribute [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) that were not added to the request when the request was encoded.

This property is read-only.

## Parameters

## Remarks

Attributes and extensions are added to a certificate request when it is encoded or initialized. You can suppress the addition of default extensions and attributes by calling the [SuppressDefaults](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_suppressdefaults) property. For a PKCS #10 request, the following attributes are added by default:

* XCN_OID_REQUEST_CLIENT_INFO
  ([IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid))
* XCN_OID_ENROLLMENT_CSP_PROVIDER ([IX509AttributeCspProvider](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributecspprovider))
* XCN_OID_OS_VERSION ([IX509AttributeOSVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeosversion))
* XCN_OID_RENEWAL_CERTIFICATE ([IX509AttributeRenewalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributerenewalcertificate))

The following extensions are added by default:

* XCN_OID_RSA_SMIMECapabilities ([IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities))
* XCN_OID_SUBJECT_KEY_IDENTIFIER
  ([IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier))
* XCN_OID_KEY_USAGE ([IX509ExtensionKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionkeyusage))

You must initialize the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object before calling this property. For more information, see any of the following methods:

* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate)
* [InitializeFromPrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromprivatekey)
* [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromtemplatename)

## See also

[ICryptAttribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattribute)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509Extension](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extension)