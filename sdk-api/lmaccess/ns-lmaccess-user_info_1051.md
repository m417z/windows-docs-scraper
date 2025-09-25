# USER_INFO_1051 structure

## Description

The
**USER_INFO_1051** structure contains the relative ID (RID) associated with the user account. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1051_primary_group_id`

Specifies a **DWORD** value that contains the RID of the Primary Global Group for the user specified in the *username* parameter to the
**NetUserSetInfo** function. This member must be the RID of a global group that represents the enrolled user. For more information about RIDs, see
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)