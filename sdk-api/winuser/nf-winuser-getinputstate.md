# GetInputState function

## Description

Determines whether there are mouse-button or keyboard messages in the calling thread's message queue.

## Return value

Type: **BOOL**

If the queue contains one or more new mouse-button or keyboard messages, the return value is nonzero.

If there are no new mouse-button or keyboard messages in the queue, the return value is zero.

## See also

**Conceptual**

[GetQueueStatus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getqueuestatus)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**