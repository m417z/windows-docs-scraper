# GROUP_USERS_INFO_0 structure

## Description

The
**GROUP_USERS_INFO_0** structure contains global group member information.

## Members

### `grui0_name`

A pointer to a null-terminated Unicode character string that specifies a name. For more information, see the Remarks section.

## Remarks

If you are calling the
[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers) function or the
[NetGroupSetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetusers) function, the **grui0_name** member contains the name of a user that is a member of the specified group.

If you are calling the
[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups) function or the
[NetUserSetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetgroups) function, the **grui0_name** member contains the name of a global group to which the specified user belongs.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1)

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers)

[NetGroupSetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetusers)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetgroups)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)