# WsSetErrorProperty function

## Description

Sets an [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object property.

## Parameters

### `error` [in]

A pointer to the **Error** object in which to set the property. The pointer must reference a valid [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object.

### `id` [in]

Identifier of the property to set.

### `value`

A pointer to the property value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The size in bytes of the property value.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object.<br><br>The specified size was not appropriate for the property. |
| **E_OUTOFMEMORY** | There was not enough space to set the property value. |
| **Other Errors** | This function may return other errors not listed above. |