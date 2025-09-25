# EnrollmentTemplateProperty enumeration

## Description

The **EnrollmentTemplateProperty** enumeration contains property values for a given template.

## Constants

### `TemplatePropCommonName:1`

A **VT_BSTR** value that contains the common name of the template in Active Directory.

### `TemplatePropFriendlyName:2`

A **VT_BSTR** value that contains the template display name.

### `TemplatePropEKUs:3`

A **VT_DISPATCH** pointer to an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) interface that contains a collection of extended key usage object identifiers. This value applies to version 2 and later templates.

### `TemplatePropCryptoProviders:4`

A **VT_ARRAY|VT_BSTR** collection of cryptographic service providers (version 2) and key storage providers (version 3) that the client can use when generating requests based on this template.

### `TemplatePropMajorRevision:5`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that specifies the major version number for the template.

### `TemplatePropDescription:6`

Not used.

### `TemplatePropKeySpec:7`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that contains **AT_SIGNATURE** or **AT_KEYEXCHANGE** to specify the **Key_Spec** value for legacy cryptographic service providers.

### `TemplatePropSchemaVersion:8`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that specifies the template version. Currently, this can be 1, 2, or 3.

### `TemplatePropMinorRevision:9`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that specifies the minor version number of a version 2 and later template.

### `TemplatePropRASignatureCount:10`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that specifies the number of recovery agent signatures that are required when generating a certificate request base on this template.

### `TemplatePropMinimumKeySize:11`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that specifies the minimum size of the public key used by the enrolling client.

### `TemplatePropOID:12`

A **VT_DISPATCH** pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that contains an object identifier for this template. This value applies to version 2 and later templates.

### `TemplatePropSupersede:13`

A **VT_ARRAY|VT_BSTR** collection that contains the common names of all version 2 and later templates that have been superseded.

### `TemplatePropRACertificatePolicies:14`

A **VT_DISPATCH** pointer to an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) interface that contains a collection of certificate policy object identifiers for the registration authority certificates. This value applies to version 2 and later templates.

### `TemplatePropRAEKUs:15`

A **VT_DISPATCH** pointer to an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) interface that contains a collection of application policy object identifiers for the registration authority certificates. This value applies to version 2 and later templates.

### `TemplatePropCertificatePolicies:16`

A **VT_DISPATCH** pointer to an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) interface that contains a collection of policy object identifiers to be added to the certificate policy extension.

### `TemplatePropV1ApplicationPolicy:17`

A **VT_DISPATCH** pointer to an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) interface that contains a collection of policy object identifiers to be added to the certificate application policy extension.

### `TemplatePropAsymmetricAlgorithm:18`

A **VT_BSTR** value that specifies the name of a public key algorithm the enrolling client must use when generating a certificate request based on this template. This value applies to version 3 and later templates.

### `TemplatePropKeySecurityDescriptor:19`

A **VT_BSTR** value that specifies the asymmetric key security descriptor for version 3 and later templates.

### `TemplatePropSymmetricAlgorithm:20`

A **VT_BSTR** value that specifies the name of the symmetric algorithm that a client must use for key exchange when using this template. This value applies to version 3 and later templates.

### `TemplatePropSymmetricKeyLength:21`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that specifies the length, in bits, of the symmetric key. This value applies to version 3 and later templates.

### `TemplatePropHashAlgorithm:22`

A **VT_BSTR** value that specifies the name of the hashing algorithm that an enrolling client must use. This value applies to version 3 and later templates.

### `TemplatePropKeyUsage:23`

### `TemplatePropEnrollmentFlags:24`

A **VT_I4** value that contains a bitwise **OR** of [X509CertificateTemplateEnrollmentFlag](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificatetemplateenrollmentflag) values.

### `TemplatePropSubjectNameFlags:25`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that contains a bitwise **OR** of [X509CertificateTemplateSubjectNameFlag](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificatetemplatesubjectnameflag) values.

### `TemplatePropPrivateKeyFlags:26`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that contains a bitwise **OR** of [X509CertificateTemplatePrivateKeyFlag](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificatetemplateprivatekeyflag) values.

### `TemplatePropGeneralFlags:27`

A **VT_UI4** (**VT_I4** beginning with Windows 8.1) value that contains a bitwise **OR** of [X509CertificateTemplateGeneralFlag](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificatetemplategeneralflag) values.

### `TemplatePropSecurityDescriptor:28`

A **VT_BSTR** value that specifies the security descriptor.

### `TemplatePropExtensions:29`

A **VT_DISPATCH** pointer to an [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) interface that contains the certificate extensions to be added to the certificate request when generating requests based on this template.

### `TemplatePropValidityPeriod:30`

A **VT_UI8 FILETIME** value that contains the maximum validity period, in seconds, of the certificate.

### `TemplatePropRenewalPeriod:31`

A **VT_UI8 FILETIME** value that specifies the amount of time before expiration that automatic enrollment has to attempt certificate renewal.