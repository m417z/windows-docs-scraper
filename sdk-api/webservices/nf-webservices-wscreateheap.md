# WsCreateHeap function

## Description

Creates a [heap](https://learn.microsoft.com/windows/desktop/wsw/heap) object.

## Parameters

### `maxSize` [in]

The total number of bytes that can be allocated from the heap. The total
number of bytes is defined as sum of the sizes passed in all the calls to
the [WsAlloc](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsalloc) function since the heap was created or reset.

### `trimSize` [in]

The maximum number of bytes of memory that the heap
retains after the heap has been reset by a call to the [WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap) function. This is an approximation value due to heap overhead.

**Note** If the
value of *trimSize* is larger than the value of *maxSize*, the size of the
heap will not be adjusted to the desired size.

### `properties` [in, optional]

 Reserved for future use; set to **NULL**.

### `propertyCount` [in]

Reserved for future use; set to 0 (zero).

### `heap`

On success, pointer that receives the address of the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) structure representing the new heap object.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

## Remarks

A heap in Windows Web Services API is a memory allocation used for [messages](https://learn.microsoft.com/windows/desktop/wsw/message). Heaps can also be used to store message data separately from the lifetime of a message. Some API functions allow for explicit heap control over the lifetime of any data read.

Creating new heap does not allocate any memory (except the memory necessary for [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) structure itself).
The parameters *maxSize* and *trimSize* are used as quotas onlyduring [WsAlloc](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsalloc) and [WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap) operations.