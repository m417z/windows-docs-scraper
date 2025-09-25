# WsGetListenerProperty function

## Description

Retrieves a specified Listener object property. The property to retrieve is identified by a [WS_LISTENER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_listener_property) input parameter.

## Parameters

### `listener` [in]

A pointer to the Listener object containing the desired property. This must be a valid [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) that was returned
from [WsCreateListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener).

### `id` [in]

This is a **WS_LISTENER_PROPERTY_ID** enumerator value that identifies the desired property.

### `value`

A reference to a location for storing the retrieved property value.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

Represents the byte-length buffer size allocated by the caller to store the retrieved property value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **Other Errors** | This function may return other errors not listed above. |