# WsGetMappedHeader function

## Description

Finds a mapped header in the message and deserializes it.

## Parameters

### `message` [in]

The message containing the header.

The message can be in any state but [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `headerName` [in]

The name of the mapped header.

### `repeatingOption` [in]

Whether the header may appear more than once in
the message.

If [WS_REPEATING_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_repeating_header_option) is used, then
the header index indicates which of the headers
with the specified headerName to return.

If [WS_SINGLETON_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_repeating_header_option) is used, then
the headerIndex must be zero.

### `headerIndex` [in]

The zero-based index of the header within
the set of headers with the specified headerName.

### `valueType` [in]

The type of value to deserialize.

### `readOption` [in]

Whether the value is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

If the header is optional (may appear zero or one times), then
[WS_READ_OPTIONAL_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) can be used.

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
| **WS_E_INVALID_FORMAT** | The header does not exist, and is required.<br><br>The input data was not in the expected format.<br><br>[WS_SINGLETON_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_repeating_header_option) was specified, and there are multiple instances of the header with the specified name in the message. |
| **WS_E_QUOTA_EXCEEDED** | The size quota of the heap was exceeded. |
| **E_OUTOFMEMORY** | There was not enough memory available to deserialize the header. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

A message may contain additional transport-specific information that is
not part of the message envelope. This transport-specific information
can be exposed programmatically as headers of the Message object.
This function is used to read a header that has been mapped by a
transport into the message.

When using the HTTP channel, the required mappings must be specified before headers
can be extracted with this function. For more information, see [WS_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_message_mapping).