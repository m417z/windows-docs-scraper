# WsCreateChannelForListener function

## Description

Creates a [channel](https://learn.microsoft.com/windows/desktop/wsw/channel) associated with a specified [listener](https://learn.microsoft.com/windows/desktop/wsw/listener).

## Parameters

### `listener` [in]

Pointer to a [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure representing the listener for which to create a channel. The listener
can be in any state. (For listener states, see the [WS_LISTENER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_state) enumeration.)

### `properties`

An array of [WS_CHANNEL_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_property) structures containing optional values for channel initialization. This can be a **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

For information on creating a custom channel, see the Remarks section.

### `propertyCount` [in]

The number of properties in the *properties* array.

### `channel`

On success, a pointer that receives the address of the created channel.
When the channel is no longer needed, you must free it by calling [WsFreeChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreechannel).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

To accept an incoming message exchange, call the [WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel) function.

The security characteristics of the channel are the same as those
specified for the listener.

When you create a custom channel (using the WS_CUSTOM_CHANNEL_BINDING value of the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration), you can specify only the following channel properties:

* WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_CALLBACKS
* WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS

If initial properties are required to create the custom channel, specify them by using the WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS property.