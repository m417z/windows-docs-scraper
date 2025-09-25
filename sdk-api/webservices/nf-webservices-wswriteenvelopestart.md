# WsWriteEnvelopeStart function

## Description

Writes the start of the message including the current set of headers of the message and prepares to write the body elements.

This function is designed for writing messages to destinations other than channels. To write a message to a channel use [WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart).

## Parameters

### `message` [in]

A pointer to the **Message** object to write. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object.

### `writer` [in]

A pointer to the **XML Writer** object to write the Message. The Message object uses the Writer in subsequent calls to write the message. The caller must keep the writer valid until [WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage) or [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage) is called.
The [WS_MESSAGE_DONE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_message_done_callback) parameter can be used to determine that the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) is no longer in use.

### `doneCallback` [in, optional]

The callback function invoked when the Message is released or reset. This callback can be used to indicate that the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object is no longer
in use by this message. If this function fails the callback is not called. If the function succeeds the callback is invoked one time only.

### `doneCallbackState` [in, optional]

A void pointer to a user-defined state that will be passed to the specified callback. This parameter may be **NULL**.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The start of the message, including the current set of headers that exist in the message,
are written to the writer.

The message state must be set to **WS_MESSAGE_STATE_INITIALIZED**. On success
the Message state transitions to **WS_MESSAGE_STATE_WRITING**.
On failure state transition does not occur.

To write an element of the message body use [WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody). To write
directly to the Writer of the Message obtain the Reader with the [WS_MESSAGE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id) set to **WS_MESSAGE_PROPERTY_BODY_WRITER** property.