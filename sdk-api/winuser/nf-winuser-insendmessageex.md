# InSendMessageEx function

## Description

Determines whether the current window procedure is processing a message that was sent from another thread (in the same process or a different process).

## Parameters

### `lpReserved`

Type: **LPVOID**

Reserved; must be **NULL**.

## Return value

Type: **DWORD**

If the message was not sent, the return value is **ISMEX_NOSEND** (0x00000000). Otherwise, the return value is one or more of the following values.

| Return code/value | Description |
| --- | --- |
| **ISMEX_CALLBACK**<br><br>0x00000004 | The message was sent using the [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka) function. The thread that sent the message is not blocked. |
| **ISMEX_NOTIFY**<br><br>0x00000002 | The message was sent using the [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea) function. The thread that sent the message is not blocked. |
| **ISMEX_REPLIED**<br><br>0x00000008 | The window procedure has processed the message. The thread that sent the message is no longer blocked. |
| **ISMEX_SEND**<br><br>0x00000001 | The message was sent using the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) or [SendMessageTimeout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagetimeouta) function. If **ISMEX_REPLIED** is not set, the thread that sent the message is blocked. |

## Remarks

To determine if the sender is blocked, use the following test:

`fBlocked = ( InSendMessageEx(NULL) & (ISMEX_REPLIED|ISMEX_SEND) ) == ISMEX_SEND;`

## See also

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[SendMessageTimeout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagetimeouta)

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)