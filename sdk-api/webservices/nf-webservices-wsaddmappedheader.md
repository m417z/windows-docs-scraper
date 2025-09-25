# WsAddMappedHeader function

## Description

Adds a specified mapped header to the [message](https://learn.microsoft.com/windows/desktop/wsw/message).

## Parameters

### `message` [in]

Pointer to a [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure representing the [message](https://learn.microsoft.com/windows/desktop/wsw/message) to which to add the mapped header.

The message can be in any state except **WS_MESSAGE_STATE_EMPTY** (see the [WS_MESSAGE_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) enumeration.

### `headerName` [in]

Pointer to a [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) containing the name of the header.

### `valueType` [in]

The type of header value to deserialize. For possible types and the corresponding headers, see the [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type)

### `writeOption` [in]

Whether the header is required, and how the value is allocated.
For more information, see the [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) enumeration.

### `value` [in]

The header value to serialize. For more information, see the [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) enumeration.

### `valueSize` [in]

The size of the value being serialized, in bytes.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

A message may contain additional transport-specific information that is
not part of the message envelope. This transport-specific information
can be exposed programmatically as headers of the message.
The **WsAddMappedHeader** function is used to add such a header that will be mapped into some
transport-specific location.

When you use the HTTP channel, you must specify the required mappings before before you call this function to add the headers. For more information, see [WS_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_message_mapping).

If you are replacing a header, call the [WsRemoveMappedHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsremovemappedheader) function to remove
the existing instances of the header before you call **WsAddMappedHeader**.