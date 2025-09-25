# USER_INFO_1005 structure

## Description

The
**USER_INFO_1005** structure contains a privilege level to assign to a user network account. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1005_priv`

Specifies a **DWORD** value that indicates the level of privilege to assign for the user account specified in the *username* parameter to the
**NetUserSetInfo** function. This member can be one of the following values. For more information about user and group account rights, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

| Value | Meaning |
| --- | --- |
| **USER_PRIV_GUEST** | Guest |
| **USER_PRIV_USER** | User |
| **USER_PRIV_ADMIN** | Administrator |

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)