# WS_CHANNEL_ENCODER structure

## Description

A structure that is used to specify a set of callbacks
that can transform the content type and encoded bytes of a sent message.

## Members

### `createContext`

A context that will be passed to the [WS_CREATE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_encoder_callback).

### `createEncoderCallback`

A [WS_CREATE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_encoder_callback) callback that creates an instance of an encoder.

### `encoderGetContentTypeCallback`

A [WS_ENCODER_GET_CONTENT_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_get_content_type_callback) callback that is invoked when a message is to be encoded.

### `encoderStartCallback`

A [WS_ENCODER_START_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_start_callback) callback that is invoked to start encoding a message.

### `encoderEncodeCallback`

A
[WS_ENCODER_ENCODE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_encode_callback) callback that is invoked to encode a message.

### `encoderEndCallback`

A [WS_ENCODER_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_end_callback) callback that is invoked to at the end of encoding a message.

### `freeEncoderCallback`

A [WS_FREE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_encoder_callback) callback that frees an instance of an encoder.

## Remarks

A [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) may wish to compress, modify, or otherwise transform
the encoded bytes of a message before they are sent. A **WS_CHANNEL_ENCODER**
provides the necessary hooks to intercept and perform these modifications.

When creating the channel, the [WS_CHANNEL_PROPERTY_ENCODER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) should be
set with the appropriate functions.

The grammar for the encoder callbacks is:

``` syntax

encodercalls := create encoderloop* free
encoderloop  := getcontenttype
             |  getcontenttype encodestart
             |  getcontenttype encodestart (encode*)
             |  getcontenttype encodestart (encode*) encodeend

```

The encoder may not see the full encode sequence for a message if the channel or the
encoder encounters an error while writing the message. An encoder must be prepared to
handle transitioning to the appropriate state based upon the callbacks invoked.

When using [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type), the content type
is fixed for the channel. In this case, the [WS_ENCODER_GET_CONTENT_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_encoder_get_content_type_callback) must return
exactly the same value for the content type of every message.

When the channel is finished using the encoder instance it will free it via the
[WS_FREE_ENCODER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_encoder_callback).