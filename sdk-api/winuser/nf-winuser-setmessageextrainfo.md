# SetMessageExtraInfo function

## Description

Sets the extra message information for the current thread. Extra message information is an application- or driver-defined value associated with the current thread's message queue. An application can use the [GetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessageextrainfo) function to retrieve a thread's extra message information.

## Parameters

### `lParam` [in]

Type: **LPARAM**

The value to be associated with the current thread.

## Return value

Type: **LPARAM**

The return value is the previous value associated with the current thread.

## See also

**Conceptual**

[GetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessageextrainfo)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**