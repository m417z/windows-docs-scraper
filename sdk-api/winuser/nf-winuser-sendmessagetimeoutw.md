# SendMessageTimeoutW function

## Description

Sends the specified message to one or more windows.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose window procedure will receive the message.

If this parameter is **HWND_BROADCAST** ((HWND)0xffff), the message is sent to all top-level windows in the system, including disabled or invisible unowned windows. The function does not return until each window has timed out. Therefore, the total wait time can be up to the value of *uTimeout* multiplied by the number of top-level windows.

### `Msg` [in]

Type: **UINT**

The message to be sent.

For lists of the system-provided messages, see [System-Defined Messages](https://learn.microsoft.com/windows/desktop/winmsg/about-messages-and-message-queues).

### `wParam` [in]

Type: **WPARAM**

Any additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Any additional message-specific information.

### `fuFlags` [in]

Type: **UINT**

The behavior of this function. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SMTO_ABORTIFHUNG**<br><br>0x0002 | The function returns without waiting for the time-out period to elapse if the receiving thread appears to not respond or "hangs." |
| **SMTO_BLOCK**<br><br>0x0001 | Prevents the calling thread from processing any other requests until the function returns. |
| **SMTO_NORMAL**<br><br>0x0000 | The calling thread is not prevented from processing other requests while waiting for the function to return. |
| **SMTO_NOTIMEOUTIFNOTHUNG**<br><br>0x0008 | The function does not enforce the time-out period as long as the receiving thread is processing messages. |
| **SMTO_ERRORONEXIT**<br><br>0x0020 | The function should return 0 if the receiving window is destroyed or its owning thread dies while the message is being processed. |

### `uTimeout` [in]

Type: **UINT**

The duration of the time-out period, in milliseconds. If the message is a broadcast message, each window can use the full time-out period. For example, if you specify a five second time-out period and there are three top-level windows that fail to process the message, you could have up to a 15 second delay.

### `lpdwResult` [out, optional]

Type: **PDWORD_PTR**

The result of the message processing. The value of this parameter depends on the message that is specified.

## Return value

Type: **LRESULT**

If the function succeeds, the return value is nonzero. **SendMessageTimeout** does not provide information about individual windows timing out if **HWND_BROADCAST** is used.

If the function fails or times out, the return value is 0.
Note that the function does not always call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror)
on failure.
If the reason for failure is important to you, call SetLastError(ERROR_SUCCESS)
before calling SendMessageTimeout. If the function returns 0, and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
returns ERROR_SUCCESS, then treat it as a generic failure.

## Remarks

The function calls the window procedure for the specified window and, if the specified window belongs to a different thread, does not return until the window procedure has processed the message or the specified time-out period has elapsed. If the window receiving the message belongs to the same queue as the current thread, the window procedure is called directly—the time-out value is ignored.

This function considers that a thread is not responding if it has not called [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or a similar function within five seconds.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

> [!NOTE]
> The winuser.h header defines SendMessageTimeout as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[InSendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**

[SendDlgItemMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-senddlgitemmessagea)

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)