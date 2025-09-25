# USER_INFO_1010 structure

## Description

The
**USER_INFO_1010** structure contains a set of bit flags defining the operator privileges assigned to a user network account. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1010_auth_flags`

Specifies a **DWORD** value that contains a set of bit flags that specify the user's operator privileges. The user is specified in the *username* parameter to the
**NetUserSetInfo** function.

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AF_OP_PRINT** | The print operator privilege is enabled. |
| **AF_OP_COMM** | The communications operator privilege is enabled. |
| **AF_OP_SERVER** | The server operator privilege is enabled. |
| **AF_OP_ACCOUNTS** | The accounts operator privilege is enabled. |

## Remarks

 For more information about controlling access to securable objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control), [Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges), and [Securable Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects).

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)