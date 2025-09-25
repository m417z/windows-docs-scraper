# CESSetupProperty enumeration

## Description

The **CESSetupProperty** enumeration type is used by the [GetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-getproperty) and [SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-setproperty) methods on the [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) interface to specify the type of property information to retrieve or set.

## Constants

### `ENUM_CESSETUPPROP_USE_IISAPPPOOLIDENTITY:0`

The property value specifies whether the server context is **ApplicationPoolIdentity**.

### `ENUM_CESSETUPPROP_CACONFIG:1`

The property value contains a certification authority (CA) configuration string.

### `ENUM_CESSETUPPROP_AUTHENTICATION:2`

The property value specifies the type of authentication procedure used.

### `ENUM_CESSETUPPROP_SSLCERTHASH:3`

The property value contains a hash of the certificate used for authentication.

### `ENUM_CESSETUPPROP_URL:4`

The property value contains the Certificate Enrollment Web Service (CES) URL.

### `ENUM_CESSETUPPROP_RENEWALONLY:5`

The property value specifies whether CES can process only certificate renewals.

### `ENUM_CESSETUPPROP_ALLOW_KEYBASED_RENEWAL:6`

## See also

[GetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-getproperty)

[ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup)

[SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-setproperty)