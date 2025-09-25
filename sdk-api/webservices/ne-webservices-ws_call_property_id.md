# WS_CALL_PROPERTY_ID enumeration

## Description

Optional parameters for configuring a call on a client side service operation.

## Constants

### `WS_CALL_PROPERTY_CHECK_MUST_UNDERSTAND:0`

An application can suppress or enable must understand header processing
on the proxy using this setting. This is **TRUE** by default.

### `WS_CALL_PROPERTY_SEND_MESSAGE_CONTEXT:1`

Enables an application to put headers into the input message for a given call.

### `WS_CALL_PROPERTY_RECEIVE_MESSAGE_CONTEXT:2`

Enables an application to extract headers from the output message for a given call.

### `WS_CALL_PROPERTY_CALL_ID:3`

On a [service operation](https://learn.microsoft.com/windows/desktop/wsw/service-operation) an application can use the call id property to uniquely identify
a service operation function all on a channel. This ID can be passed on to [WsAbandonCall](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabandoncall) along with the
service proxy to abandon the call.

For more information about abandoning calls see [service operation](https://learn.microsoft.com/windows/desktop/wsw/client-side-service-operations).