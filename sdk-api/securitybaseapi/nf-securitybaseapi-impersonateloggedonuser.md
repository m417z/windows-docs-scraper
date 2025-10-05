# ImpersonateLoggedOnUser function

## Description

The **ImpersonateLoggedOnUser** function lets the calling thread impersonate the [security context](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) of a logged-on user. The user is represented by a token handle.

## Parameters

### `hToken` [in]

A handle to a primary or impersonation [access token](https://learn.microsoft.com/windows/win32/SecGloss/a-gly) that represents a logged-on user. This can be a token handle returned by a call to [LogonUser](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-logonusera), [CreateRestrictedToken](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), [DuplicateToken](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetoken), [DuplicateTokenEx](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex), [OpenProcessToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or [OpenThreadToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) functions. If *hToken* is a handle to a [primary token](https://learn.microsoft.com/windows/win32/SecGloss/p-gly), the token must have **TOKEN_QUERY** and **TOKEN_DUPLICATE** access. If *hToken* is a handle to an [impersonation token](https://learn.microsoft.com/windows/win32/SecGloss/i-gly), the token must have **TOKEN_QUERY** and **TOKEN_IMPERSONATE** access.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The impersonation lasts until the thread exits or until it calls [RevertToSelf](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-reverttoself).

The calling thread does not need to have any particular [privileges](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) to call **ImpersonateLoggedOnUser**.

If the call to **ImpersonateLoggedOnUser** fails, the client connection is not impersonated and the client request is made in the security context of the process. If the process is running as a highly privileged account, such as LocalSystem, or as a member of an administrative group, the user may be able to perform actions they would otherwise be disallowed. Therefore, it is important to always check the return value of the call, and if it fails, raise an error; do not continue execution of the client request.

All impersonate functions, including **ImpersonateLoggedOnUser** allow the requested impersonation if one of the following is true:

- The caller has the **SeImpersonatePrivilege** privilege.
- A process (or another process in the caller's logon session) created the token using explicit credentials through [LogonUser](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-logonusera) or [LsaLogonUser](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.
- The authenticated identity is same as the caller.

> [!IMPORTANT]
> The token must have an impersonation level of **SecurityImpersonation** or higher for impersonation to succeed. Tokens with **SecurityIdentification** or **SecurityAnonymous** levels cannot be used for impersonation, even if the caller has **SeImpersonatePrivilege**. **SecurityIdentification** tokens allow identity verification and ACL checks but do not permit impersonation.

#### Impersonation Level Requirements

The behavior varies based on the token's impersonation level:

- **SecurityAnonymous**: The server cannot obtain client identity information and cannot impersonate the client.
- **SecurityIdentification**: The server can obtain the client's identity and perform access validation, but cannot impersonate the client. This is the default level for many scenarios.
- **SecurityImpersonation**: The server can impersonate the client's security context on the local system. This is the minimum level required for **ImpersonateLoggedOnUser** to succeed.
- **SecurityDelegation**: The server can impersonate the client on remote systems as well as locally.

**Windows XP with SP1 and earlier:** The **SeImpersonatePrivilege** privilege is not supported.

For more information about impersonation, see [Client Impersonation](https://learn.microsoft.com/windows/win32/SecAuthZ/client-impersonation).

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/win32/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/win32/SecAuthZ/client-server-access-control)

[CreateProcessAsUser](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[CreateRestrictedToken](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken)

[DuplicateToken](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetoken)

[DuplicateTokenEx](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex)

[LogonUser](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-logonusera)

[OpenProcessToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[OpenThreadToken](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[RevertToSelf](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-reverttoself)