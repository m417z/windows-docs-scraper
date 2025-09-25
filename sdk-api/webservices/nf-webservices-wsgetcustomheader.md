# WsGetCustomHeader function

## Description

Finds an application-defined header of the message and deserializes it.

## Parameters

### `message` [in]

The message containing the header.

The message can be in any state but [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `customHeaderDescription` [in]

A [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) which describes the header element.

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

### `readOption` [in]

Whether the value is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

### `heap` [in, optional]

The heap to store the deserialized header data in.
If this is **NULL**, then the message heap will be used
as required by the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `value`

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `valueSize` [in]

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `headerAttributes`

Returns the [WS_HEADER_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_text_type) for this header.
The pointer may be **NULL**, in which case no attributes are returned.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The header does not exist, and is required.<br><br>[WS_SINGLETON_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_repeating_header_option) was specified, and there are multiple instances of the type of header present in the message.<br><br>The input data was not in the expected format. |
| **WS_E_QUOTA_EXCEEDED** | The size quota of the heap was exceeded. |
| **E_OUTOFMEMORY** | There was not enough memory available to deserialize the header. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This API operates on headers targeted at the ultimate receiver.
Headers targeted with a role/actor other than ultimate receiver are
ignored by this API.