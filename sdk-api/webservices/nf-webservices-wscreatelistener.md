# WsCreateListener function

## Description

Creates a [listener](https://learn.microsoft.com/windows/desktop/wsw/listener) with the specified properties.

## Parameters

### `channelType` [in]

The type of channel the listener listens for. For channel types, see the [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) enumeration.

### `channelBinding` [in]

The channel protocol for the listener.
For possible bindings, see the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration.

### `properties`

Pointer to a [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_listener_property) structure containing optional properties for the listener.

For information on which properties you can specify when creating a listener, see the [WS_LISTENER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) enumeration.

For information on creating a custom listener, see the Remarks section.

### `propertyCount` [in]

The number of properties in the *properties* array.

### `securityDescription` [in, optional]

Pointer to a [WS_SECURITY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) structure specifying the security for the listener.

If you are creating a custom channel (using the WS_CUSTOM_CHANNEL_BINDING value of the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration), the security description must be **NULL**. See the Remarks section.

### `listener`

On success, a pointer that receives the address of the [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure representing the new listener.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

When you create a custom listener (using the WS_CUSTOM_CHANNEL_BINDING value of the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration), you can specify only the following channel properties:

* WS_LISTENER_PROPERTY_CUSTOM_LISTENER_CALLBACKS
* WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS

(See the [WS_LISTENER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) enumeration.) If other initial properties are required to create the custom listener, specify them by using the WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS property.

To pass security information to a custom listener implementation, use the WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS value of the [WS_LISTENER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) enumeration.