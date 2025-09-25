# WS_DECODER_DECODE_CALLBACK callback function

## Description

Decodes a message.

## Parameters

### `encoderContext` [in]

The decoder instance returned by the [WS_CREATE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_decoder_callback).

### `buffer`

The buffer to read into.

### `maxLength` [in]

The maximum number of bytes to read.

### `length` [out]

The number of bytes read should be returned here.

The number of bytes should be set to 0 when there are no more bytes left. This indicates
the end of the decoded message data, and will cause [WS_DECODER_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_end_callback) to
be invoked.

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