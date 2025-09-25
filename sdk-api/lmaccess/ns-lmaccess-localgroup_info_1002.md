# LOCALGROUP_INFO_1002 structure

## Description

The
**LOCALGROUP_INFO_1002** structure contains a comment describing a local group.

## Members

### `lgrpi1002_comment`

Pointer to a Unicode string that specifies a remark associated with the local group. This member can be a null string. The comment can have as many as MAXCOMMENTSZ characters.

## See also

[Local Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)