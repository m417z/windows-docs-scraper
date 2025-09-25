# WS_DECODER_END_CALLBACK callback function

## Description

Decodes the end of a message.

## Parameters

### `encoderContext` [in]

The decoder instance returned by the [WS_CREATE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_decoder_callback).

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The decoder can use the callback passed to [WS_CREATE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_decoder_callback) to
read the encoded data of the message.

This callback is not invoked until [WS_DECODER_DECODE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_decode_callback) returns 0 bytes.