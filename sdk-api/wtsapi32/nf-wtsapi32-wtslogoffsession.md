# WTSLogoffSession function

## Description

Logs off a specified Remote Desktop Services session.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function, or specify **WTS_CURRENT_SERVER_HANDLE** to indicate the RD Session Host server on which your application is running.

### `SessionId` [in]

A Remote Desktop Services session identifier. To indicate the current session, specify **WTS_CURRENT_SESSION**. You can use the
[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa) function to retrieve the identifiers of all sessions on a specified RD Session Host server.

To be able to log off another user's session, you need to have the Reset permission. For more information, see
[Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration administrative tool.

To log off sessions running on a virtual machine hosted on a RD Virtualization Host server, you must be a member of the Administrators group on the RD Virtualization Host server.

### `bWait` [in]

Indicates whether the operation is synchronous.

If *bWait* is **TRUE**, the function returns when the session is logged off.

If *bWait* is **FALSE**, the function returns immediately. To verify that the session has been logged off, specify the session identifier in a call to the
[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function.
**WTSQuerySessionInformation** returns zero if the session is logged off.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)