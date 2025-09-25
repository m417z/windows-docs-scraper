# WsSetHeader function

## Description

Adds or replaces the specified standard header in the message.

## Parameters

### `message` [in]

The message to set the header in.

The message can be in any state but [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `headerType` [in]

The type of header to serialize.

### `valueType` [in]

The type of the value to serialize. See [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) for
the set of types supported for each type of header.

### `writeOption` [in]

Whether the header element is required, and how the value is allocated.
[WS_WRITE_NILLABLE_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) and **WS_WRITE_NILLABLE_POINTER**
write options cannot be specified since the header types in [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type)
are not allowed to be nillable in the respective standards specifications.
See **WS_WRITE_OPTION** for more information.

### `value`

The header value to serialize. See [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) for
more information.

### `valueSize` [in]

The size of the value being serialized, in bytes.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | There are multiple instances of the type of header present in the message. |
| **E_OUTOFMEMORY** | There was not enough memory available to serialize the header. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This API allows setting of standard header types (see [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type)).
For application defined header types, use [WsAddCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddcustomheader).

This API is designed handle types of headers that appear once in the
message and are targeted at the ultimate receiver. Headers targeted
with a role/actor other than ultimate receiver are ignored by this API.

If a header of the given type (targeted at the ultimate receiver) already
exists in the message, it is replaced.