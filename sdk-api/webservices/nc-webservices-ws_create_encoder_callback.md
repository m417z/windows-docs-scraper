# WS_CREATE_ENCODER_CALLBACK callback function

## Description

Handles creating an encoder instance.

## Parameters

### `createContext` [in]

The createContext that was specified in the [WS_CHANNEL_ENCODER](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_encoder) used during channel creation.

### `writeCallback` [in]

The function that should be used to write the message data. This callback
should only be used in response to the [WS_ENCODER_START_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_start_callback),
[WS_ENCODER_ENCODE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_encode_callback) and [WS_ENCODER_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_end_callback) callbacks.

### `writeContext` [in]

The write context that should be passed to the provided [WS_WRITE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback).

#### - **encoderContext

Returns the encoder instance. This value will be
passed to all of the encoder callbacks.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

### `encoderContext`

Returns the encoder instance. This value will be
passed to all of the encoder callbacks.

## Return value

This callback function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The channel will create encoder instances as necessary. Each encoder
instance will be called in a single-threaded fashion. A single encoder
instance however should not assume that it will see all messages from a
channel, as the channel may use multiple encoder instances for processing
messages.