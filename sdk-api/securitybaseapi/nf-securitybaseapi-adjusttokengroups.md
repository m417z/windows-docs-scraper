# AdjustTokenGroups function

## Description

The **AdjustTokenGroups** function enables or disables groups already present in the specified [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). Access to TOKEN_ADJUST_GROUPS is required to enable or disable groups in an access token.

## Parameters

### `TokenHandle` [in]

A handle to the access token that contains the groups to be enabled or disabled. The handle must have TOKEN_ADJUST_GROUPS access to the token. If the *PreviousState* parameter is not **NULL**, the handle must also have TOKEN_QUERY access.

### `ResetToDefault` [in]

Boolean value that indicates whether the groups are to be set to their default enabled and disabled states. If this value is **TRUE**, the groups are set to their default states and the *NewState* parameter is ignored. If this value is **FALSE**, the groups are set according to the information pointed to by the *NewState* parameter.

### `NewState` [in, optional]

A pointer to a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the groups to be enabled or disabled. If the *ResetToDefault* parameter is **FALSE**, the function sets each of the groups to the value of that group's SE_GROUP_ENABLED attribute in the **TOKEN_GROUPS** structure. If *ResetToDefault* is **TRUE**, this parameter is ignored.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by the *PreviousState* parameter. This parameter can be zero if the *PreviousState* parameter is **NULL**.

### `PreviousState` [out, optional]

A pointer to a buffer that receives a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure containing the previous state of any groups the function modifies. That is, if a group has been modified by this function, the group and its previous state are contained in the **TOKEN_GROUPS** structure referenced by *PreviousState*. If the **GroupCount** member of **TOKEN_GROUPS** is zero, then no groups have been changed by this function. This parameter can be **NULL**.

If a buffer is specified but it does not contain enough space to receive the complete list of modified groups, no group states are changed and the function fails. In this case, the function sets the variable pointed to by the *ReturnLength* parameter to the number of bytes required to hold the complete list of modified groups.

### `ReturnLength` [out, optional]

A pointer to a variable that receives the actual number of bytes needed for the buffer pointed to by the *PreviousState* parameter. This parameter can be **NULL** and is ignored if *PreviousState* is **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The information retrieved in the *PreviousState* parameter is formatted as a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure. This means a pointer to the buffer can be passed as the *NewState* parameter in a subsequent call to the **AdjustTokenGroups** function, restoring the original state of the groups.

The *NewState* parameter can list groups to be changed that are not present in the access token. This does not affect the successful modification of the groups in the token.

The **AdjustTokenGroups** function cannot disable groups with the SE_GROUP_MANDATORY attribute in the [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure. Use
[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken) instead.

You cannot enable a group that has the SE_GROUP_USE_FOR_DENY_ONLY attribute.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)