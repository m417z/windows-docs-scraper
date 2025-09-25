# WS_CREATE_DECODER_CALLBACK callback function

## Description

Handles creating a decoder instance.

## Parameters

### `createContext` [in]

The createContext that was specified in the [WS_CHANNEL_DECODER](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_decoder) used during channel creation.

### `readCallback` [in]

The function that should be used to read the message data. This callback
should only be used in response to the [WS_DECODER_START_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_start_callback),
[WS_DECODER_DECODE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_decode_callback) and [WS_DECODER_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_end_callback)
callbacks.

### `readContext` [in]

The read context that should be passed to the provided [WS_READ_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_callback).

#### - **decoderContext

Returns the decoder instance. This value will be
passed to all of the decoder callbacks.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

### `decoderContext`

Returns the decoder instance. This value will be
passed to all of the decoder callbacks.

## Return value

This callback function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The channel will create decoder instances as necessary. Each decoder
instance will be called in a single-threaded fashion. A single decoder
instance however should not assume that it will see all messages from a
channel, as the channel may use multiple decoder instances for processing
messages.