# PeekMessageW function

## Description

Dispatches incoming nonqueued messages, checks the thread message queue for a posted message, and retrieves the message (if any exist).

## Parameters

### `lpMsg` [out]

Type: **LPMSG**

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that receives message information.

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window whose messages are to be retrieved. The window must belong to the current thread.

If *hWnd* is **NULL**, **PeekMessage** retrieves messages for any window that belongs to the current thread, and any messages on the current thread's message queue whose **hwnd** value is **NULL** (see the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure). Therefore if hWnd is **NULL**, both window messages and thread messages are processed.

 If *hWnd* is -1, **PeekMessage** retrieves only messages on the current thread's message queue whose **hwnd** value is **NULL**, that is, thread messages as posted by [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) (when the *hWnd* parameter is **NULL**) or [PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea).

### `wMsgFilterMin` [in]

Type: **UINT**

The value of the first message in the range of messages to be examined. Use **WM_KEYFIRST** (0x0100) to specify the first keyboard message or **WM_MOUSEFIRST** (0x0200) to specify the first mouse message.

If *wMsgFilterMin* and *wMsgFilterMax* are both zero, **PeekMessage** returns all available messages (that is, no range filtering is performed).

### `wMsgFilterMax` [in]

Type: **UINT**

The value of the last message in the range of messages to be examined. Use **WM_KEYLAST** to specify the last keyboard message or **WM_MOUSELAST** to specify the last mouse message.

If *wMsgFilterMin* and *wMsgFilterMax* are both zero, **PeekMessage** returns all available messages (that is, no range filtering is performed).

### `wRemoveMsg` [in]

Type: **UINT**

Specifies how messages are to be handled. This parameter can be one or more of the following values.

| Value | Meaning |
|-------|---------|
| **PM\_NOREMOVE**<br>`0x0000` | Messages are not removed from the queue after processing by **PeekMessage**. |
| **PM\_REMOVE**<br>`0x0001` | Messages are removed from the queue after processing by **PeekMessage**. |
| **PM\_NOYIELD**<br>`0x0002` | Prevents the system from releasing any thread that is waiting for the caller to go idle (see [WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle)). Combine this value with either **PM\_NOREMOVE** or **PM\_REMOVE**. |

By default, all message types are processed. To specify that only certain message should be processed, specify one or more of the following values.

| Value | Meaning |
|-------|---------|
| **PM\_QS\_INPUT**<br>`(QS_INPUT << 16)` | Process mouse and keyboard messages. |
| **PM\_QS\_POSTMESSAGE**<br>`((QS_POSTMESSAGE \| QS_HOTKEY \| QS_TIMER) << 16)` | Process all posted messages, including timers and hotkeys. |
| **PM\_QS\_PAINT**<br>`(QS_PAINT << 16)` | Process paint messages. |
| **PM\_QS\_SENDMESSAGE**<br>`(QS_SENDMESSAGE << 16)` | Process all sent messages. |

For more info on listed `QS_` flags and types of messages see [GetQueueStatus](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getqueuestatus) documentation.

## Return value

Type: **BOOL**

If a message is available, the return value is nonzero.

If no messages are available, the return value is zero.

## Remarks

**PeekMessage** retrieves messages associated with the window identified by the *hWnd* parameter or any of its children as specified by the [IsChild](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ischild) function, and within the range of message values given by the *wMsgFilterMin* and *wMsgFilterMax* parameters. Note that an application can only use the low word in the *wMsgFilterMin* and *wMsgFilterMax* parameters; the high word is reserved for the system.

Note that **PeekMessage** always retrieves [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) messages, no matter which values you specify for *wMsgFilterMin* and *wMsgFilterMax*.

During this call, the system dispatches ([DispatchMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-dispatchmessage)) pending, nonqueued messages, that is, messages sent to windows owned by the calling thread using the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage), [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka), [SendMessageTimeout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagetimeouta), or [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea) function. Then the first queued message that matches the specified filter is retrieved. The system may also process internal events. If no filter is specified, messages are processed in the following order:

* Sent messages
* Posted messages
* Input (hardware) messages and system internal events
* Sent messages (again)
* [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages
* [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages

To retrieve input messages before posted messages, use the *wMsgFilterMin* and *wMsgFilterMax* parameters.

The **PeekMessage** function normally does not remove [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages from the queue. **WM_PAINT** messages remain in the queue until they are processed. However, if a **WM_PAINT** message has a **NULL** update region, **PeekMessage** does remove it from the queue.

 If a top-level window stops responding to messages for more than several seconds, the system considers the window to be not responding and replaces it with a ghost window that has the same z-order, location, size, and visual attributes. This allows the user to move it, resize it, or even close the application. However, these are the only actions available because the application is actually not responding. When an application is being debugged, the system does not generate a ghost window.

### DPI Virtualization

This API does not participate in DPI virtualization. The output is in the mode of the window that the message is targeting. The calling thread is not taken into consideration.

#### Examples

For an example, see [Examining a Message Queue](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

> [!NOTE]
> The winuser.h header defines PeekMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[IsChild](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ischild)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Other Resources**

**Reference**

[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle)

[WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage)