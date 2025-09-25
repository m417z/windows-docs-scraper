# WsGetServiceHostProperty function

## Description

Retrieves a specified Service Host property. The property to retrieve is identified by a [WS_SERVICE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_property_id) input parameter.

## Parameters

### `serviceHost` [in]

A pointer to the WS_SERVICE_HOST object containing the property to retrieve.

### `id` [in]

This is a **WS_SERVICE_PROPERTY_ID** enumerator value that identifies the property to retrieve.

### `value`

A void pointer to a location for storing the retrieved property value.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The byte-length buffer size allocated by the caller to store the retrieved property value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |