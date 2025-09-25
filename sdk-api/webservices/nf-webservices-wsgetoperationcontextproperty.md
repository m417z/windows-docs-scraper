# WsGetOperationContextProperty function

## Description

Returns a property of the specified operation context. It should be noted that the
validity of these property is limited to the lifetime of the operation context itself.

## Parameters

### `context` [in]

The context that the property value is being obtained for.

### `id` [in]

The id of the property.

### `value`

The address to place the retrieved value. The contents are not modified in case of a failure.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The size of the buffer that the caller has allocated for the retrieved value.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.