# LOCALGROUP_MEMBERS_INFO_1 structure

## Description

The
**LOCALGROUP_MEMBERS_INFO_1** structure contains the security identifier (SID) and account information associated with the member of a local group.

## Members

### `lgrmi1_sid`

Type: **PSID**

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that contains the security identifier (SID) of an account that is a member of this local group member. The account can be a user account or a global group account.

### `lgrmi1_sidusage`

Type: **SID_NAME_USE**

The account type associated with the security identifier specified in the **lgrmi1_sid** member. The following values are valid.

| Value | Meaning |
| --- | --- |
| **SidTypeUser** | The account is a user account. |
| **SidTypeGroup** | The account is a global group account. |
| **SidTypeWellKnownGroup** | The account is a well-known group account (such as Everyone). For more information, see [Well-Known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids). |
| **SidTypeDeletedAccount** | The account has been deleted. |
| **SidTypeUnknown** | The account type cannot be determined. |

### `lgrmi1_name`

Type: **LPWSTR**

A pointer to the account name of the local group member identified by the **lgrmi1_sid** member. The **lgrmi1_name** member does not include the domain name. For more information, see the following Remarks section.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[LOCALGROUP_MEMBERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_0)

[LOCALGROUP_MEMBERS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_2)

[LOCALGROUP_MEMBERS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_3)

[Local Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupGetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetmembers)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)