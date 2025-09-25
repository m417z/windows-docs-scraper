# WS_TRANSFER_MODE enumeration

## Description

Whether messages that are sent or received are streamed or buffered.

## Constants

### `WS_STREAMED_INPUT_TRANSFER_MODE:0x1`

Setting this flag means messages are delivered in chunks. The start of the message
(opening tag, headers, and opening body tag) will be returned to the application
when [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) completes. It is up to the application to call
[WsFillBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillbody) before reading each chunk of the message body. The end of
the message (closing body and envelope tags) will be read when [WsReadMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessageend) is called.

Not setting this flag means the entire message is read and buffered
in memory before [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) indicates completion.

### `WS_STREAMED_OUTPUT_TRANSFER_MODE:0x2`

Setting this flag means messages are transmitted in chunks. The start of the message (opening
envelope tag, headers, and opening body tag) will be transmitted when [WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart) is called. It is up to the application to call [WsFlushBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushbody) after writing each chunk
of the message body to cause the chunk to be transmitted.
Any remaining body data will be transmitted when [WsWriteMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessageend) is called, along with
the end of the message (closing body and envelope tags).

Not setting this flag means the entire message is buffered in
memory and is only transmitted once [WsWriteMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessageend) is called.

### `WS_BUFFERED_TRANSFER_MODE:0x0`

Messages that are written or read are buffered.

This is equivalent to specifying neither
[WS_STREAMED_INPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) nor
**WS_STREAMED_OUTPUT_TRANSFER_MODE**.

### `WS_STREAMED_TRANSFER_MODE`

Messages that are written or read are streamed.

This is equivalent to specifying both
[WS_STREAMED_INPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) and
**WS_STREAMED_OUTPUT_TRANSFER_MODE**.

## Remarks

This value is specified for a channel using the
[WS_CHANNEL_PROPERTY_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) channel property.

The streaming programming model can be used regardless of which
transfer mode is used. In the case where streaming is not used, the calls
to the calls to [WsFillBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillbody) and [WsFlushBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushbody) are NOPs.