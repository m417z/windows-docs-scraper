# WsSetChannelProperty function

## Description

Sets a property of the channel.

## Parameters

### `channel` [in]

A pointer to the **Channel** on which to set the property and may not be **NULL**.

### `id` [in]

Identifier of the property to set.

### `value`

A void pointer to the property value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The size in bytes of the property value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object.<br><br>The specified size was not appropriate for the property. |
| **E_OUTOFMEMORY** | There was not enough space to set the property value. |
| **Other Errors** | This function may return other errors not listed above. |