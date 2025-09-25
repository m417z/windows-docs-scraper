# WsGetChannelProperty function

## Description

Retrieves a property of the Channel referenced by the *channel* parameter.

## Parameters

### `channel` [in]

A pointer to the [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) object with the property to retrieve.

### `id` [in]

Represents an identifier of the property to retrieve.

### `value`

A void pointer referencing the location to store the retrieved property.

**Note** The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The number of bytes allocated by the caller to
store the retrieved property.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property Id was not supported for this object or the specified buffer was not large enough. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |