# PostQuitMessage function

## Description

Indicates to the system that a thread has made a request to terminate (quit). It is typically used in response to a [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy) message.

## Parameters

### `nExitCode` [in]

Type: **int**

The application exit code. This value is used as the *wParam* parameter of the [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message.

## Remarks

The **PostQuitMessage** function posts a [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message to the thread's message queue and returns immediately; the function simply indicates to the system that the thread is requesting to quit at some time in the future.

When the thread retrieves the [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message from its message queue, it should exit its message loop and return control to the system. The exit value returned to the system must be the *wParam* parameter of the **WM_QUIT** message.

#### Examples

For an example, see [Posting a Message](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**

[WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy)

[WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit)