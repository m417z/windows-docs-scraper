# LogonUserExW function

## Description

The **LogonUserEx** function attempts to log a user on to the local computer. The local computer is the computer from which **LogonUserEx** was called. You cannot use **LogonUserEx** to log on to a remote computer. You specify the user with a user name and domain and [authenticate](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) the user with a plaintext password. If the function succeeds, you receive a handle to a token that represents the logged-on user. You can then use this token handle to impersonate the specified user or, in most cases, to create a [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that runs in the context of the specified user.

## Parameters

### `lpszUsername` [in]

A pointer to a null-terminated string that specifies the name of the user. This is the name of the user account to log on to. If you use the [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) format, user@DNS_domain_name, the *lpszDomain* parameter must be **NULL**.

### `lpszDomain` [in, optional]

A pointer to a null-terminated string that specifies the name of the domain or server whose account database contains the *lpszUsername* account. If this parameter is **NULL**, the user name must be specified in UPN format. If this parameter is ".", the function validates the account by using only the local account database.

### `lpszPassword` [in, optional]

A pointer to a null-terminated string that specifies the plaintext password for the user account specified by *lpszUsername*. When you have finished using the password, clear the password from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `dwLogonType` [in]

The type of logon operation to perform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LOGON32_LOGON_BATCH** | This logon type is intended for batch servers, where processes may be executing on behalf of a user without their direct intervention. This type is also for higher performance servers that process many plaintext authentication attempts at a time, such as mail or web servers. The **LogonUserEx** function does not cache credentials for this logon type. |
| **LOGON32_LOGON_INTERACTIVE** | This logon type is intended for users who will be interactively using the computer, such as a user being logged on by a [terminal](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) server, remote shell, or similar process. This logon type has the additional expense of caching logon information for disconnected operations; therefore, it is inappropriate for some client/server applications, such as a mail server. |
| **LOGON32_LOGON_NETWORK** | This logon type is intended for high performance servers to authenticate plaintext passwords. The **LogonUserEx** function does not cache credentials for this logon type. |
| **LOGON32_LOGON_NETWORK_CLEARTEXT** | This logon type preserves the name and password in the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly), which allows the server to make connections to other network servers while impersonating the client. A server can accept plaintext credentials from a client, call **LogonUserEx**, verify that the user can access the system across the network, and still communicate with other servers. |
| **LOGON32_LOGON_NEW_CREDENTIALS** | This logon type allows the caller to clone its current token and specify new credentials for outbound connections. The new logon session has the same local identifier but uses different credentials for other network connections.<br><br>This logon type is supported only by the LOGON32_PROVIDER_WINNT50 logon provider. |
| **LOGON32_LOGON_SERVICE** | Indicates a service-type logon. The account provided must have the service privilege enabled. |
| **LOGON32_LOGON_UNLOCK** | This logon type is for [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLLs that log on users who will be interactively using the computer. This logon type can generate a unique audit record that shows when the workstation was unlocked. |

### `dwLogonProvider` [in]

The logon provider. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LOGON32_PROVIDER_DEFAULT** | Use the standard logon provider for the system. The default [security provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is NTLM. |
| **LOGON32_PROVIDER_WINNT50** | Use the negotiate logon provider. |
| **LOGON32_PROVIDER_WINNT40** | Use the NTLM logon provider. |

### `phToken` [out, optional]

A pointer to a handle variable that receives a handle to a token that represents the specified user.

You can use the returned handle in calls to the
[ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) function.

In most cases, the returned handle is a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that you can use in calls to the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function. However, if you specify the LOGON32_LOGON_NETWORK flag, **LogonUserEx** returns an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that you cannot use in **CreateProcessAsUser** unless you call [DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) to convert the impersonation token to a primary token.

When you no longer need this handle, close it by calling the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `ppLogonSid` [out, optional]

A pointer to a pointer to a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that receives the SID of the user logged on.

When you have finished using the SID, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

### `ppProfileBuffer` [out, optional]

A pointer to a pointer that receives the address of a buffer that contains the logged on user's profile.

### `pdwProfileLength` [out, optional]

A pointer to a **DWORD** that receives the length of the profile buffer.

### `pQuotaLimits` [out, optional]

A pointer to a [QUOTA_LIMITS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-quota_limits) structure that receives information about the quotas for the logged on user.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The LOGON32_LOGON_NETWORK logon type is fastest, but it has the following limitations:

* The function returns an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly), not a primary token. You cannot use this token directly in the
  [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function. However, you can call the
  [DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) function to convert the token to a primary token, and then use it in **CreateProcessAsUser**.
* If you convert the token to a primary token and use it in [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) to start a process, the new process cannot access other network resources, such as remote servers or printers, through the redirector. An exception is that if the network resource is not access controlled, then the new process will be able to access it.

The SE_TCB_NAME privilege is not required for this function unless you are logging onto a Passport account.

The account specified by *lpszUsername* must have the necessary account rights. For example, to log on a user with the LOGON32_LOGON_INTERACTIVE flag, the user (or a group to which the user belongs) must have the SE_INTERACTIVE_LOGON_NAME account right. For a list of the account rights that affect the various logon operations, see
[Account Object Access Rights](https://learn.microsoft.com/windows/desktop/SecMgmt/account-object-access-rights).

A user is considered logged on if at least one token exists. If you call
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) and then close the token, the user is still logged on until the process (and all child processes) have ended.

If the **LogonUserEx** call is successful, the system notifies network providers that the logon occurred by calling the provider's [NPLogonNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nplogonnotify) entry-point function.

> [!NOTE]
> The winbase.h header defines LogonUserEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex)

[ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser)

[QUOTA_LIMITS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-quota_limits)