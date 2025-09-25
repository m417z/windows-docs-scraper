# CEPSetupProperty enumeration

## Description

The **CEPSetupProperty** enumeration type is used by the [GetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-getproperty) and [SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty) methods on the [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) interface to specify the type of property information to retrieve or set.

## Constants

### `ENUM_CEPSETUPPROP_AUTHENTICATION:0`

The property value contains the type of authentication procedure used.

### `ENUM_CEPSETUPPROP_SSLCERTHASH:1`

The property value contains the hash of the certificate, if any, used for authentication.

### `ENUM_CEPSETUPPROP_URL:2`

The property value contains the Certificate Enrollment Policy (CEP) Web Service URL.

### `ENUM_CEPSETUPPROP_KEYBASED_RENEWAL:3`

The property value indicates whether to set up the Enrollment Policy Server in a mode that returns policies for KeyBasedRenewal templates only.

## See also

[GetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-getproperty)

[ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup)

[SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty)