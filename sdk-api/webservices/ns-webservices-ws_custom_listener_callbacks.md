# WS_CUSTOM_LISTENER_CALLBACKS structure

## Description

A structure that is used to specify a set of callbacks
that form the implementation of a custom
listener.

## Members

### `createListenerCallback`

The callback that implements [WsCreateListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener).
See [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback) for more information.

### `freeListenerCallback`

The callback that implements [WsFreeListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreelistener).
See [WS_FREE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_listener_callback) for more information.

### `resetListenerCallback`

The callback that implements [WsResetListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetlistener).
See [WS_RESET_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_reset_listener_callback) for more information.

### `openListenerCallback`

The callback that implements [WsOpenListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenlistener).
See [WS_OPEN_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_open_listener_callback) for more information.

### `closeListenerCallback`

The callback that implements [WsCloseListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloselistener).
See [WS_CLOSE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_close_listener_callback) for more information.

### `abortListenerCallback`

The callback that implements [WsAbortListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortlistener).
See [WS_ABORT_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_abort_listener_callback) for more information.

### `getListenerPropertyCallback`

The callback that implements [WsGetListenerProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetlistenerproperty).
See [WS_GET_LISTENER_PROPERTY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_get_listener_property_callback) for more information.

### `setListenerPropertyCallback`

The callback that implements [WsSetListenerProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetlistenerproperty).
See [WS_SET_LISTENER_PROPERTY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_set_listener_property_callback) for more information.

### `createChannelForListenerCallback`

The callback that implements [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener).
See [WS_CREATE_CHANNEL_FOR_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_for_listener_callback) for more information.

### `acceptChannelCallback`

The callback that implements [WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel).
See [WS_ACCEPT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_accept_channel_callback) for more information.

## Remarks

This structure is specified when a listener is created using
[WsCreateListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener)
using [WS_LISTENER_PROPERTY_CUSTOM_LISTENER_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id).

Except where noted, each callback is responsible for validating all parameters and
that the operation requested is acceptable given the current
[WS_LISTENER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_state).