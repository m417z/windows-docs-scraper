# GetMessageTime function

## Description

Retrieves the message time for the last message retrieved by the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) function. The time is a long integer that specifies the elapsed time, in milliseconds, from the time the system was started to the time the message was created (that is, placed in the thread's message queue).

## Return value

Type: **LONG**

The return value specifies the message time.

## Remarks

The return value from the **GetMessageTime** function does not necessarily increase between subsequent messages, because the value wraps to the minimum value for a long integer if the timer count exceeds the maximum value for a long integer.

To calculate time delays between messages, subtract the time of the first message from the time of the second message (ignoring overflow) and compare the result of the subtraction against the desired delay amount.

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[GetMessagePos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessagepos)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**