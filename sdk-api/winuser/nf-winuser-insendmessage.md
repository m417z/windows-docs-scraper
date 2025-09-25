# InSendMessage function

## Description

Determines whether the current window procedure is processing a message that was sent from another thread (in the same process or a different process) by a call to the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function.

To obtain additional information about how the message was sent, use the [InSendMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessageex) function.

## Return value

Type: **BOOL**

If the window procedure is processing a message sent to it from another thread using the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function, the return value is nonzero.

If the window procedure is not processing a message sent to it from another thread using the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function, the return value is zero.

## See also

**Conceptual**

[InSendMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessageex)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)