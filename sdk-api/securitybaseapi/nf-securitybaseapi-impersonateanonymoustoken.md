# ImpersonateAnonymousToken function

## Description

The **ImpersonateAnonymousToken** function enables the specified thread to impersonate the system's anonymous logon token. To ensure that a token matches the operating system's concept of anonymous access, this function should be called before attempting network access to generate an anonymous token on the remote server.

## Parameters

### `ThreadHandle` [in]

A handle to the thread to impersonate the system's anonymous logon token. The thread handle must have the THREAD_IMPERSONATE access right in order for the thread to impersonate the system's anonymous logon token.

To grant such access, the thread must be opened by calling [OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) with the desired access right to THREAD_IMPERSONATE.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

An error of ACCESS_DENIED might indicate that the token is for a restricted process. Use [OpenProcessToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) and [IsTokenRestricted](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-istokenrestricted) to check if the process is restricted. ACCESS_DENIED is also returned if the thread handle lacks right access to THREAD_IMPERSONATE.

## Remarks

Anonymous tokens do not include the "Everyone" Group SID unless the system default has been overridden by setting the HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa\EveryoneIncludesAnonymous registry value to DWORD=1.

To cancel the impersonation, call
[RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself).

## See also

- [Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)
- [Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
- [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/procthread/thread-security-and-access-rights)
- [RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself)