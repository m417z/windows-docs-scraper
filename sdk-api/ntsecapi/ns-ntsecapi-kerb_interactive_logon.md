# KERB_INTERACTIVE_LOGON structure

## Description

The **KERB_INTERACTIVE_LOGON** structure contains information about an interactive [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

It is used by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) with the Kerberos security package using LOGON32_PROVIDER_WINNT50 or LOGON32_PROVIDER_DEFAULT.

## Members

### `MessageType`

[KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) value identifying the type of logon request being made. This member must be set to **KerbInteractiveLogon**.

### `LogonDomainName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) specifying the name of the target logon domain.

### `UserName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) specifying the user name.

### `Password`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) specifying the user password. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)). For more information on protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).