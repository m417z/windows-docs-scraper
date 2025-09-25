# KsCreateAllocator function

## Description

The **KsCreateAllocator** function creates a handle to an allocator for the given sink connection handle. This function does not complete the IRP or set the status in the IRP.

## Parameters

### `ConnectionHandle` [in]

Specifies the handle to the sink connection on which to create the allocator.

### `AllocatorFraming` [in]

Specified framing for the allocator.

### `AllocatorHandle` [out]

Specifies the pointer to a handle to store the allocator handle.

## Return value

The **KsCreateAllocator** function returns STATUS_SUCCESS if successful, or it returns an error if unsuccessful.

## Remarks

There are two versions of the **KsCreateAllocator** function: one for user-mode clients and one for kernel-mode clients. This function can only be called at PASSIVE_LEVEL for kernel-mode clients.

## See also

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)