# ALLOCATE_SHARED_MEMORY_HANDLER callback function

## Description

The
*NetAllocateSharedMemory* function (ALLOCATE_SHARED_MEMORY_HANDLER entry point) is called by NDIS when
a driver allocates shared memory from a shared memory provider.

## Parameters

### `ProviderContext` [in]

An NDIS_HANDLE to a block of driver-allocated context information that identifies the provider.
The provider supplied this information in the
**ProviderContext** member of the
[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics) structure.

### `SharedMemoryParameters` [in]

A pointer to an
[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters) structure that defines the requested attributes for the shared
memory.

### `pSharedMemoryProviderContext` [in, out]

A pointer to a handle for a shared memory context area. The shared memory provider provides a
handle that identifies the shared memory that it allocated.

## Return value

*NetAllocateSharedMemory* can return the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because there were insufficient resources to complete the operation. |
| **NDIS_STATUS_INVALID_PARAMETER** | The operation failed because of an invalid input parameter. |
| **NDIS_STATUS_FAILURE** | The operation failed for unspecified reasons. |

## Remarks

NDIS calls the
*NetAllocateSharedMemory* function of a shared memory provider when a driver calls the
[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory) function.

The shared memory provider specified the entry point (ALLOCATE_SHARED_MEMORY_HANDLER) for
*NetAllocateSharedMemory* in the
[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics) structure.

## See also

[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters)

[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics)

[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory)