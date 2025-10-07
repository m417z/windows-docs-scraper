# LogonUserExExW function

The **LogonUserExExW** function attempts to log a user on to the local computer. The local computer is the computer from which **LogonUserExExW** was called. You cannot use **LogonUserExExW** to log on to a remote computer. Specify the user by using a user name and domain and [*authenticate*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) the user by using a plaintext password. If the function succeeds, it receives a handle to a token that represents the logged-on user. You can then use this token handle to impersonate the specified user or, in most cases, to create a [*process*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) that runs in the context of the specified user.

This function is similar to the [**LogonUserEx**](https://learn.microsoft.com/windows/desktop/api/Winbase/nf-winbase-logonuserexa) function, except that it takes the additional parameter, *pTokenGroups*, which is a set of one or more [*security identifiers*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) (SIDs) that are added to the token returned to the caller when the logon is successful.

This function is not declared in a public header and has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Advapi32.dll.

## Parameters

*lpszUsername* \[in\]

A pointer to a null-terminated string that specifies the name of the user. This is the name of the user account to log on to. If you use the [*user principal name*](https://learn.microsoft.com/windows/win32/secgloss/u-gly) (UPN) format, the *lpszDomain* parameter must be **NULL**.

*lpszDomain* \[in, optional\]

A pointer to a null-terminated string that specifies the name of the domain or server whose account database contains the *lpszUsername* account. If this parameter is **NULL**, the user name must be specified in UPN format. If this parameter is ".", the function validates the account by using only the local account database.

*lpszPassword* \[in, optional\]

A pointer to a null-terminated string that specifies the plaintext password for the user account specified by *lpszUsername*. When you have finished using the password, clear the password from memory by calling the [**SecureZeroMemory**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/win32/secbp/handling-passwords).

*dwLogonType* \[in\]

The type of logon operation to perform. This parameter can be one of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**LOGON32\_LOGON\_INTERACTIVE**

2

| This logon type is intended for users who will be interactively using the computer, such as a user being logged on by a [*terminal*](https://learn.microsoft.com/windows/win32/secgloss/t-gly) server, remote shell, or similar process. This logon type has the additional expense of caching logon information for disconnected operations; therefore, it is inappropriate for some client/server applications, such as a mail server.<br> |
|

**LOGON32\_LOGON\_NETWORK**

3

| This logon type is intended for high performance servers to authenticate plaintext passwords. The **LogonUserExExW** function does not cache credentials for this logon type.<br> |
|

**LOGON32\_LOGON\_BATCH**

4

| This logon type is intended for batch servers, where processes may be executing on behalf of a user without their direct intervention. This type is also for higher performance servers that process many plaintext authentication attempts at a time, such as mail or web servers. The **LogonUserExExW** function does not cache credentials for this logon type.<br> |
|

**LOGON32\_LOGON\_SERVICE**

5

| Indicates a service-type logon. The account provided must have the service privilege enabled.<br> |
|

**LOGON32\_LOGON\_UNLOCK**

7

| This logon type is for [*GINA*](https://learn.microsoft.com/windows/win32/secgloss/g-gly) DLLs that log on users who will be interactively using the computer. This logon type can generate a unique audit record that shows when the workstation was unlocked.<br> |
|

**LOGON32\_LOGON\_NETWORK\_CLEARTEXT**

8

| This logon type preserves the name and password in the [*authentication package*](https://learn.microsoft.com/windows/win32/secgloss/a-gly), which allows the server to make connections to other network servers while impersonating the client. A server can accept plaintext credentials from a client, call **LogonUserExExW**, verify that the user can access the system across the network, and still communicate with other servers. <br> |
|

**LOGON32\_LOGON\_NEW\_CREDENTIALS**

9

| This logon type allows the caller to clone its current token and specify new credentials for outbound connections. The new logon session has the same local identifier but uses different credentials for other network connections.<br> This logon type is supported only by the **LOGON32\_PROVIDER\_WINNT50** logon provider.<br> |

*dwLogonProvider* \[in\]

The logon provider. This parameter can be one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**LOGON32\_PROVIDER\_DEFAULT**

| Use the standard logon provider for the system. The default [*security provider*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) is NTLM.<br> |
|

**LOGON32\_PROVIDER\_WINNT50**

| Use the negotiate logon provider. <br> |
|

**LOGON32\_PROVIDER\_WINNT40**

| Use the NTLM logon provider.<br> |

*pTokenGroups* \[in, optional\]

A pointer to a [**TOKEN\_GROUPS**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_groups) structure that specifies a list of group SIDs that are added to the token that this function receives upon successful logon. Any SIDs added to the token also effect group expansion. For example, if the added SIDs are members of local groups, those groups are also added to the received access token.

If this parameter is not **NULL**, the caller of this function must have the **SE\_TCB\_PRIVILEGE** privilege granted and enabled.

*phToken* \[out, optional\]

A pointer to a handle variable that receives a handle to a token that represents the specified user.

You can use the returned handle in calls to the [**ImpersonateLoggedOnUser**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) function.

In most cases, the returned handle is a [*primary token*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) that you can use in calls to the [**CreateProcessAsUser**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function. However, if you specify the LOGON32\_LOGON\_NETWORK flag, **LogonUserExExW** returns an [*impersonation token*](https://learn.microsoft.com/windows/win32/secgloss/i-gly) that you cannot use in **CreateProcessAsUser** unless you call [**DuplicateTokenEx**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) to convert the impersonation token to a primary token.

When you no longer need this handle, close it by calling the [**CloseHandle**](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function.

*ppLogonSid* \[out, optional\]

A pointer to a pointer to a SID that receives the SID of the user logged on.

When you have finished using the SID, free it by calling the [**LocalFree**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree) function.

*ppProfileBuffer* \[out, optional\]

A pointer to a pointer that receives the address of a buffer that contains the logged on user's profile.

*pdwProfileLength* \[out, optional\]

A pointer to a **DWORD** that receives the length of the profile buffer.

*pQuotaLimits* \[out, optional\]

A pointer to a [**QUOTA\_LIMITS**](https://learn.microsoft.com/windows/desktop/api/Winnt/ns-winnt-quota_limits) structure that receives information about the quotas for the logged on user.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LOGON32\_LOGON\_NETWORK** logon type is fastest, but it has the following limitations:

- The function returns an [*impersonation token*](https://learn.microsoft.com/windows/win32/secgloss/i-gly), not a primary token. You cannot use this token directly in the [**CreateProcessAsUser**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function. However, you can call the [**DuplicateTokenEx**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) function to convert the token to a primary token, and then use it in **CreateProcessAsUser**.
- If you convert the token to a primary token and use it in [**CreateProcessAsUser**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) to start a process, the new process cannot access other network resources, such as remote servers or printers, through the redirector. An exception is that if the network resource is not access controlled, then the new process will be able to access it.

The account specified by *lpszUsername* must have the necessary account rights. For example, to log on a user with the **LOGON32\_LOGON\_INTERACTIVE** flag, the user (or a group to which the user belongs) must have the **SE\_INTERACTIVE\_LOGON\_NAME** account right. For a list of the account rights that affect the various logon operations, see [Account Object Access Rights](https://learn.microsoft.com/windows/win32/secmgmt/account-object-access-rights).

A user is considered logged on if at least one token exists. If you call [**CreateProcessAsUser**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) and then close the token, the user is still logged on until the process (and all child processes) have ended.

If the optional *pTokenGroups* parameter is supplied, LSA will not add either the local SID or the logon SID automatically.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Version<br> | LogonUserExExW is also available onWindows Server 2003 or Windows XPwith the General Distribution Release.<br> |
| Header<br> | Winbasep.h |
| DLL<br> | Advapi32.dll |

## See also

[Client/Server Access Control](https://learn.microsoft.com/windows/win32/secauthz/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/win32/secauthz/authorization-functions)

[**CloseHandle**](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[**CreateProcessAsUser**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[**DuplicateTokenEx**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex)

[**ImpersonateLoggedOnUser**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser)

[**LogonUserEx**](https://learn.microsoft.com/windows/desktop/api/Winbase/nf-winbase-logonuserexa)

[**QUOTA\_LIMITS**](https://learn.microsoft.com/windows/desktop/api/Winnt/ns-winnt-quota_limits)

