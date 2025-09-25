# SendNotifyMessageA function

## Description

Sends the specified message to a window or windows. If the window was created by the calling thread, **SendNotifyMessage** calls the window procedure for the window and does not return until the window procedure has processed the message. If the window was created by a different thread, **SendNotifyMessage** passes the message to the window procedure and returns immediately; it does not wait for the window procedure to finish processing the message.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose window procedure will receive the message. If this parameter is **HWND_BROADCAST** ((HWND)0xffff), the message is sent to all top-level windows in the system, including disabled or invisible unowned windows, overlapped windows, and pop-up windows; but the message is not sent to child windows.

### `Msg` [in]

Type: **UINT**

The message to be sent.

For lists of the system-provided messages, see [System-Defined Messages](https://learn.microsoft.com/windows/desktop/winmsg/about-messages-and-message-queues).

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you send a message in the range below [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user) to the asynchronous message functions ([PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea), **SendNotifyMessage**, and [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)), its message parameters cannot include pointers. Otherwise, the operation will fail. The functions will return before the receiving thread has had a chance to process the message and the sender will free the memory before it is used.

Applications that need to communicate using **HWND_BROADCAST** should use the [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) function to obtain a unique message for inter-application communication.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

> [!NOTE]
> The winuser.h header defines SendNotifyMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

[PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea)

**Reference**

[RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)