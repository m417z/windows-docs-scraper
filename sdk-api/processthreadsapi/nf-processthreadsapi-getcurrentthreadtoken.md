# GetCurrentThreadToken function

## Description

Retrieves a pseudo-handle that you can use as a shorthand way to refer to the [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that was assigned to the current thread.

## Return value

A pseudo-handle that you can use as a shorthand way to refer to the [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that was assigned to the current thread.

## Remarks

A pseudo-handle is a special constant that can function as the impersonation token for the current thread. The calling thread can use a pseudo-handle to specify the impersonation token for that thread whenever a token handle is required. Child processes do not inherit pseudo-handles.

Starting in Windows 8, this pseudo-handle has only TOKEN_QUERY and TOKEN_QUERY_SOURCE access rights.

The pseudo-handle cannot be duplicated by the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function or the [DuplicateToken](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetoken) function.

You do not need to close the pseudo-handle when you no longer need it. If you call the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function with a pseudo-handle, the function has no effect.

## See also

[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken)