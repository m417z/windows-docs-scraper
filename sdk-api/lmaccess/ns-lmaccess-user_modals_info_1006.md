# USER_MODALS_INFO_1006 structure

## Description

The
**USER_MODALS_INFO_1006** structure contains logon server information.

## Members

### `usrmod1006_role`

Specifies the role of the logon server. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **UAS_ROLE_STANDALONE** | Logon server is a stand-alone. Use this value if no logon services are available. |
| **UAS_ROLE_MEMBER** | Logon server is a member. |
| **UAS_ROLE_BACKUP** | Logon server is a backup. |
| **UAS_ROLE_PRIMARY** | Logon server is a domain controller. |

## See also

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)