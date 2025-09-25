# WS_PROXY_PROPERTY_ID enumeration

## Description

Optional parameters for configuring the service proxy. With an exception of
**WS_PROXY_PROPERTY_STATE** all the values are only supported for
use with [WsCreateServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateserviceproxy) as part of the [WS_PROXY_PROPERTY*](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_proxy_property) parameter.

## Constants

### `WS_PROXY_PROPERTY_CALL_TIMEOUT:0`

The maximum amount of time in milliseconds for a call to remain pending.
Default is 30000 milliseconds(30 seconds). It is of type **ULONG**.

If an application wishes to have no timeout associated with a call, it can set the value to INFINITE.

This property is write only.

### `WS_PROXY_PROPERTY_MESSAGE_PROPERTIES:1`

This property allows the user to specify properties of the message
objects used by the service proxy to send and receive messages.

This property may be specified when the service proxy is created.

The value specified should be of type [WS_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_properties).

The following message properties may be specified:

* [WS_MESSAGE_PROPERTY_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
* [WS_MESSAGE_PROPERTY_XML_READER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
* [WS_MESSAGE_PROPERTY_XML_WRITER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
* [WS_MESSAGE_PROPERTY_MAX_PROCESSED_HEADERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)

### `WS_PROXY_PROPERTY_MAX_CALL_POOL_SIZE:2`

Each call in the service proxy is represented by an object internal to the service proxy.
A call object is designed such that after every call it can be reused.
This allows applications to scale better in scenarios where they expect
large number of calls over the service proxy. The default value for this property is 5.
It is of type **USHORT**.

This property is write only.

### `WS_PROXY_PROPERTY_STATE:3`

The current state of the service proxy.
It is of type [WS_SERVICE_PROXY_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_proxy_state).

This property is read only.

The returned value is a snapshot of the current state, so it is
possible that the state may have changed before the caller has
had a chance to examine the value.

### `WS_PROXY_PROPERTY_MAX_PENDING_CALLS:4`

The maximum number of pending calls allowed on the service proxy. If the
maximum number of calls pending on the service proxy reaches this limit, the
incoming calls will be rejected with **WS_E_QUOTA_EXCEEDED** (see [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values)). The default value
for this property is 100.
It is of type **ULONG**.

This property is write only.

### `WS_PROXY_PROPERTY_MAX_CLOSE_TIMEOUT:5`

The amount of time in milliseconds the service proxy will wait for the pending calls to complete.
Once the timeout expires, the service proxy will abort itself.

The default value for this property is 5000 (5 seconds).

This property is write only.
It is of type **ULONG**.

### `WS_PROXY_FAULT_LANG_ID:6`

The LANGID that would be used for returning a fault. If none specified default user locale will be used. It is of type [LANGID](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers).

This property is write only.