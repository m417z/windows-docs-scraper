# WS_GET_LISTENER_PROPERTY_CALLBACK callback function

## Description

Handles the [WsGetListenerProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetlistenerproperty) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `listenerInstance` [in]

The pointer to the state specific to this listener instance,
as created by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback).

### `id` [in]

The id of the property to retrieve.

A custom listener can decide which properties to support.

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
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsGetListenerProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetlistenerproperty) for information about the contract
of this API.