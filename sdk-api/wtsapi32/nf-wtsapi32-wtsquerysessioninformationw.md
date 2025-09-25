# WTSQuerySessionInformationW function

## Description

Retrieves session information for the specified session on the specified Remote Desktop Session Host (RD Session Host) server. It can be used
to query session information on local and remote RD Session Host servers.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify
**WTS_CURRENT_SERVER_HANDLE** to indicate the RD Session Host server on which your application
is running.

### `SessionId` [in]

A Remote Desktop Services session identifier. To indicate the session in which the calling application is running
(or the current session) specify **WTS_CURRENT_SESSION**. Only specify
**WTS_CURRENT_SESSION** when obtaining session information on the local server. If
**WTS_CURRENT_SESSION** is specified when querying session information on a remote server,
the returned session information will be inconsistent. Do not use the returned data.

You can use the [WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)
function to retrieve the identifiers of all sessions on a specified RD Session Host server.

To query information for another user's session, you must have Query Information permission. For more
information, see [Remote Desktop Services
Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration administrative
tool.

### `WTSInfoClass` [in]

A value of the [WTS_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_info_class) enumeration that indicates the type of
session information to retrieve in a call to the
**WTSQuerySessionInformation** function.

### `ppBuffer` [out]

A pointer to a variable that receives a pointer to the requested information. The format and contents of the
data depend on the information class specified in the *WTSInfoClass* parameter. To free
the returned buffer, call the [WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory)
function.

### `pBytesReturned` [out]

A pointer to a variable that receives the size, in bytes, of the data returned in
*ppBuffer*.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To retrieve the session ID for the current session when Remote Desktop Services is running, call
**WTSQuerySessionInformation** and specify
**WTS_CURRENT_SESSION** for the *SessionId* parameter and
**WTSSessionId** for the *WTSInfoClass* parameter. The session ID
will be returned in the *ppBuffer* parameter. If Remote Desktop Services is not running, calls
to **WTSQuerySessionInformation** fail. In
this situation, you can retrieve the current session ID by calling the
[ProcessIdToSessionId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-processidtosessionid) function.

To determine whether your application is running on the physical console, you must specify
**WTS_CURRENT_SESSION** for the *SessionId* parameter, and
**WTSClientProtocolType** as the *WTSInfoClass* parameter.
If *ppBuffer* is "0", the session is attached to the physical console.

> [!NOTE]
> The wtsapi32.h header defines WTSQuerySessionInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSCONFIGINFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsconfiginfoa)

[WTSINFOEX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoexa)

[WTS_CLIENT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_address)

[WTS_CLIENT_DISPLAY](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_display)

[WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class)

[WTS_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_info_class)

[WTS_SESSION_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_address)