# WsGetServiceProxyProperty function

## Description

This function retrieves a specified Service Proxy property. The property to retrieve is identified by a [WS_PROXY_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_proxy_property_id) input parameter.

## Parameters

### `serviceProxy` [in]

This parameter is a pointer to the WS_SERVICE_PROXY object containing the property to retrieve.

### `id` [in]

The value of this parameter is a **WS_PROXY_PROPERTY_ID** enumerator value that identifies the property to retrieve.

### `value`

This parameter is a reference to a location for storing the retrieved property value.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The value of this ULONG parameter represents the byte-length buffer size allocated by the caller to store the retrieved property value.

### `error` [in, optional]

This parameter is a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) pointer to where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object. |