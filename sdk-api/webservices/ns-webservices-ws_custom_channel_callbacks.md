# WS_CUSTOM_CHANNEL_CALLBACKS structure

## Description

A structure that is used to specify a set of callbacks
that form the implementation of a custom channel.

## Members

### `createChannelCallback`

The callback that implements [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel).
See [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback) for more information.

### `freeChannelCallback`

The callback that implements [WsFreeChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreechannel).
See [WS_FREE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_channel_callback) for more information.

### `resetChannelCallback`

The callback that implements [WsResetChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetchannel).
See [WS_RESET_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_reset_channel_callback) for more information.

### `openChannelCallback`

The callback that implements [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel).
See [WS_OPEN_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_open_channel_callback) for more information.

### `closeChannelCallback`

The callback that implements [WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel).
See [WS_CLOSE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_close_channel_callback) for more information.

### `abortChannelCallback`

The callback that implements [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel).
See [WS_ABORT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_abort_channel_callback) for more information.

### `getChannelPropertyCallback`

The callback that implements [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty).
See [WS_GET_CHANNEL_PROPERTY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_get_channel_property_callback) for more information.

### `setChannelPropertyCallback`

The callback that implements [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty).
See [WS_SET_CHANNEL_PROPERTY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_set_channel_property_callback) for more information.

### `writeMessageStartCallback`

The callback that implements [WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart).
See [WS_WRITE_MESSAGE_START_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_message_start_callback) for more information.

### `writeMessageEndCallback`

The callback that implements [WsWriteMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessageend).
See [WS_WRITE_MESSAGE_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_message_end_callback) for more information.

### `readMessageStartCallback`

The callback that implements [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart).
See [WS_READ_MESSAGE_START_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_message_start_callback) for more information.

### `readMessageEndCallback`

The callback that implements [WsReadMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessageend).
See [WS_READ_MESSAGE_END_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_message_end_callback) for more information.

### `abandonMessageCallback`

The callback that implements [WsAbandonMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabandonmessage).
See [WS_ABANDON_MESSAGE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_abandon_message_callback) for more information.

### `shutdownSessionChannelCallback`

The callback that implements [WsShutdownSessionChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsshutdownsessionchannel).
See [WS_SHUTDOWN_SESSION_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_shutdown_session_channel_callback) for more information.

## Remarks

This structure is specified when a channel is created using
[WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) using [WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id).

Except where noted, each callback is responsible for validating all parameters and
that the operation requested is acceptable given the current
[WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state).