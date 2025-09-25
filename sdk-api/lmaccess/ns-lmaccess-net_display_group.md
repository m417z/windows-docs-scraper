# NET_DISPLAY_GROUP structure

## Description

The
**NET_DISPLAY_GROUP** structure contains information that an account manager can access to determine information about group accounts.

## Members

### `grpi3_name`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of the group.

### `grpi3_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a comment associated with the group. This string can be a null string, or it can have any number of characters before the terminating null character.

### `grpi3_group_id`

Type: **DWORD**

The relative identifier (RID) of the group. The relative identifier is determined by the accounts database when the group is created. It uniquely identifies the group to the account manager within the domain. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member. For more information about RIDs, see
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

### `grpi3_attributes`

Type: **DWORD**

These attributes are hard-coded to SE_GROUP_MANDATORY, SE_GROUP_ENABLED, and SE_GROUP_ENABLED_BY_DEFAULT. For more information, see
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups).

### `grpi3_next_index`

Type: **DWORD**

The index of the last entry returned by the
[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function. Pass this value as the *Index* parameter to
**NetQueryDisplayInformation** to return the next logical entry. Note that you should not use the value of this member for any purpose except to retrieve more data with additional calls to
**NetQueryDisplayInformation**.

## See also

[Get Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/get-functions)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)