# WS_ENCODER_GET_CONTENT_TYPE_CALLBACK callback function

## Description

Gets the content type of the message.

## Parameters

### `encoderContext` [in]

The encoder instance returned by the [WS_CREATE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_encoder_callback).

### `contentType` [in]

The content type of the encoded message.

### `newContentType` [out]

The callback should return the content type for the newly encoded message here.

### `contentEncoding` [out]

The callback should return the content encoding for the encoded message here.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The callback may inspect the content type provided, and then should return the
content type to use for the encoded message.

The content type and content encoding returned must remain valid until the
callback is invoked again, or the encoder is freed.

For [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), if a non-zero length content encoding
is returned, the HTTP header "Content-Encoding" will be added to the message
with this value.

For other channel bindings, it is an error to return a non-zero length
content encoding.