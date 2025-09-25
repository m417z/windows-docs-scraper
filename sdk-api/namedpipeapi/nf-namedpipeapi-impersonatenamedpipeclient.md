# ImpersonateNamedPipeClient function

## Description

The **ImpersonateNamedPipeClient** function impersonates a named-pipe client application.

## Parameters

### `hNamedPipe` [in]

A handle to a named pipe.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ImpersonateNamedPipeClient** function allows the server end of a named pipe to impersonate the client end. When this function is called, the named-pipe file system changes the thread of the calling [process](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) to start impersonating the [security context](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) of the last message read from the pipe. Only the server end of the pipe can call this function.

The server can call the
[RevertToSelf](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-reverttoself) function when the impersonation is complete.

**Important** If the **ImpersonateNamedPipeClient** function fails, the client is not impersonated, and all subsequent client requests are made in the security context of the process that called the function. If the calling process is running as a privileged account, it can perform actions that the client would not be allowed to perform. To avoid security risks, the calling process should always check the return value. If the return value indicates that the function call failed, no client requests should be executed.

All impersonate functions, including **ImpersonateNamedPipeClient** allow the requested impersonation if one of the following is true:

* The requested impersonation level of the token is less than **SecurityImpersonation**, such as **SecurityIdentification** or **SecurityAnonymous**.
* The caller has the **SeImpersonatePrivilege** privilege.
* A process (or another process in the caller's logon session) created the token using explicit credentials through [LogonUser](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-logonusera) or [LsaLogonUser](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.
* The authenticated identity is same as the caller.

**Windows XP with SP1 and earlier:** The **SeImpersonatePrivilege** privilege is not supported.

#### Examples

For an example that uses this function, see
[Verifying Client Access with ACLs](https://learn.microsoft.com/windows/win32/SecAuthZ/verifying-client-access-with-acls-in-c--).

## See also

[Authorization functions](https://learn.microsoft.com/windows/win32/secauthz/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/win32/SecAuthZ/client-server-access-control)

[DdeImpersonateClient](https://learn.microsoft.com/windows/win32/api/ddeml/nf-ddeml-ddeimpersonateclient)

[DuplicateToken](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetoken)

[RevertToSelf](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-reverttoself)