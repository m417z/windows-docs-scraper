# GROUP_INFO_0 structure

## Description

The
**GROUP_INFO_0** structure contains the name of a global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `grpi0_name`

Pointer to a null-terminated Unicode character string that specifies the name of the global group. For more information, see the following Remarks section.

When you call the
[NetGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetinfo) function this member specifies the new name of the global group.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadd)

[NetGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupenum)

[NetGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetinfo)

[NetGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)