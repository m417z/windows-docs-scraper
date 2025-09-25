# LOCALGROUP_USERS_INFO_0 structure

## Description

The
**LOCALGROUP_USERS_INFO_0** structure contains local group member information.

## Members

### `lgrui0_name`

Pointer to a Unicode string specifying the name of a local group to which the user belongs.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[Local Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetUserGetLocalGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetlocalgroups)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)