# LOCALGROUP_INFO_1 structure

## Description

The
**LOCALGROUP_INFO_1** structure contains a local group name and a comment describing the local group.

## Members

### `lgrpi1_name`

Pointer to a Unicode string that specifies a local group name. For more information, see the following Remarks section.

This member is ignored when you call the
[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo) function.

### `lgrpi1_comment`

Pointer to a Unicode string that contains a remark associated with the local group. This member can be a null string. The comment can have as many as MAXCOMMENTSZ characters.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[Local Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupadd)

[NetLocalGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupenum)

[NetLocalGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetinfo)

[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)