# WTSRegisterSessionNotificationEx function

## Description

Registers the specified window to receive session change notifications.

## Parameters

### `hServer` [in]

Handle of the server returned from
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or
**WTS_CURRENT_SERVER**.

### `hWnd` [in]

Handle of the window to receive session change notifications.

### `dwFlags` [in]

Specifies which session notifications are to be received. This parameter can only be
**NOTIFY_FOR_THIS_SESSION** if *hServer* is a remote server.

#### NOTIFY_FOR_THIS_SESSION (0)

Only session notifications involving the session attached to by the window identified by the
*hWnd* parameter value are to be received.

#### NOTIFY_FOR_ALL_SESSIONS (1)

All session notifications are to be received.

## Return value

If the function succeeds, the return value is **TRUE**. Otherwise, it is
**FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called before the dependent services of Remote Desktop Services have started, an
**RPC_S_INVALID_BINDING** error code may be returned. When the
"Global\\TermSrvReadyEvent" global event is set, all dependent services have started and this
function can be successfully called.

Session change notifications are sent in the form of a
[WM_WTSSESSION_CHANGE](https://learn.microsoft.com/windows/desktop/TermServ/wm-wtssession-change) message. These
notifications are sent only to the windows that have registered for them using this function.

When a window no longer requires these notifications, it must call
[WTSUnRegisterSessionNotificationEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsunregistersessionnotificationex)
before being destroyed. For every call to this function, there must be a corresponding call to
**WTSUnRegisterSessionNotificationEx**.

If the window handle passed in this function is already registered, the value of the
*dwFlags* parameter is ignored.

To receive session change notifications from a service, use the
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) function.

## See also

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)

[WM_WTSSESSION_CHANGE](https://learn.microsoft.com/windows/desktop/TermServ/wm-wtssession-change)

[WTSGetActiveConsoleSessionId](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wtsgetactiveconsolesessionid)

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)

[WTSSESSION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wtssession_notification)

[WTSUnRegisterSessionNotificationEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsunregistersessionnotificationex)