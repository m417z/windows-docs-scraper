# WsGetHeapProperty function

## Description

Retrieves a particular property of a specified Heap.

## Parameters

### `heap` [in]

A pointer to the **Heap** object to that contains the desired property data.

### `id` [in]

This is a [WS_HEAP_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_heap_property) enumerator that identifies the desired property.

### `value`

A reference to the retrieved property value.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The buffer size allocated by the caller for the retrieved property value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.