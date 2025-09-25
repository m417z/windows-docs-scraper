# WsCreateChannel function

## Description

Creates a [channel](https://learn.microsoft.com/windows/desktop/wsw/channel) for message exchange with an endpoint.

## Parameters

### `channelType` [in]

The type of the channel. For channel types, see the [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) enumeration. This represents the message exchange pattern for the channel being created.

### `channelBinding` [in]

The channel [binding](https://learn.microsoft.com/windows/desktop/wsw/binding), indicating the protocol stack to use for the new channel.
For available channel bindings, see the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration.

### `properties` [in]

An array of [WS_CHANNEL_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_property) structures containing optional values for channel initialization. The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

For information on which channel properties can be specified when you create a channel, see the [WS_CHANNEL_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) enumeration.

For information on creating a custom channel, see the Remarks section.

### `propertyCount` [in]

The number of properties in the *properties* array.

### `securityDescription` [in, optional]

Pointer to a [WS_SECURITY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) structure specifying the security for the channel.

If you are creating a custom channel (using the WS_CUSTOM_CHANNEL_BINDING value of the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration), the security description must be **NULL**. See the Remarks section.

### `channel`

Pointer that receives the address of the created channel.
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

Use the [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel) function to initiate communication on the channel and to specify the endpoint.

When you create a custom channel (using the WS_CUSTOM_CHANNEL_BINDING value of the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration), you can specify only the following channel properties:

* WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_CALLBACKS
* WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS

(See the [WS_CHANNEL_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) enumeration) If initial properties are required to create the custom channel, specify them by using the WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS property.

To pass security information to a custom channel implementation, use the WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS value of the [WS_CHANNEL_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) enumeration.