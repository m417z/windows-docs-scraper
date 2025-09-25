# GROUP_INFO_2 structure

## Description

The
**GROUP_INFO_2** structure contains information about a global group, including name, identifier, and resource attributes.

It is recommended that you use the
[GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) structure instead.

## Members

### `grpi2_name`

Pointer to a null-terminated Unicode character string that specifies the name of the global group. For more information, see the following Remarks section.

When you call the
[NetGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetinfo) function this member is ignored.

### `grpi2_comment`

Pointer to a null-terminated Unicode character string that contains a remark associated with the global group. This member can be a null string. The comment can contain MAXCOMMENTSZ characters.

### `grpi2_group_id`

The relative identifier (RID) of the global group. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member. For more information about RIDs, see
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

### `grpi2_attributes`

These attributes are hard-coded to SE_GROUP_MANDATORY, SE_GROUP_ENABLED, and SE_GROUP_ENABLED_BY_DEFAULT. For more information, see
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups).

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

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)