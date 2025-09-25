# WsGetHeader function

## Description

Finds a particular standard header in the message and deserializes it.

## Parameters

### `message` [in]

The message containing the header.

The message can be in any state but [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `headerType` [in]

The type of header to deserialize.

### `valueType` [in]

The type of value to deserialize. See [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) for
the set of types which correspond to each type of header.

### `readOption` [in]

Whether the value is required, and how to allocate the value.
[WS_READ_NILLABLE_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) and **WS_READ_NILLABLE_POINTER**
read options cannot be specified since the header types in [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type)
are not allowed to be nillable in the respective standards specifications.
See **WS_READ_OPTION** for more information.

### `heap` [in, optional]

The heap to store the deserialized header data in.
If this is **NULL**, then the message heap will be used.

### `value`

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `valueSize` [in]

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The header does not exist, and is required.<br><br>There are multiple instances of the type of header present in the message.<br><br>The input data was not in the expected format. |
| **WS_E_QUOTA_EXCEEDED** | The size quota of the heap was exceeded. |
| **E_OUTOFMEMORY** | There was not enough memory available to deserialize the header. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This API provides access to a set of standard header types (see [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type)).
For application defined header types, use [WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader).

This API is designed handle types of headers that appear once in the
message and are targeted at the ultimate receiver. Headers targeted
with a role/actor other than ultimate receiver are ignored by this API.