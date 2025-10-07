# DSTORAGE_ERROR_PARAMETERS_SIGNAL structure (dstorage.h)

The parameters passed to the [EnqueueSignal](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-enqueuesignal) call.

## Members

`Fence`

An **ID3D12Fence** to enqueue.

`Value`

The value to write to the fence.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |