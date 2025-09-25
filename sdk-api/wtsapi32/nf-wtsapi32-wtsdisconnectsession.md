# WTSDisconnectSession function

## Description

Disconnects the logged-on user from the specified Remote Desktop Services session without closing the session. If the user subsequently logs on to the same Remote Desktop Session Host (RD Session Host) server, the user is reconnected to the same session.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function, or specify **WTS_CURRENT_SERVER_HANDLE** to indicate the RD Session Host server on which your application is running.

### `SessionId` [in]

A Remote Desktop Services session identifier. To indicate the current session, specify **WTS_CURRENT_SESSION**. To retrieve the identifiers of all sessions on a specified RD Session Host server, use the
[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa) function.

To be able to disconnect another user's session, you need to have the Disconnect permission. For more information, see
[Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration administrative tool.

To disconnect sessions running on a virtual machine hosted on a RD Virtualization Host server, you must be a member of the Administrators group on the RD Virtualization Host server.

### `bWait` [in]

Indicates whether the operation is synchronous. Specify **TRUE** to wait for the operation to complete, or **FALSE** to return immediately.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)