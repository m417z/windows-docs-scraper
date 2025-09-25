# SENDASYNCPROC callback function

## Description

An application-defined callback function used with the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function. The system passes the message to the callback function after passing the message to the destination window procedure. The **SENDASYNCPROC** type defines a pointer to this callback function. *SendAsyncProc* is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **HWND**

A handle to the window whose window procedure received the message.

If the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function was called with its *hwnd* parameter set to **HWND_BROADCAST**, the system calls the *SendAsyncProc* function once for each top-level window.

### `unnamedParam2`

Type: **UINT**

The message.

### `unnamedParam3`

Type: **ULONG_PTR**

An application-defined value sent from the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function.

### `unnamedParam4`

Type: **LRESULT**

The result of the message processing. This value depends on the message.

## Remarks

You install a *SendAsyncProc* application-defined callback function by passing a **SENDASYNCPROC** pointer to the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function.

The callback function is only called when the thread that called [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) calls [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage), [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), or [WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage).

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

**Reference**

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage)