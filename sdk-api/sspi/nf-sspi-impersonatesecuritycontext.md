# ImpersonateSecurityContext function

## Description

The **ImpersonateSecurityContext** function allows a server to impersonate a client by using a token previously obtained by a call to [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) or [QuerySecurityContextToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritycontexttoken). This function allows the application server to act as the client, and thus all necessary access controls are enforced.

## Parameters

### `phContext` [in]

The handle of the context to impersonate. This handle must have been obtained by a call to the
[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns the following error code.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle passed to the function is not valid. |
| **SEC_E_NO_IMPERSONATION** | The client could not be impersonated. |
| **SEC_E_UNSUPPORTED_FUNCTION** | This value is returned by Schannel kernel mode to indicate that this function is not supported. |

## Remarks

The server application calls the **ImpersonateSecurityContext** function when it needs to impersonate the client. Before doing so, the server must have obtained a valid context handle. To obtain the context handle, the server must call
[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) to submit the client's incoming security token to the security system. The server gets a context handle if the inbound context is validated. The function creates an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) and allows the thread or process to run with the impersonation context.

When using the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP), the server application must pass the **ASC_REQ_MUTUAL_AUTH** flag when calling [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext). This ensures that the client is asked for a client certificate during the SSL/TLS handshake. When a client certificate is received, the Schannel package verifies the client certificate and attempts to map it to a user account. When this mapping is successful, then a client user token is created and this function succeeds.

The application server must call the
[RevertSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-revertsecuritycontext) function when it finishes or when it needs to restore its own [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

**ImpersonateSecurityContext** is not available with all [security packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) on all platforms. Typically, it is implemented only on platforms and with security packages that support impersonation. To learn whether a security package supports impersonation, call the
[QuerySecurityPackageInfo](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritypackageinfoa) function.

**Note** If the **ImpersonateSecurityContext** function fails, the client is not impersonated, and all subsequent client requests are made in the security context of the process that called the function. If the calling process is running as a privileged account, it can perform actions that the client would not be allowed to perform. To avoid security risks, the calling process should always check the return value. If the return value indicates that the function call failed, no client requests should be executed.

All impersonate functions, including **ImpersonateSecurityContext** allow the requested impersonation if one of the following is true:

* The requested impersonation level of the token is less than **SecurityImpersonation**, such as **SecurityIdentification** or **SecurityAnonymous**.
* The caller has the **SeImpersonatePrivilege** privilege.
* A process (or another process in the caller's logon session) created the token using explicit credentials through [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) or [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.
* The authenticated identity is same as the caller.

**Windows XP with SP1 and earlier:** The **SeImpersonatePrivilege** privilege is not supported.

**Windows XP:** The SeImpersonatePrivilege privilege is not supported until Windows XP with Service Pack 2 (SP2).

## See also

[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext)

[QuerySecurityPackageInfo](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritypackageinfoa)

[RevertSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-revertsecuritycontext)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)