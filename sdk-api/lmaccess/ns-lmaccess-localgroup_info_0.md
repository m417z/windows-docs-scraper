# LOCALGROUP_INFO_0 structure

## Description

The
**LOCALGROUP_INFO_0** structure contains a local group name.

## Members

### `lgrpi0_name`

Pointer to a Unicode string that specifies a local group name. For more information, see the following Remarks section.

## Remarks

When you call the
[NetLocalGroupAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupadd) function, this member specifies the name of a new local group. When you call the
[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo) function, this member specifies the new name of an existing local group.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[Local Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupadd)

[NetLocalGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupenum)

[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)