# USER_MODALS_INFO_1 structure

## Description

The
**USER_MODALS_INFO_1** structure contains logon server and domain controller information.

## Members

### `usrmod1_role`

Specifies the role of the logon server. The following values are defined.

| Value | Meaning |
| --- | --- |
| **UAS_ROLE_STANDALONE** | The logon server is a stand-alone server. |
| **UAS_ROLE_MEMBER** | The logon server is a member. |
| **UAS_ROLE_BACKUP** | The logon server is a backup. |
| **UAS_ROLE_PRIMARY** | The logon server is a domain controller. |

If the Netlogon service is not being used, the element should be set to UAS_ROLE_STANDALONE.

### `usrmod1_primary`

Pointer to a Unicode string that specifies the name of the domain controller that stores the primary copy of the database for the user account manager.

## See also

[NetUserModalsGet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsget)

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)