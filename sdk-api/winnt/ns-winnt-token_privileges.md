# TOKEN_PRIVILEGES structure

## Description

The **TOKEN_PRIVILEGES** structure contains information about a set of privileges for an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Members

### `PrivilegeCount`

This must be set to the number of entries in the **Privileges** array.

### `Privileges`

Specifies an array of
[LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid_and_attributes) structures. Each structure contains the
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) and attributes of a privilege. To get the name of the privilege associated with a **LUID**, call the [LookupPrivilegeName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegenamea) function, passing the address of the **LUID** as the value of the *lpLuid* parameter.

**Important** The constant **ANYSIZE_ARRAY** is defined as 1 in the public header Winnt.h. To create this array with more than one element, you must allocate sufficient memory for the structure to take into account additional elements.

The attributes of a privilege can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SE_PRIVILEGE_ENABLED** | The privilege is enabled. |
| **SE_PRIVILEGE_ENABLED_BY_DEFAULT** | The privilege is enabled by default. |
| **SE_PRIVILEGE_REMOVED** | Used to remove a privilege. For details, see [AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges). |
| **SE_PRIVILEGE_USED_FOR_ACCESS** | The privilege was used to gain access to an object or service. This flag is used to identify the relevant privileges in a set passed by a client application that may contain unnecessary privileges. |

## See also

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)

[LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid_and_attributes)

[LookupPrivilegeName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegenamea)

[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)

[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)

[PrivilegedServiceAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-privilegedserviceauditalarma)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)