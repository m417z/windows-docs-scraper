# SetThreadToken function

## Description

The **SetThreadToken** function assigns an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) to a thread. The function can also cause a thread to stop using an impersonation token.

## Parameters

### `Thread` [in, optional]

A pointer to a handle to the thread to which the function assigns the impersonation token.

If *Thread* is **NULL**, the function assigns the impersonation token to the calling thread.

### `Token` [in, optional]

A handle to the impersonation token to assign to the thread. This handle must have been opened with TOKEN_IMPERSONATE access rights. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

If *Token* is **NULL**, the function causes the thread to stop using an impersonation token.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When using the **SetThreadToken** function to impersonate, you must have the impersonate privileges and make sure that the **SetThreadToken** function succeeds before calling the [RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself) function.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)