# SENDASYNCPROC callback function

## Description

An application-defined callback function used with the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function. The system passes the message to the callback function after passing the message to the destination window procedure. The **SENDASYNCPROC** type defines a pointer to this callback function. _SendAsyncProc_ is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **HWND**

A handle to the window whose window procedure received the message. This parameter is typically named _hWnd_.

If the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function was called with its _hWnd_ parameter set to **HWND_BROADCAST**, the system calls the _SendAsyncProc_ function once for each top-level window.

### `unnamedParam2`

Type: **UINT**

The message. This parameter is typically named _uMsg_.

### `unnamedParam3`

Type: **ULONG_PTR**

An application-defined value sent from the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function. This parameter is typically named _dwData_.

### `unnamedParam4`

Type: **LRESULT**

The result of the message processing. This value depends on the message. This parameter is typically named _lResult_.

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef VOID (CALLBACK* SENDASYNCPROC)(HWND, UINT, ULONG_PTR, LRESULT);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam4`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions.

You install a _SendAsyncProc_ application-defined callback function by passing a **SENDASYNCPROC** pointer to the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function.

The callback function is only called when the thread that called [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) calls [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage), [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), or [WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage).

## See also

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage)