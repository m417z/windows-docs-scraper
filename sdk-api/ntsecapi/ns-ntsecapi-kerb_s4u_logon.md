# KERB_S4U_LOGON structure

## Description

The **KERB_S4U_LOGON** structure contains information about a service for user (S4U) logon. This structure is used by the [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function with the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) package.

## Members

### `MessageType`

A value of the [KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) enumeration that identifies the type of logon being requested. This member must be set to **KerbS4ULogon**.

### `Flags`

Flags that provide more information about the logon.

| Value | Meaning |
| --- | --- |
| **KERB_S4U_LOGON_FLAG_CHECK_LOGONHOURS**<br><br>0x2 | Requests the hours that the user has been logged on. |
| **KERB_S4U_LOGON_FLAG_IDENTIFY**<br><br>0x8 | Requests the identity token. |

### `ClientUpn`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that specifies the [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) of the client. This member cannot be **NULL**.

The **Buffer** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure must point to memory that is contiguous to the **KERB_S4U_LOGON** structure.

### `ClientRealm`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that specifies the realm of the client, if known. If the realm is not known, this member can be **NULL**.

The **Buffer** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure must point to memory that is contiguous to the **KERB_S4U_LOGON** structure.