# GetMessageExtraInfo function

## Description

Retrieves the extra message information for the current thread. Extra message information is an application- or driver-defined value associated with the current thread's message queue.

## Return value

Type: **LPARAM**

The return value specifies the extra information. The meaning of the extra information is device specific.

## Remarks

To set a thread's extra message information, use the [SetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmessageextrainfo) function.

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

**Reference**

[SetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmessageextrainfo)