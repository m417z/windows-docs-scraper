# WS_DECODER_GET_CONTENT_TYPE_CALLBACK callback function

## Description

Gets the content type of the message.

## Parameters

### `decoderContext` [in]

The encoder instance returned by the [WS_CREATE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_decoder_callback).

### `contentType` [in]

The content type of the encoded message.

### `contentEncoding` [in, optional]

The content encoding for the encoded message.

### `newContentType` [out]

The callback should return the content type for the newly decoded message here.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The callback should verify that the content type provided matches what is expected,
and then should return the content type of the decoded message.

The content type returned must remain valid until the next time the callback is
invoked, or the decoder is freed.

The callback has to set newContentType to one that is supported by underlying channel.
For example, with TCP session channel using SOAP 1.2 and binary encoding,
the new content type should always be application/soap+msbinsession1.

For [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) the content encoding parameter will
be set to the value of the "Content-Encoding" HTTP header. If this header does
not exist, then **NULL** will be passed.

For all other channel bindings, **NULL** will be passed for the content encoding.