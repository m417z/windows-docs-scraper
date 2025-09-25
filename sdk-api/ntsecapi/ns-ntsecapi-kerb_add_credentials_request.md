# KERB_ADD_CREDENTIALS_REQUEST structure

## Description

Specifies a message to add, remove, or replace an extra server credential for a logon session. The **SeTcbPrivilege** is required to alter another logon account's credentials.

## Members

### `MessageType`

A
value of the [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration that lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. This member must be set to **KerbAddExtraCredentialsMessage**.

### `UserName`

The user name for the credential.

### `DomainName`

The domain name for the credential.

### `Password`

The password for the credential.

### `LogonId`

The logon ID of the credential. The value of this member can be **NULL**.

### `Flags`

A value that specifies what to do with the credential. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **KERB_REQUEST_ADD_CREDENTIAL**<br><br>1 | Add the specified credential to the logon session. |
| **KERB_REQUEST_REPLACE_CREDENTIAL**<br><br>2 | Replace the specified credential in the logon session. |
| **KERB_REQUEST_REMOVE_CREDENTIAL**<br><br>4 | Remove the specified credential from the logon session. |

## Remarks

Calling the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function with this structure affects only the behavior of the [AcceptSecurityContext (Kerberos)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function. Using this structure allows multiple physical and virtual servers to share a single identity.

## See also

[KERB_ADD_CREDENTIALS_REQUEST_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_add_credentials_request_ex)