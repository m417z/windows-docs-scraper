# WsCreateMessageForChannel function

## Description

Creates a [message](https://learn.microsoft.com/windows/desktop/wsw/message) for use with a specified [channel](https://learn.microsoft.com/windows/desktop/wsw/channel).

## Parameters

### `channel` [in]

Pointer to a [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) structure representing the channel for the message.

### `properties`

An array of optional properties for the message. See [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property).

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `message`

On success, a pointer that receives the address of the [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure representing the new message.

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

In contrast to the more general [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) function, **WsCreateMessageForChannel** ensures that
the message version used is appropriate for the channel.