# WsResetMessage function

## Description

Sets the Message state back to **WS_MESSAGE_STATE_EMPTY**. In this state the Message object can be reused.

## Parameters

### `message` [in]

A pointer to the Message object to reset.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

When a message is reset, its underlying heap is reset.

Reusing a message object to receive or send multiple messages is generally
more efficient than creating and freeing the message object for each message.