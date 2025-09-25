# WTSUnRegisterSessionNotificationEx function

## Description

Unregisters the specified window so that it receives no further session change notifications.

## Parameters

### `hServer` [in]

Handle of the server returned from
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or
**WTS_CURRENT_SERVER**.

### `hWnd` [in]

Handle of the window to be unregistered from receiving session notifications.

## Return value

If the function succeeds, the return value is **TRUE**. Otherwise, it is **FALSE**. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function must be called once for every call to the
[WTSRegisterSessionNotificationEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotificationex)
function.

## See also

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)

[WTSRegisterSessionNotificationEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotificationex)

[WTSUnRegisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsunregistersessionnotification)