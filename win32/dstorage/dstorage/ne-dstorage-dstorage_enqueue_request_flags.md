# DSTORAGE_ENQUEUE_REQUEST_FLAGS enumeration (dstorage.h)

Defines constants that specify the behavior of requests enqueued by using [IDStorageQueue3::EnqueueRequests](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue3-enqueurequests).

## Constants

|   |
| -- |
| **DSTORAGE_ENQUEUE_REQUEST_FLAG_NONE**<br> Specifies that requests wait on the **ID3D12Fence** before writing to the destination. All processing required for the requests before the write can be completed asynchronously once submitted. This is the default behavior.|
| **DSTORAGE_ENQUEUE_REQUEST_FLAG_FENCE_WAIT_BEFORE_GPU_WORK**<br> Specifies that requests wait on the **ID3D12Fence** before using the GPU for any of the requests, and before writing to the destination. All processing required for the requests, except GPU work or writing to the destination, can be completed asynchronously once submitted.|
| **DSTORAGE_ENQUEUE_REQUEST_FLAG_FENCE_WAIT_BEFORE_SOURCE_ACCESS**<br> Specifies that requests wait on the **ID3D12Fence** before reading from the source. No processing occurs until the **ID3D12Fence** is set.|

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |