# WFDDisplaySinkCloseSession function

Cleans up the state for the session being opened, or the currently open session.

## Parameters

*hSessionHandle* \[in\]

The handle received via the most recent [**WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-callback) invocation that included one.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

## Remarks

Your app can call this function to terminate the Miracast session for any reason. Your app is not required to call it when it receives the **DisconnectedNotification** type in its callback.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| End of client support<br> | Windows 10<br> |
| End of server support<br> | Windows Server 2016<br> |
| Header<br> | Wfdsink.h |
| Library<br> | Wifidisplay.lib |
| DLL<br> | Wifidisplay.dll |

## See also

[**WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-callback)

