# PolicyQualifierType enumeration

## Description

The **PolicyQualifierType** enumeration type specifies the type of qualifier applied to a [certificate policy](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This enumeration is used by the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) method and the [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_type) property on the [IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier) interface.

## Constants

### `PolicyQualifierTypeUnknown:0`

The qualifier type is not specified.

### `PolicyQualifierTypeUrl:1`

The qualifier is a URL that points to a Certification Practice Statement (CPS) that has been defined by the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to outline the policies under which the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) was issued and the purposes for which the certificate can be used.

### `PolicyQualifierTypeUserNotice:2`

The qualifier is a text statement to be displayed by the application to any user who relies on the certificate. The user notice identifies the permitted uses of the certificate.

### `PolicyQualifierTypeFlags:3`

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier)

[IPolicyQualifiers](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifiers)

[IX509ExtensionCertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensioncertificatepolicies)