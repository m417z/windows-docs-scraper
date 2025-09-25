# WS_GET_CHANNEL_PROPERTY_CALLBACK callback function

## Description

Handles the [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

The pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

### `id` [in]

The id of the property to retrieve.

### `value`

The location to store the retrieved property.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The number of bytes allocated by the caller to
store the retrieved property.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for information about the contract
of this API.

Every custom channel implementation must support returning
a value for at least the following properties:

* [WS_CHANNEL_PROPERTY_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
* [WS_CHANNEL_PROPERTY_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
* [WS_CHANNEL_PROPERTY_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
* [WS_CHANNEL_PROPERTY_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)

Service Model layer provides its own logic of call timeouts as such it requires
disabling timeouts in the underlying channel. In order for a custom channel to be
used from Service Model layer, it should support disabling all of its timeouts and
implement this callback for [WS_CHANNEL_PROPERTY_ENABLE_TIMEOUTS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id). A custom
channel cannot be used through Service Model unless query for
**WS_CHANNEL_PROPERTY_ENABLE_TIMEOUTS** returns **FALSE**.

It is up to the custom channel implementation to determine any
additional properties it wishes to support.

If a property is not supported, the **E_INVALIDARG** should be returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)