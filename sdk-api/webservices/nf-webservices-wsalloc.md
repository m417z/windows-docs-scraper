# WsAlloc function

## Description

Allocates a segment of memory from the specified [heap](https://learn.microsoft.com/windows/desktop/wsw/heap).

## Parameters

### `heap` [in]

Pointer to a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) structure representing the heap from which to allocate the memory.

### `size` [in]

The number of bytes to allocate. This value can be zero.

### `ptr`

On success, a pointer that receives the address of the allocated memory. This pointer is valid until [WsFreeHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeheap) or [WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap) is called on the [heap](https://learn.microsoft.com/windows/desktop/wsw/heap).

The returned pointer is aligned on an 8-byte boundary.

Zero byte allocations will return a non-NULL pointer.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_QUOTA_EXCEEDED** | The requested bytes, in addition to already allocated bytes, exceed the size of the [heap](https://learn.microsoft.com/windows/desktop/wsw/heap), as specified by the [WS_HEAP_PROPERTY_MAX_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id) property. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The memory returned by this function is not zero initialized and contains undefined values.