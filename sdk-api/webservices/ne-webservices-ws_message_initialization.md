# WS_MESSAGE_INITIALIZATION enumeration

## Description

Specifies what headers the
[WsInitializeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsinitializemessage) should add to the message.

## Constants

### `WS_BLANK_MESSAGE:0`

The headers of the message are empty.

### `WS_DUPLICATE_MESSAGE:1`

The headers are initialized to be the same as the source message's headers.

### `WS_REQUEST_MESSAGE:2`

If using [WS_ADDRESSING_VERSION_0_9](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) or **WS_ADDRESSING_VERSION_1_0**,
then a unique message ID is set as the MessageID header of the message.
No other headers are added in the message.

### `WS_REPLY_MESSAGE:3`

The ReplyTo header of the source message (an [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address))
is used to address the message. The MessageID header of the source
message is used to add a RelatesTo header to the message. If the message
will contain a fault reply, then [WS_FAULT_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_initialization) should be
used instead.

### `WS_FAULT_MESSAGE:4`

The FaultTo or ReplyTo header of the source message (an [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address))
is used to address the message. The MessageID header of the source message
is used to add a RelatesTo header to the message. This should only be
used when the contents of the message will contain a fault.