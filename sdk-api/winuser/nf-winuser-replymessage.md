# ReplyMessage function

## Description

Replies to a message sent from another thread by the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function.

## Parameters

### `lResult` [in]

Type: **LRESULT**

The result of the message processing. The possible values are based on the message sent.

## Return value

Type: **BOOL**

If the calling thread was processing a message sent from another thread or process, the return value is nonzero.

If the calling thread was not processing a message sent from another thread or process, the return value is zero.

## Remarks

By calling this function, the window procedure that receives the message allows the thread that called [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) to continue to run as though the thread receiving the message had returned control. The thread that calls the **ReplyMessage** function also continues to run.

If the message was not sent through [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) or if the message was sent by the same thread, **ReplyMessage** has no effect.

#### Examples

For an example, see [Sending a Message](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

## See also

**Conceptual**

[InSendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)