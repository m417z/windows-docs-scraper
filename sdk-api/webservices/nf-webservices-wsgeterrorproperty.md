# WsGetErrorProperty function

## Description

Retrieves a property of an [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object referenced by the *error* parameter.

## Parameters

### `error` [in]

A pointer to the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object with the property to retrieve.

### `id` [in]

An identifier of the property to retrieve.

### `buffer`

A pointer referencing the location to store the retrieved property.

### `bufferSize` [in]

The number of bytes allocated by the caller to
store the retrieved property.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |