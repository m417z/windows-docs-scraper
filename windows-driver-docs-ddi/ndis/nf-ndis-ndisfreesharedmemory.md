# NdisFreeSharedMemory function

## Description

The
**NdisFreeSharedMemory** function frees shared memory that a driver allocated from a shared memory
provider.

## Parameters

### `NdisHandle` [in]

An NDIS driver or instance handle that was obtained during caller initialization. This should be
the same handle that was passed to the
*NdisHandle* parameter of the
[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory) function when the shared memory was allocated.

### `AllocationHandle` [in]

A handle for a context area that identifies the shared memory block. This is the handle that NDIS
supplied at the
*pSharedMemoryProviderContext* parameter of the
**NdisAllocateSharedMemory** function.

## Remarks

An NDIS driver must call the
**NdisFreeSharedMemory** function to free a block of shared memory that it previously allocated with
the
[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory) function.

NDIS calls the
[NetFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-free_shared_memory_handler) function of a
shared memory provider from the context of the call to
**NdisFreeSharedMemory**.

## See also

[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory)

[NetFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-free_shared_memory_handler)