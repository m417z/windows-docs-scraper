# FREE_SHARED_MEMORY_HANDLER callback function

## Description

The
*NetFreeSharedMemory* function (FREE_SHARED_MEMORY_HANDLER entry point) is called by NDIS when a driver
frees shared memory from a shared memory provider.

## Parameters

### `ProviderContext` [in]

An NDIS_HANDLE to a block of driver-allocated context information that identifies the provider.
The provider supplied this information in the
**ProviderContext** member of the
[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics) structure.

### `SharedMemoryProviderContext` [in]

A handle for a context area that identifies the shared memory block. This is the handle that the
shared memory provider supplied at the
*pSharedMemoryProviderContext* parameter of the
[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler) function.

## Remarks

NDIS calls the
*NetFreeSharedMemory* function of a shared memory provider when a driver calls the
[NdisFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreesharedmemory) function.

The shared memory provider specified the entry point (FREE_SHARED_MEMORY_HANDLER) for
*NetFreeSharedMemory* in the
[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics) structure.

## See also

[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics)

[NdisFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreesharedmemory)

[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler)