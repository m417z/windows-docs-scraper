# PKU2U_CERTIFICATE_S4U_LOGON structure

## Description

Specifies a certificate used for S4U logon.

## Members

### `MessageType`

A value of the [PKU2U_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-pku2u_logon_submit_type) enumeration that indicates the logon type.

### `Flags`

This member is reserved. Do not use it.

### `UserPrincipalName`

The name of the user who is attempting to authenticate.

### `DomainName`

This member is reserved. Do not use it.

### `CertificateLength`

The size, in bytes, of the **Certificate** buffer.

### `Certificate`

The certificate data.