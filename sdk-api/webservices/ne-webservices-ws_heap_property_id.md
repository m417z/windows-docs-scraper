# WS_HEAP_PROPERTY_ID enumeration

## Description

Each heap property is identified by an ID and has an associated value.

## Constants

### `WS_HEAP_PROPERTY_MAX_SIZE:0`

Used with [WsGetHeapProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheapproperty). Returns
the total number of bytes that can be allocated from the heap. The total
number of bytes is defined as sum of the sizes passed in all the calls to
[WsAlloc](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsalloc) since the heap was created / reset.

### `WS_HEAP_PROPERTY_TRIM_SIZE:1`

Used with [WsGetHeapProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheapproperty).
Returns the maximum number of bytes of memory that the heap will
retain after a call to [WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap) call. This should
be treated an approximate value due to heap overhead. If the
trim size is larger than the max size, then the size of the
heap will not be trimmed.

### `WS_HEAP_PROPERTY_REQUESTED_SIZE:2`

Used with [WsGetHeapProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheapproperty). Returns the current
total number of bytes requested from the heap since the heap was
created/reset.

### `WS_HEAP_PROPERTY_ACTUAL_SIZE:3`

Used with [WsGetHeapProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheapproperty). Returns the current
total number of bytes that the WS_HEAP has allocated from the
operating system for purposes of providing allocations.