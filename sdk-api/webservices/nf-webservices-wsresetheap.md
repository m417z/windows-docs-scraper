# WsResetHeap function

## Description

Releases all Heap allocations. Allocations made on the Heap
using [WsAlloc](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsalloc) are no longer valid. Allocation for the Heap object itself is not released.

## Parameters

### `heap` [in]

A pointer to a Heap instance to reset.
If the heap is not required for the given type this
parameter can be **NULL**.

The heap object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The heap object can retain allocated memory even though it has been reset. The amount of memory retained
can be specified using the [WS_HEAP_PROPERTY_TRIM_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id)
property when creating the heap.