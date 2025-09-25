# SendMessageW function

## Description

Sends the specified message to a window or windows. The **SendMessage** function calls the window procedure for the specified window and does not return until the window procedure has processed the message.

To send a message and return immediately, use the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) or [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea) function. To post a message to a thread's message queue and return immediately, use the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) or [PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose window procedure will receive the message. If this parameter is **HWND_BROADCAST** ((HWND)0xffff), the message is sent to all top-level windows in the system, including disabled or invisible unowned windows, overlapped windows, and pop-up windows; but the message is not sent to child windows.

 Message sending is subject to UIPI. The thread of a process can send messages only to message queues of threads in processes of lesser or equal integrity level.

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

Type: **LRESULT**

The return value specifies the result of the message processing; it depends on the message sent.

## Remarks

 When a message is blocked by UIPI the last error, retrieved with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), is set to 5 (access denied).

Applications that need to communicate using **HWND_BROADCAST** should use the [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) function to obtain a unique message for inter-application communication.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

If the specified window was created by the calling thread, the window procedure is called immediately as a subroutine. If the specified window was created by a different thread, the system switches to that thread and calls the appropriate window procedure. Messages sent between threads are processed only when the receiving thread executes message retrieval code. The sending thread is blocked until the receiving thread processes the message. However, the sending thread will process incoming nonqueued messages while waiting for its message to be processed. To prevent this, use [SendMessageTimeout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagetimeouta) with SMTO_BLOCK set. For more information on nonqueued messages, see [Nonqueued Messages](https://learn.microsoft.com/windows/desktop/winmsg/about-messages-and-message-queues).

 An accessibility application can use **SendMessage** to send [WM_APPCOMMAND](https://learn.microsoft.com/windows/desktop/inputdev/wm-appcommand) messages to the shell to launch applications. This functionality is not guaranteed to work for other types of applications.

#### Examples

For an example, see [Displaying Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/using-keyboard-input).

> [!NOTE]
> The winuser.h header defines SendMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[InSendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

[PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea)

**Reference**

[RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)

[SendDlgItemMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-senddlgitemmessagea)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[SendMessageTimeout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagetimeouta)

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)