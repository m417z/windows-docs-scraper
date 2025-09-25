# GetMessageW function

## Description

Retrieves a message from the calling thread's message queue. The function dispatches incoming sent messages until a posted message is available for retrieval.

Unlike **GetMessage**, the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function does not wait for a message to be posted before returning.

## Parameters

### `lpMsg` [out]

Type: **LPMSG**

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that receives message information from the thread's message queue.

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window whose messages are to be retrieved. The window must belong to the current thread.

If *hWnd* is **NULL**, **GetMessage** retrieves messages for any window that belongs to the current thread, and any messages on the current thread's message queue whose **hwnd** value is **NULL** (see the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure). Therefore if hWnd is **NULL**, both window messages and thread messages are processed.

 If *hWnd* is -1, **GetMessage** retrieves only messages on the current thread's message queue whose **hwnd** value is **NULL**, that is, thread messages as posted by [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) (when the *hWnd* parameter is **NULL**) or [PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea).

### `wMsgFilterMin` [in]

Type: **UINT**

The integer value of the lowest message value to be retrieved. Use **WM_KEYFIRST** (0x0100) to specify the first keyboard message or **WM_MOUSEFIRST** (0x0200) to specify the first mouse message.

Use [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input) here and in *wMsgFilterMax* to specify only the **WM_INPUT** messages.

If *wMsgFilterMin* and *wMsgFilterMax* are both zero, **GetMessage** returns all available messages (that is, no range filtering is performed).

### `wMsgFilterMax` [in]

Type: **UINT**

The integer value of the highest message value to be retrieved. Use **WM_KEYLAST** to specify the last keyboard message or **WM_MOUSELAST** to specify the last mouse message.

Use [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input) here and in *wMsgFilterMin* to specify only the **WM_INPUT** messages.

If *wMsgFilterMin* and *wMsgFilterMax* are both zero, **GetMessage** returns all available messages (that is, no range filtering is performed).

## Return value

Type: **BOOL**

If the function retrieves a message other than [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit), the return value is nonzero.

If the function retrieves the [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message, the return value is zero.

If there is an error, the return value is -1. For example, the function fails if *hWnd* is an invalid window handle or *lpMsg* is an invalid pointer. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Because the return value can be nonzero, zero, or -1, avoid code like this:

```
while (GetMessage( lpMsg, hWnd, 0, 0)) ...
```

The possibility of a -1 return value in the case that hWnd is an invalid parameter (such as referring to a window that has already been destroyed) means that such code can lead to fatal application errors. Instead, use code like this:

```
BOOL bRet;

while( (bRet = GetMessage( &msg, hWnd, 0, 0 )) != 0)
{
    if (bRet == -1)
    {
        // handle the error and possibly exit
    }
    else
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
```

## Remarks

An application typically uses the return value to determine whether to end the main message loop and exit the program.

The **GetMessage** function retrieves messages associated with the window identified by the *hWnd* parameter or any of its children, as specified by the [IsChild](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ischild) function, and within the range of message values given by the *wMsgFilterMin* and *wMsgFilterMax* parameters. Note that an application can only use the low word in the *wMsgFilterMin* and *wMsgFilterMax* parameters; the high word is reserved for the system.

Note that **GetMessage** always retrieves [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) messages, no matter which values you specify for *wMsgFilterMin* and *wMsgFilterMax*.

During this call, the system delivers pending, nonqueued messages, that is, messages sent to windows owned by the calling thread using the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage), [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka), [SendMessageTimeout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagetimeouta), or [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea) function. Then the first queued message that matches the specified filter is retrieved. The system may also process internal events. If no filter is specified, messages are processed in the following order:

* Sent messages
* Posted messages
* Input (hardware) messages and system internal events
* Sent messages (again)
* [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages
* [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages

To retrieve input messages before posted messages, use the *wMsgFilterMin* and *wMsgFilterMax* parameters.

**GetMessage** does not remove [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages from the queue. The messages remain in the queue until processed.

If a top-level window stops responding to messages for more than several seconds, the system considers the window to be not responding and replaces it with a ghost window that has the same z-order, location, size, and visual attributes. This allows the user to move it, resize it, or even close the application. However, these are the only actions available because the application is actually not responding. When in the debugger mode, the system does not generate a ghost window.

### DPI Virtualization

This API does not participate in DPI virtualization. The output is in the mode of the window that the message is targeting. The calling thread is not taken into consideration.

#### Examples

For an example, see [Creating a Message Loop](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

> [!NOTE]
> The winuser.h header defines GetMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[IsChild](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ischild)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

[PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea)

**Reference**

[WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage)