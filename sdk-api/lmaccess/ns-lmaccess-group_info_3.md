# GROUP_INFO_3 structure

## Description

The
**GROUP_INFO_3** structure contains information about a global group, including name, security identifier (SID), and resource attributes.

## Members

### `grpi3_name`

Pointer to a null-terminated Unicode character string that specifies the name of the global group.

When you call the
[NetGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetinfo) function this member is ignored.

### `grpi3_comment`

Pointer to a null-terminated Unicode character string that contains a remark associated with the global group. This member can be a null string. The comment can contain MAXCOMMENTSZ characters.

### `grpi3_group_sid`

Pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that contains the
[security identifier (SID)](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers) that uniquely identifies the global group. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `grpi3_attributes`

These attributes are hard-coded to SE_GROUP_MANDATORY, SE_GROUP_ENABLED, and SE_GROUP_ENABLED_BY_DEFAULT. For more information, see
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups).

## See also

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadd)

[NetGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupenum)

[NetGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetinfo)

[NetGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)