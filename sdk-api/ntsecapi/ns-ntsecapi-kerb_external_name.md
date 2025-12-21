# KERB_EXTERNAL_NAME structure

## Description

The **KERB_EXTERNAL_NAME** structure contains information about an external name.

An external name is one used by external users. This structure is used by the
[KERB_EXTERNAL_TICKET](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_external_ticket) structure.

## Members

### `NameType`

Indicates the type of the names stored in this structure.

| Value | Meaning |
| --- | --- |
| **KRB_NT_UNKNOWN** | Unknown name type. |
| **KRB_NT_PRINCIPAL** | Name of the user or a Kerberos name type principal in the case of a DCE. |
| **KRB_NT_SRV_INST** | Service name and other unique name as instance (krbtgt). |
| **KRB_NT_SRV_HST** | Service name with host name as instance (telnet, rcommands). |
| **KRB_NT_SRV_XHST** | Service name with host as instance other than krbtgt, telnet, or rcommands. |
| **KRB_NT_UID** | Unique ID. |
| **KRB_NT_ENTERPRISE_PRINCIPAL** | User principal name (UPN) or [service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN). |
| **KRB_NT_ENT_PRINCIPAL_AND_ID** | UPN and [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). |
| **KRB_NT_MS_PRINCIPAL** | Windows NT 4.0–style name. |
| **KRB_NT_MS_PRINCIPAL_AND_ID** | Windows NT 4.0–style name with SID. |

### `NameCount`

Indicates the number of names stored in **Names**.

### `Names`

Array of
[UNICODE_STRINGS](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the names.