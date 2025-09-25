# WS_OPERATION_CONTEXT_PROPERTY_ID enumeration

## Description

The properties available on the Context. Not all properties may be available
at a given point on a context. All context properties are available through [WsGetOperationContextProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetoperationcontextproperty).

## Constants

### `WS_OPERATION_CONTEXT_PROPERTY_CHANNEL:0`

This value is a handle to the underlying channel. This property is available to service operations ,
to the [WS_SERVICE_MESSAGE_RECEIVE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_message_receive_callback), [WS_SERVICE_ACCEPT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_accept_channel_callback) and
[WS_SERVICE_CLOSE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_close_channel_callback).

### `WS_OPERATION_CONTEXT_PROPERTY_CONTRACT_DESCRIPTION:1`

The value represents the contract description. This property is available to service operations ,
to the [WS_SERVICE_MESSAGE_RECEIVE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_message_receive_callback), [WS_SERVICE_ACCEPT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_accept_channel_callback) and
[WS_SERVICE_CLOSE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_close_channel_callback).

### `WS_OPERATION_CONTEXT_PROPERTY_HOST_USER_STATE:2`

The value is a pointer to the host state specified on the [service host](https://learn.microsoft.com/windows/desktop/wsw/service-host) as the
[WS_SERVICE_PROPERTY_HOST_USER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_property_id) service property. This property is available to
service operations and to the [WS_SERVICE_MESSAGE_RECEIVE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_message_receive_callback).

### `WS_OPERATION_CONTEXT_PROPERTY_CHANNEL_USER_STATE:3`

The value is a pointer to the channel state specified through [WS_SERVICE_ACCEPT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_accept_channel_callback). This property is
available to service operations and to the [WS_SERVICE_MESSAGE_RECEIVE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_message_receive_callback).

### `WS_OPERATION_CONTEXT_PROPERTY_INPUT_MESSAGE:4`

The value is a pointer to the underlying input message. This property is available to service operations and to the
[WS_SERVICE_MESSAGE_RECEIVE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_message_receive_callback).

### `WS_OPERATION_CONTEXT_PROPERTY_OUTPUT_MESSAGE:5`

The value is a pointer to the underlying output message. This property is available only to service operations.

### `WS_OPERATION_CONTEXT_PROPERTY_HEAP:6`

The value is a pointer to the WS_HEAP. This property is available to a service operation. Please see the memory management section in
service operations for usage.

### `WS_OPERATION_CONTEXT_PROPERTY_LISTENER:7`

### `WS_OPERATION_CONTEXT_PROPERTY_ENDPOINT_ADDRESS:8`