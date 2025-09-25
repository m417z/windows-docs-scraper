# WsReadEnvelopeStart function

## Description

Reads the headers of the message and prepare to read the body elements.
The operation reads the start of the next message from the Reader including the headers of
the message.
The process allows for reading of messages from other sources than channels. To read
a message using a channel, use [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart).

**Note** On success the headers is stored in the message and can be retrieved randomly
using functions such as [WsGetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheader) or [WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader).

## Parameters

### `message` [in]

A pointer to the **Message** object to read. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object.

### `reader` [in]

A pointer to the Reader with the message to read. The Message object uses the Reader in the current and subsequent
calls.

**Note** The function caller must keep the Reader valid until
[WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage) or [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage) is called.
The [WS_MESSAGE_DONE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_message_done_callback) parameter can be used a way to know
that the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) is no longer in use.

### `doneCallback` [in, optional]

Identifies the callback function to initiate on success of the current operation once the message has
been released.

**Note** Messages are released using [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage) or [WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage)

The callback
can be used to discover whether the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) instance is in use by this message. If the current operation fails the callback is not called.

### `doneCallbackState` [in, optional]

A pointer to user-defined state that can be passed
to the [WS_MESSAGE_DONE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_message_done_callback).
This parameter may be **NULL** if the callback is not used.

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

The message must be in **WS_MESSAGE_STATE_EMPTY** state. On success
the message state is set to **WS_MESSAGE_STATE_READING**.

To read an Element of the message body, use [WsReadBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbody). To read
directly from the XML Reader get the Reader with
the **message property Id** set to **WS_MESSAGE_PROPERTY_BODY_READER**.