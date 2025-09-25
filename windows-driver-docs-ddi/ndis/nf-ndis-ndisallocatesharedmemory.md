# NdisAllocateSharedMemory function

## Description

The
**NdisAllocateSharedMemory** function allocates shared memory from a shared memory provider.

## Parameters

### `NdisHandle` [in]

An NDIS driver or instance handle that was obtained during caller initialization. For example, a
miniport driver can use the NDIS handle that it obtained from the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) or
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
Other NDIS drivers can use the handles from the following functions:

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

### `SharedMemoryParameters` [in]

A pointer to an
[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters) structure that defines the requested attributes for the shared
memory.

### `pAllocationHandle` [in, out]

A pointer to a location for a handle that identifies the shared memory that was allocated. The
handle is available when the function returns or it is **NULL** if the function fails. The caller must use
this handle to free the shared memory that was allocated successfully.

## Return value

**NdisAllocateSharedMemory** can return the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because there were insufficient resources to complete the operation. |
| **NDIS_STATUS_INVALID_PARAMETER** | The operation failed because of an invalid input parameter. |
| **NDIS_STATUS_FAILURE** | The operation failed for unspecified reasons. |

## Remarks

**Note** A miniport driver must have already called [NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) or [NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) to initialize a
scatter/gather DMA channel before calling **NdisAllocateSharedMemory**.

NDIS drivers call the
**NdisAllocateSharedMemory** function to allocate a block of shared memory from an NDIS shared memory
provider.

The
*SharedMemoryParameters* parameter contains a pointer to an
[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters) structure that defines the requested attributes for the shared
memory. If the **NDIS_SHARED_MEM_PARAMETERS_CONTIGUOUS** flag is not set in the
**Flags** member, shared memory can be specified in a scatter-gather list that is contained in
non-contiguous memory.

NDIS calls the
[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler) function of a shared memory provider from the context of the call to
**NdisAllocateSharedMemory**.

The driver must call the
[NdisFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreesharedmemory) function to free
the shared memory that it allocates with
**NdisAllocateSharedMemory**.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreesharedmemory)

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler)