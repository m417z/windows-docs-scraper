# GROUP_USERS_INFO_1 structure

## Description

The
**GROUP_USERS_INFO_1** structure contains global group member information.

## Members

### `grui1_name`

Type: **LPWSTR**

A pointer to a null-terminated Unicode character string that specifies a name. For more information, see the Remarks section.

### `grui1_attributes`

Type: **DWORD**

A set of attributes for this entry. This member can be a combination of the security group attributes defined in the *Winnt.h* header file.

| Value | Meaning |
| --- | --- |
| **SE_GROUP_MANDATORY**<br><br>0x00000001 | The group is mandatory. |
| **SE_GROUP_ENABLED_BY_DEFAULT**<br><br>0x00000002 | The group is enabled for access checks by default. |
| **SE_GROUP_ENABLED**<br><br>0x00000004 | The group is enabled for access checks. |
| **SE_GROUP_OWNER**<br><br>0x00000008 | The group identifies a group account for which the user of the token is the owner of the group. |
| **SE_GROUP_USE_FOR_DENY_ONLY**<br><br>0x00000010 | The group is used for deny only purposes. When this attribute is set, the SE_GROUP_ENABLED attribute must not be set. |
| **SE_GROUP_INTEGRITY**<br><br>0x00000020 | The group is used for integrity. This attribute is available on Windows Vista and later. |
| **SE_GROUP_INTEGRITY_ENABLED**<br><br>0x00000040 | The group is enabled for integrity level. This attribute is available on Windows Vista and later. |
| **SE_GROUP_LOGON_ID**<br><br>0xC0000000 | The group is used to identify a logon session associated with an access token. |
| **SE_GROUP_RESOURCE**<br><br>0x20000000 | The group identifies a domain-local group. |

## Remarks

If you are calling the
[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers) function or the
[NetGroupSetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetusers) function, the **grui1_name** member contains the name of a user that is a member of the specified group.

If you are calling the
[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups) function or the
[NetUserSetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetgroups) function, the **grui1_name** member contains the name of a global group to which the specified user belongs.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

Windows Vista and later include an addition to the access control security mechanism of Windows that labels processes and other securable objects with an integrity level. Internet-facing programs are at higher risk for exploits than other programs because they download untrustworthy content from unknown sources. Running these programs with fewer permissions, or at a lower integrity level, than other programs reduces the ability of an exploit to modify the system or harm user data files. The SE_GROUP_INTEGRITY and SE_GROUP_INTEGRITY_ENABLED attributes of the **grui1_attributes** member are used for this purpose.

## See also

**GROUP_USERS_INFO_0**

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers)

[NetGroupSetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetusers)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetgroups)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)