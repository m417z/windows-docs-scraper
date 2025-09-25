# NdisMFreeSharedMemory function

## Description

**NdisMFreeSharedMemory** frees memory that was previously allocated by
[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory) or
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) by the driver of a DMA NIC.

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the handle originally input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `Length` [in]

Specifies the number of bytes originally allocated.

### `Cached` [in]

Specifies **TRUE** if the original allocation was cacheable.

### `VirtualAddress` [in]

Specifies the base virtual address returned by
**NdisMAllocateSharedMemory** or
**NdisMAllocateSharedMemoryAsyncEx**.

### `PhysicalAddress` [in]

Specifies the corresponding physical address returned by
**NdisMAllocateSharedMemory** or
**NdisMAllocateSharedMemoryAsyncEx**.

## Remarks

If it has already made a successful call to
[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory) or
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex), the miniport driver of a DMA device calls
**NdisMFreeSharedMemory** if any of the following occurs:

* Its
  *MiniportInitializeEx* function is unable to initialize the NIC, so this function must release all
  existing claims on hardware resources for that NIC before it returns control.
* The NIC for which the miniport driver allocated the memory is being removed.
* The driver is being unloaded, whether because the system is shutting down or because the user
  reconfigured the network components used in the machine.
* The driver allocated additional shared memory with
  **NdisMAllocateSharedMemoryAsyncEx** when I/O demand on a NIC was high but network traffic has now
  subsided to an average level.

A miniport driver cannot call
**NdisMFreeSharedMemory** to free a subrange within an allocated shared memory range. The parameters
passed to
**NdisMFreeSharedMemory** must match exactly those that were passed to
**NdisMAllocateSharedMemory** or
**NdisMAllocateSharedMemoryAsyncEx**.

**NdisMFreeSharedMemory** cannot be called from a
[MiniportShutdownEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_shutdown) function.

Microsoft Windows Server 2003, Windows XP Service Pack 1, and later versions of Windows allow both
bus-master DMA NICs and subordinate DMA NICs to call
**NdisMFreeSharedMemory**. Prior releases allow only bus-master DMA NICs to call
**NdisMFreeSharedMemory**.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete)

[MiniportShutdownEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_shutdown)

[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory)

[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex)