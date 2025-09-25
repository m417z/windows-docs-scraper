# NdisMAllocateSharedMemoryAsyncEx function

## Description

> [!CAUTION]
> For ARM and ARM64 processors, we strongly recommend that NDIS driver writers use WDF DMA or WDM DMA instead of NDIS Scatter/Gather DMA.
>
> For more information about WDF DMA, see [Handling DMA Operations in KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-dma-operations-in-kmdf-drivers).
>
> For more information about WDM DMA, see the DMA-related child topics of [Managing Input/Output for Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-input-output-for-drivers).

Miniport drivers call the
**NdisMAllocateSharedMemoryAsyncEx** function to allocate additional memory shared between the driver and
its bus-master DMA NIC, usually when the miniport driver is running low on available NIC receive
buffers.

## Parameters

### `MiniportDmaHandle` [in]

A handle to a context area that NDIS uses to manage a DMA resource. The caller obtained this
handle by calling the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function.

### `Length` [in]

The number of bytes to allocate.

### `Cached` [in]

This parameter is ignored (cached memory is always used on x86 and x64 systems).

### `Context` [in]

A pointer to driver-determined context to be passed to the
[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete) function when it is called.

## Return value

**NdisMAllocateSharedMemoryAsyncEx** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_PENDING** | NDIS will call the [MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete) function and provide information that describes the allocated shared memory. If the attempt to allocate shared memory fails, NDIS calls *MiniportSharedMemoryAllocateComplete* and passes **NULL** pointers. |
| **NDIS_STATUS_FAILURE** | The requested memory could not be allocated at this time. If [NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) returns this status, a subsequent call with the same parameters might succeed, depending on whether system resources have become available. |

## Remarks

**Note** A miniport driver must have already called [NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) or [NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) to initialize a
scatter/gather DMA channel before calling **NdisMAllocateSharedMemoryAsyncEx**.

Drivers of bus-master DMA NICs call
**NdisMAllocateSharedMemoryAsyncEx** to dynamically allocate shared memory. Such drivers also allocate
shared memory space during initialization. These drivers use the dynamically allocated shared memory for
transfer operations when high network traffic places excessive demands on the existing shared memory
space.

Such a miniport driver usually maintains one or more state variables to track the number of shared
memory buffers available for incoming transfers. When the number of available buffers reaches a
driver-determined low, the miniport driver calls
**NdisMAllocateSharedMemoryAsyncEx** to allocate more buffer space in shared memory. When the number of
available buffers climbs to a driver-determined high, the miniport driver calls
[NdisMFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreesharedmemory) one or more
times to release its preceding dynamic allocations.

Usually, such a miniport driver retains the block of shared memory that its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
allocated with
[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory) until
a NIC is removed. When the NIC is removed, NDIS calls the miniport driver's
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. This allocation
is sufficient to handle an average demand for transfers through the NIC.

A miniport driver should set a limit on how much shared memory it can allocate. This limit is
driver-specific and should be high enough so that the driver does not run out of buffers. Do not et a
limit that is excessively high, as this could result in a wasteful consumption of shared memory that
could reduce system performance.

Any miniport driver that calls
**NdisMAllocateSharedMemoryAsyncEx** or
[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory) must release all outstanding allocations with one or more calls to
[NdisMFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreesharedmemory) when its NIC is removed.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete)

[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory)

[NdisMFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreesharedmemory)

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)