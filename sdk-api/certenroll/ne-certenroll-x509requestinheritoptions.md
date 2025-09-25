# X509RequestInheritOptions enumeration

## Description

The **X509RequestInheritOptions** enumeration type specifies how keys, extension values, and external properties are inherited when a new request is created from an existing [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This enumeration can be used to initialize an [IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7) or an [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object from an existing certificate.

You can choose one of the following values to specify how keys are inherited:

* **InheritNewDefaultKey**
* **InheritNewSimilarKey**
* **InheritPrivateKey**
* **InheritPublicKey**

You can also use a bitwise-**AND** operation to combine the key inheritance choice with **InheritNone** or with any combination of the following flags:

* **InheritRenewalCertificateFlag**
* **InheritTemplateFlag**
* **InheritSubjectFlag**
* **InheritExtensionsFlag**
* **InheritSubjectAltNameFlag**
* **InheritValidityPeriodFlag**

## Constants

### `InheritDefault:0`

Inheritance is not specified. For more information, see the [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate) method on the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) interface.

### `InheritNewDefaultKey:0x1`

Creates a new key but inherits the default [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) or KSP.

### `InheritNewSimilarKey:0x2`

Creates a new key but inherits the CSP or KSP used to create the existing certificate.

### `InheritPrivateKey:0x3`

Inherits the [private](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and [public keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `InheritPublicKey:0x4`

Inherits only the public key.

### `InheritKeyMask:0xf`

Use to mask the lower-order 4 bits that identify key inheritance.

### `InheritNone:0x10`

Prevents use of the following inheritance values:

* **InheritRenewalCertificateFlag**
* **InheritTemplateFlag**
* **InheritSubjectFlag**
* **InheritExtensionsFlag**
* **InheritSubjectAltNameFlag**
* **InheritValidityPeriodFlag**

### `InheritRenewalCertificateFlag:0x20`

Inherits the renewal certificate. Specifying this flag sets an [ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal) value.

### `InheritTemplateFlag:0x40`

Inherits the [certificate template](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `InheritSubjectFlag:0x80`

Inherits the subject distinguished name.

### `InheritExtensionsFlag:0x100`

Inherits the relevant extensions from the certificate. Extension values associated with the following [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) are not inherited:

* XCN_OID_CERTSRV_CA_VERSION
* XCN_OID_AUTHORITY_INFO_ACCESS
* XCN_OID_CRL_DIST_POINTS
* XCN_OID_AUTHORITY_KEY_IDENTIFIER2
* XCN_OID_CERTSRV_PREVIOUS_CERT_HASH
* XCN_OID_ENROLL_CERTTYPE_EXTENSION
* XCN_OID_CERTIFICATE_TEMPLATE

### `InheritSubjectAltNameFlag:0x200`

Inherits the **SubjectAlternativeName** extension.

### `InheritValidityPeriodFlag:0x400`

Inherits the validity period.

### `InheritReserved80000000:0x80000000`

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)