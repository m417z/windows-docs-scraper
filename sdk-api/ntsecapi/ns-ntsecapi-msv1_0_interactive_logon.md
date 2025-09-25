# MSV1_0_INTERACTIVE_LOGON structure

## Description

The **MSV1_0_INTERACTIVE_LOGON** structure contains information about an interactive logon.

It is used by the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.

## Members

### `MessageType`

[MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type) value that specifies the type of logon being requested. This member must be set to **MsV1_0InteractiveLogon**.

### `LogonDomainName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the logon domain. The specified domain name must be a Windows domain or mixed domain that is trusted by this machine.

The **Buffer** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) is relative to the KERB_INTERACTIVE_LOGON structure and must point to memory that is contiguous to the MSV1_0_INTERACTIVE_LOGON structure.

### `UserName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that represents the user's account name. The name can be up to 255 bytes long. The name is treated as case-insensitive. The specified **UserName** must have an account in domain **LogonDomainName**.

The **Buffer** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) is relative to the KERB_INTERACTIVE_LOGON structure and must point to memory that is contiguous to the MSV1_0_INTERACTIVE_LOGON structure.

### `Password`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the user's [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) password. The password may be up to 255 bytes long and contain any Unicode value. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information on protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

The **Buffer** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) is relative to the KERB_INTERACTIVE_LOGON structure and must point to memory that is contiguous to the MSV1_0_INTERACTIVE_LOGON structure.

## See also

[MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type)