# WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK callback function

The **WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK** function defines the callback function—which you implement in your app—that was specified to the [**WFDStartDisplaySink**](https://learn.microsoft.com/windows/win32/nativewifi/wfdstartdisplaysink) function.

## Parameters

*pvContext* \[in, optional\]

An optional context pointer passed to the callback function.

*pNotification* \[in\]

A pointer to a struct containing data about the display sink notification.

*pNotificationResult* \[in, out, optional\]

A pointer to a struct containing data that your app can optionally set to indicate the result of processing the display sink notification.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | Wfdsink.h |

