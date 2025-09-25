# WS_ENCODER_START_CALLBACK callback function

## Description

Starts encoding a message.

## Parameters

### `encoderContext` [in]

The encoder instance returned by the [WS_CREATE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_encoder_callback).

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

The encoder can use the callback passed to [WS_CREATE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_encoder_callback) to
write the encoded data of the message.