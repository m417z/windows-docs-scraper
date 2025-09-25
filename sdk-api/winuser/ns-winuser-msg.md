# MSG structure

## Description

Contains message information from a thread's message queue.

## Members

### `hwnd`

Type: **HWND**

A handle to the window whose window procedure receives the message. This member is **NULL** when the message is a thread message.

### `message`

Type: **UINT**

The message identifier. Applications can only use the low word; the high word is reserved by the system.

### `wParam`

Type: **WPARAM**

Additional information about the message. The exact meaning depends on the value of the
**message** member.

### `lParam`

Type: **LPARAM**

Additional information about the message. The exact meaning depends on the value of the
**message** member.

### `time`

Type: **DWORD**

The time at which the message was posted.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The cursor position, in screen coordinates, when the message was posted.

### `lPrivate`

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea)

**Reference**