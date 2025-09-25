# PrivilegeCheck function

## Description

The **PrivilegeCheck** function determines whether a specified set of
[privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) are enabled in an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). The **PrivilegeCheck** function is typically called by a server application to check the privileges of a client's access token.

## Parameters

### `ClientToken` [in]

A handle to an access token representing a client [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This handle must have been obtained by opening the token of a thread impersonating the client. The token must be open for TOKEN_QUERY access.

### `RequiredPrivileges` [in, out]

A pointer to a
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure. The **Privilege** member of this structure is an array of
[LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid_and_attributes) structures. Before calling **PrivilegeCheck**, use the **Privilege** array to indicate the set of privileges to check. Set the **Control** member to PRIVILEGE_SET_ALL_NECESSARY if all of the privileges must be enabled; or set it to zero if it is sufficient that any one of the privileges be enabled.

When **PrivilegeCheck** returns, the **Attributes** member of each [LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid_and_attributes) structure is set to SE_PRIVILEGE_USED_FOR_ACCESS if the corresponding privilege is enabled.

### `pfResult` [out]

A pointer to a value the function sets to indicate whether any or all of the specified privileges are enabled in the access token. If the **Control** member of the [PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure specifies PRIVILEGE_SET_ALL_NECESSARY, this value is **TRUE** only if all the privileges are enabled; otherwise, this value is **TRUE** if any of the privileges are enabled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An access token contains a list of the privileges held by the account associated with the token. These privileges can be enabled or disabled; most are disabled by default. The **PrivilegeCheck** function checks only for enabled privileges. To get a list of all the enabled and disabled privileges held by an access token, call the
[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function. To enable or disable a set of privileges in an access token, call the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function.

## See also

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid_and_attributes)

[LookupPrivilegeValue](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegevaluea)

[ObjectPrivilegeAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectprivilegeauditalarma)

[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)

[PrivilegedServiceAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-privilegedserviceauditalarma)