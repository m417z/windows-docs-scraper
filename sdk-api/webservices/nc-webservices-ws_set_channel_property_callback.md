# WS_SET_CHANNEL_PROPERTY_CALLBACK callback function

## Description

Handles the [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

The pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

### `id` [in]

The id of the property to set.

### `value`

The pointer to the property value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The size of the property value.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object.<br><br>The specified size was not appropriate for the property. |
| **E_OUTOFMEMORY** | There was not enough space to set the property value. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty) for information about the contract
of this API.

It is up to the custom channel implementation to determine the
set of properties it wishes to support.

If a property is not supported, the **E_INVALIDARG**  should be returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)