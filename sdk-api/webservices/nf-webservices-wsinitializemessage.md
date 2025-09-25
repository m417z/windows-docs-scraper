# WsInitializeMessage function

## Description

This function initializes the headers for the message in preparation for
processing.
After a message has been initialized an application can
add additional headers.
On success the message is in [WS_MESSAGE_STATE_INITIALIZED](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) state.
If the function fails, then no state transitions occurs.

## Parameters

### `message` [in]

A pointer to the Message object to initialize. The Message must be a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object instance returned
by [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) or [WsCreateMessageForChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessageforchannel) and may not be NULL.

### `initialization` [in]

Defines the Message initialization.

**Note** If the *initialization* value is set to **WS_REPLY_MESSAGE** or
**WS_FAULT_MESSAGE** the message is automatically addressed.

### `sourceMessage` [in, optional]

A pointer to a message object that is used to initialize the *message* parameter.
This value should be NULL unless the initialization parameter
has the value of **WS_DUPLICATE_MESSAGE**,
**WS_REPLY_MESSAGE**, or **WS_FAULT_MESSAGE**.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The initial sender of a message should add an action header
to the message using [WsSetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetheader).

This API must be called before [WsWriteEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteenvelopestart) or
[WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart) is called for the message.