# WTSQueryUserToken function

## Description

Obtains the primary access token of the logged-on user specified by the session ID. To call
this function successfully, the calling application must be running within the context of the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account) and have the
**SE_TCB_NAME** privilege.

**Caution** **WTSQueryUserToken** is
intended for highly trusted services. Service providers must use caution that they do not leak user tokens when
calling this function. Service providers must close token handles after they have finished using them.

## Parameters

### `SessionId` [in]

A Remote Desktop Services session identifier. Any program running in the context of a service will have a
session identifier of zero (0). You can use the
[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa) function to retrieve
the identifiers of all sessions on a specified RD Session Host server.

To be able to query information for another user's session, you need to have the Query Information
permission. For more information, see
[Remote Desktop Services
Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration
administrative tool.

### `phToken` [out]

If the function succeeds, receives a pointer to the token handle for the logged-on user. Note that you must
call the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close this
handle.

## Return value

If the function succeeds, the return value is a nonzero value, and the *phToken*
parameter points to the primary token of the user.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For information about primary tokens, see
[Access Tokens](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens). For more information about
account privileges, see
[Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions)
and [Authorization Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

See [LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account) for
information about the privileges associated with that account.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)