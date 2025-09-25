# WsGetFaultErrorProperty function

## Description

Retrieves a [Fault](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) error property of an [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object referenced by the *error* parameter.

## Parameters

### `error` [in]

A pointer to the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object with the property to retrieve.

### `id` [in]

Represents an identifier of the fault error property to retrieve.

### `buffer`

A pointer referencing the location to store the retrieved fault error property.

**Note** The pointer must have an alignment compatible with the type
of the property.

### `bufferSize` [in]

The number of bytes allocated by the caller to
store the retrieved property.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **Other Errors** | This function may return other errors not listed above. |