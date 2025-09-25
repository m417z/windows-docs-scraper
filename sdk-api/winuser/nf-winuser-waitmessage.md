# WaitMessage function

## Description

Blocks thread execution until the thread needs to process a new message.
The new message could be an input message, a queued message, or a non-queued message.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Note that **WaitMessage** does not return for unprocessed messages reported by a previous function which checks the queue. This is because functions such as [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage), [GetQueueStatus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getqueuestatus), **WaitMessage**, [MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects), and [MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex) check the queue and then change the state information for the queue so that the message is no longer considered new. A subsequent call to **WaitMessage** will not return until new messages arrive. The existing unprocessed messages (received prior to the last time the thread checked the queue) are not considered to be new.

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

**Reference**