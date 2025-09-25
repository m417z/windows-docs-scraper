# SendMessageCallbackW function

## Description

Sends the specified message to a window or windows. It calls the window procedure for the specified window and returns immediately if the window belongs to another thread. After the window procedure processes the message, the system calls the specified callback function, passing the result of the message processing and an application-defined value to the callback function.

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

### `lpResultCallBack` [in]

Type: **SENDASYNCPROC**

A pointer to a callback function that the system calls after the window procedure processes the message. For more information, see [SendAsyncProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-sendasyncproc).

If *hWnd* is **HWND_BROADCAST** ((HWND)0xffff), the system calls the [SendAsyncProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-sendasyncproc) callback function once for each top-level window.

### `dwData` [in]

Type: **ULONG_PTR**

An application-defined value to be sent to the callback function pointed to by the *lpCallBack* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the target window belongs to the same thread as the caller, then the window procedure is called synchronously, and the callback function is called immediately after the window procedure returns. If the target window belongs to a different thread from the caller, then the callback function is called only when the thread that called **SendMessageCallback** also calls [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage), [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), or [WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage).

If you send a message in the range below [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user) to the asynchronous message functions ([PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea), [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea), and **SendMessageCallback**), its message parameters cannot include pointers. Otherwise, the operation will fail. The functions will return before the receiving thread has had a chance to process the message and the sender will free the memory before it is used.

Applications that need to communicate using **HWND_BROADCAST** should use the [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) function to obtain a unique message for inter-application communication.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

> [!NOTE]
> The winuser.h header defines SendMessageCallback as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**

[RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)

[SendAsyncProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-sendasyncproc)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)