# AdjustTokenPrivileges function

## Description

The **AdjustTokenPrivileges** function enables or disables privileges in the specified [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). Enabling or disabling privileges in an access token requires TOKEN_ADJUST_PRIVILEGES access.

## Parameters

### `TokenHandle` [in]

A handle to the access token that contains the privileges to be modified. The handle must have TOKEN_ADJUST_PRIVILEGES access to the token. If the *PreviousState* parameter is not **NULL**, the handle must also have TOKEN_QUERY access.

### `DisableAllPrivileges` [in]

Specifies whether the function disables all of the token's privileges. If this value is **TRUE**, the function disables all privileges and ignores the *NewState* parameter. If it is **FALSE**, the function modifies privileges based on the information pointed to by the *NewState* parameter.

### `NewState` [in, optional]

A pointer to a
[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that specifies an array of privileges and their attributes. If the *DisableAllPrivileges* parameter is **FALSE**, the **AdjustTokenPrivileges** function enables, disables, or removes these privileges for the token. The following table describes the action taken by the **AdjustTokenPrivileges** function, based on the privilege attribute.

| Value | Meaning |
| --- | --- |
| **SE_PRIVILEGE_ENABLED** | The function enables the privilege. |
| **SE_PRIVILEGE_REMOVED** | The privilege is removed from the list of privileges in the token. The other privileges in the list are reordered to remain contiguous.<br><br>SE_PRIVILEGE_REMOVED supersedes SE_PRIVILEGE_ENABLED.<br><br>Because the privilege has been removed from the token, attempts to reenable the privilege result in the warning ERROR_NOT_ALL_ASSIGNED as if the privilege had never existed.<br><br>Attempting to remove a privilege that does not exist in the token results in ERROR_NOT_ALL_ASSIGNED being returned.<br><br>Privilege checks for removed privileges result in STATUS_PRIVILEGE_NOT_HELD. Failed privilege check auditing occurs as normal.<br><br>The removal of the privilege is irreversible, so the name of the removed privilege is not included in the *PreviousState* parameter after a call to **AdjustTokenPrivileges**.<br><br>**Windows XP with SP1:** The function cannot remove privileges. This value is not supported. |
| **None** | The function disables the privilege. |

If *DisableAllPrivileges* is **TRUE**, the function ignores this parameter.

### `BufferLength` [in]

Specifies the size, in bytes, of the buffer pointed to by the *PreviousState* parameter. This parameter can be zero if the *PreviousState* parameter is **NULL**.

### `PreviousState` [out, optional]

A pointer to a buffer that the function fills with a [TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that contains the previous state of any privileges that the function modifies. That is, if a privilege has been modified by this function, the privilege and its previous state are contained in the **TOKEN_PRIVILEGES** structure referenced by *PreviousState*. If the **PrivilegeCount** member of **TOKEN_PRIVILEGES** is zero, then no privileges have been changed by this function. This parameter can be **NULL**.

If you specify a buffer that is too small to receive the complete list of modified privileges, the function fails and does not adjust any privileges. In this case, the function sets the variable pointed to by the *ReturnLength* parameter to the number of bytes required to hold the complete list of modified privileges.

### `ReturnLength` [out, optional]

A pointer to a variable that receives the required size, in bytes, of the buffer pointed to by the *PreviousState* parameter. This parameter can be **NULL** if *PreviousState* is **NULL**.

## Return value

If the function succeeds, the return value is nonzero. To determine whether the function adjusted all of the specified privileges, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns one of the following values when the function succeeds:

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function adjusted all specified privileges. |
| **ERROR_NOT_ALL_ASSIGNED** | The token does not have one or more of the privileges specified in the *NewState* parameter. The function may succeed with this error value even if no privileges were adjusted. The *PreviousState* parameter indicates the privileges that were adjusted. |

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **AdjustTokenPrivileges** function cannot add new privileges to the access token. It can only enable or disable the token's existing privileges. To determine the token's privileges, call the
[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function.

The *NewState* parameter can specify privileges that the token does not have, without causing the function to fail. In this case, the function adjusts the privileges that the token does have and ignores the other privileges so that the function succeeds. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine whether the function adjusted all of the specified privileges. The *PreviousState* parameter indicates the privileges that were adjusted.

The *PreviousState* parameter retrieves a
[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that contains the original state of the adjusted privileges. To restore the original state, pass the *PreviousState* pointer as the *NewState* parameter in a subsequent call to the **AdjustTokenPrivileges** function.

#### Examples

For an example that uses this function, see [Enabling and Disabling Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/enabling-and-disabling-privileges-in-c--).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AdjustTokenGroups](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokengroups)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)