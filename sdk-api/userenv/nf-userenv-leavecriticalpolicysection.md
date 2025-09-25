# LeaveCriticalPolicySection function

## Description

The
**LeaveCriticalPolicySection** function resumes the background application of policy. This function closes the handle to the policy section.

## Parameters

### `hSection` [in]

Handle to a policy section, which is returned by the
[EnterCriticalPolicySection](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-entercriticalpolicysection) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[EnterCriticalPolicySection](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-entercriticalpolicysection)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)