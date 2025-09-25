# EnterCriticalPolicySection function

## Description

The
**EnterCriticalPolicySection** function pauses the application of policy to allow applications to safely read policy settings. Applications call this function if they read multiple policy entries and must ensure that the settings are not changed while they are being read. This mutex protects Group Policy processing for all client-side extensions stored in a Group Policy Object (GPO).

## Parameters

### `bMachine` [in]

A value that specifies whether to stop the application of computer policy or user policy. If this value is **TRUE**, the system stops applying computer policy. If this value is **FALSE**, the system stops applying user policy.

## Return value

If the function succeeds, the return value is a handle to a policy section.

If the function fails, the return value is **NULL**. To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The maximum amount of time an application can hold a critical section is 10 minutes. After 10 minutes, the system releases the critical section and policy can be applied again.

To acquire both the computer and user critical section objects, acquire the user critical section object before acquiring the computer critical section object. This will help prevent a deadlock situation.

To close the handle, call the
[LeaveCriticalPolicySection](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-leavecriticalpolicysection) function. The policy section handle cannot be used in any other Windows functions.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[LeaveCriticalPolicySection](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-leavecriticalpolicysection)