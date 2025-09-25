# WsCreateMessage function

## Description

Creates a [message](https://learn.microsoft.com/windows/desktop/wsw/message) object with the specified properties.

## Parameters

### `envelopeVersion` [in]

A [WS_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version) enumeration value that specifies the version of the envelope for the message.

### `addressingVersion` [in]

A [WS_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) that specifies the version of the addressing for the message.

### `properties`

An array of optional properties for the message. See [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property).

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `message`

On success, a pointer that receives the address of a [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure representing the new message.

When you no longer need this structure, you must free it by calling [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

A message object is the delivery vehicle for Windows Web Services. A single message object can be used to send or receive sequential messages. Reusing a message object in this way can reduce memory allocations.
When you no longer need the message, you must free the memory by calling [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage). (For more information on reusing message objects, see [WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage) .)

If you are creating a message for use with a particular channel, use the [WsCreateMessageForChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessageforchannel) function, which will ensure the correct message version for the channel.