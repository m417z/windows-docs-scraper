# WS_CHANNEL_DECODER structure

## Description

A structure that is used to specify a set of callbacks
that can transform the content type and encoded bytes of a received message.

## Members

### `createContext`

A context that will be passed to the [WS_CREATE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_decoder_callback).

### `createDecoderCallback`

A [WS_CREATE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_decoder_callback) callback that creates an instance of a decoder.

### `decoderGetContentTypeCallback`

A [WS_DECODER_GET_CONTENT_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_get_content_type_callback) callback that is invoked to get the content type of the message.

### `decoderStartCallback`

A
[WS_DECODER_START_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_start_callback) callback that is invoked at the start of decoding a message.

### `decoderDecodeCallback`

A [WS_DECODER_DECODE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_decode_callback) callback that is invoked to decode a message.

### `decoderEndCallback`

A [WS_DECODER_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_end_callback) callback that is invoked at the end of decoding a message.

### `freeDecoderCallback`

A [WS_FREE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_decoder_callback) callback that frees an instance of a decoder.

## Remarks

A [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) may wish to decompress, modify, or otherwise transform
the encoded bytes of a message as soon as they are received. A **WS_CHANNEL_DECODER**
provides the necessary hooks to intercept and perform these modifications.

When creating the channel, the [WS_CHANNEL_PROPERTY_DECODER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) should be
set with the appropriate functions.

The callbacks specified will get invoked according to the following grammar:

``` syntax

decodercalls := create decoderloop* free
decoderloop  := decodestart
             |  decodestart getcontenttype
             |  decodestart getcontenttype (decode*)
             |  decodestart getcontenttype (decode*) decodeend
```

The decoder may not see the full decode sequence for a message if the channel
or the decoder encounters an error while reading the message. A decoder must be
prepared to handle transitioning to the appropriate state based upon the callbacks invoked.

When using [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type), the content type
is fixed for the channel. In this case, the [WS_DECODER_GET_CONTENT_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_get_content_type_callback) must return
exactly the same value for the content type of every message.

The [WS_DECODER_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_end_callback) will not be invoked until [WS_DECODER_DECODE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_decoder_decode_callback) returns 0 bytes.

When the channel is finished using the decoder instance it will free it via the
[WS_FREE_DECODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_decoder_callback).