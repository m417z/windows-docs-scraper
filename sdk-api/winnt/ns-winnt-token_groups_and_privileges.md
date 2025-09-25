# TOKEN_GROUPS_AND_PRIVILEGES structure

## Description

The **TOKEN_GROUPS_AND_PRIVILEGES** structure contains information about the group [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) and privileges in an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Members

### `SidCount`

Number of SIDs in the access token.

### `SidLength`

Length, in bytes, required to hold all of the user SIDs and the account SID for the group.

### `Sids`

A pointer to an array of
[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures that contain a set of SIDs and corresponding attributes.

The **Attributes** members of the [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures can have the following values.

| Value | Meaning |
| --- | --- |
| **SE_GROUP_ENABLED**<br><br>0x00000004L | The SID is enabled for access checks. When the system performs an access check, it checks for access-allowed and access-denied [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) that apply to the SID. <br><br>A SID without this attribute is ignored during an access check unless the SE_GROUP_USE_FOR_DENY_ONLY attribute is set. |
| **SE_GROUP_ENABLED_BY_DEFAULT**<br><br>0x00000002L | The SID is enabled by default. |
| **SE_GROUP_INTEGRITY**<br><br>0x00000020L | The SID is a mandatory integrity SID.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SE_GROUP_INTEGRITY_ENABLED**<br><br>0x00000040L | The mandatory integrity SID is evaluated during access check.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SE_GROUP_LOGON_ID**<br><br>0xC0000000L | The SID is a logon SID that identifies the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) associated with an access token. |
| **SE_GROUP_MANDATORY**<br><br>0x00000001L | The SID cannot have the SE_GROUP_ENABLED attribute cleared by a call to the [AdjustTokenGroups](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups) function. However, you can use the [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken) function to convert a mandatory SID to a deny-only SID. |
| **SE_GROUP_OWNER**<br><br>0x00000008L | The SID identifies a group account for which the user of the token is the owner of the group, or the SID can be assigned as the owner of the token or objects. |
| **SE_GROUP_RESOURCE**<br><br>0x20000000L | The SID identifies a domain-local group. |
| **SE_GROUP_USE_FOR_DENY_ONLY**<br><br>0x00000010L | The SID is a deny-only SID in a [restricted token](https://learn.microsoft.com/windows/desktop/SecAuthZ/restricted-tokens). When the system performs an access check, it checks for access-denied ACEs that apply to the SID; it ignores access-allowed ACEs for the SID. <br><br>If this attribute is set, SE_GROUP_ENABLED is not set, and the SID cannot be reenabled. |

### `RestrictedSidCount`

Number of restricted SIDs.

### `RestrictedSidLength`

Length, in bytes, required to hold all of the restricted SIDs.

### `RestrictedSids`

A pointer to an array of
[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures that contain a set of restricted SIDs and corresponding attributes.

The **Attributes** members of the [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures can have the same values as those listed for the preceding **Sids** member.

### `PrivilegeCount`

Number of privileges.

### `PrivilegeLength`

Length, in bytes, needed to hold the privilege array.

### `Privileges`

Array of privileges.

### `AuthenticationId`

[Locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) of the authenticator of the token.

## See also

[AdjustTokenGroups](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups)

[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken)

[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)