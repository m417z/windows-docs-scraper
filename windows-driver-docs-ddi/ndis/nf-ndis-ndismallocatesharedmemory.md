# NdisMAllocateSharedMemory function

## Description

> [!CAUTION]
> For ARM and ARM64 processors, we strongly recommend that NDIS driver writers use WDF DMA or WDM DMA instead of NDIS Scatter/Gather DMA.
>
> For more information about WDF DMA, see [Handling DMA Operations in KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-dma-operations-in-kmdf-drivers).
>
> For more information about WDM DMA, see the DMA-related child topics of [Managing Input/Output for Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-input-output-for-drivers).

**NdisMAllocateSharedMemory** allocates and maps a host memory range so that the memory range is
simultaneously accessible from both the host system and a DMA NIC.

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the handle input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `Length` [in]

Specifies the number of bytes to allocate.

### `Cached` [in]

This parameter is ignored (cached memory is always used on x86 and x64 systems).

### `VirtualAddress` [out]

Pointer to a caller-supplied variable in which this function returns the base virtual address of
the allocation for use by the miniport driver. If
**NdisMAllocateSharedMemory** cannot satisfy its caller, it returns **NULL** to indicate that no memory
was allocated.

### `PhysicalAddress` [out]

Pointer to a caller-supplied variable in which this function returns a physical address, suitable
for use by the NIC, that corresponds to that returned at
*VirtualAddress*, or it returns **NULL**.

## Remarks

**Note** A miniport driver must have already called [NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) or [NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) to initialize a
scatter/gather DMA channel before calling **NdisMAllocateSharedMemory**.

Microsoft Windows Server 2003, Windows XP Service Pack 1, and later versions of Windows allow both
bus-master DMA NICs and subordinate DMA NICs to call
**NdisMAllocateSharedMemory**. Prior releases allow only bus-master DMA NICs to call
**NdisMAllocateSharedMemory**. In these prior releases, if
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) did not specify that the NIC is a bus master when it called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes),
**NdisMAllocateSharedMemory** simply returns control without attempting to make an allocation.

**NdisMAllocateSharedMemory** provides both the mapped virtual address range that the driver uses to
access the shared memory block and the
[NDIS_PHYSICAL_ADDRESS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557129(v=vs.85))-type range that the
NIC uses. A value returned at
*PhysicalAddress* can be doubly mapped by the system. That is, a "physical" address range described
by the value at
*PhysicalAddress* and
*Length* can be a range of mapped logical addresses that do not match the host physical addresses for
the allocation in every possible platform.

**NdisMAllocateSharedMemory** can be called only from
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize). How large
an allocation to request depends on how the driver writer, knowing the capabilities and features of the
NIC, decides to make the tradeoff between the following performance versus size dilemma:

* In periods of high network traffic, a miniport driver cannot maintain high I/O throughput if it runs
  low on shared memory space for device-accessible data buffers.

  For example, the miniport driver could be indicating receive buffers in shared memory faster than
  such buffers are being returned from bound protocol drivers when a flood of receives come in to a NIC.
  If all its shared memory space is consumed by outstanding receive buffers, the miniport driver might
  have to disable receive interrupts on a NIC until it has some shared memory space available for receive
  buffers.
* On the other hand, calling
  **NdisMAllocateSharedMemory** with a
  *Length* chosen to anticipate some maximum transfer demand makes the driver's image larger and its
  resource usage quite uneconomical, except for rare periods of very high I/O demand. Moreover,
  **NdisMAllocateSharedMemory** might not give the driver such a large block if insufficient system
  memory is available, forcing the driver to fail initialization.

A miniport driver that supplies a
[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete) function has considerably more flexibility in resolving the
preceding performance versus size dilemma.
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) should allocate only enough shared memory with
**NdisMAllocateSharedMemory** for a moderate demand for network transfer operations through the NIC if
the driver has a
*MiniportSharedMemoryAllocateComplete* function. Such a miniport driver can call
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) dynamically to allocate more shared memory in periods of heavier
transfer demand on a NIC. When the high demand for transfers subsides, such a driver calls
[NdisMFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreesharedmemory) to release the
additional memory it allocated. Note that only bus-master DMA NICs can call
**NdisMAllocateSharedMemoryAsyncEx** and export
*MiniportSharedMemoryAllocateComplete*. This functionality is not supported for subordinate DMA
NICs.

**NdisMAllocateSharedMemory** and
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) are the only
**Ndis*Xxx*** functions that can be called to allocate host memory that is shared between the driver, which
uses virtual addresses, and a NIC, which uses the corresponding logical addresses.

A miniport driver should align the buffers it allocates from shared cached memory on an integral of
the host data-cache-line boundary to prevent cache-line tearing during DMA. Cache-line tearing can cause
data-integrity problems in the driver or degrade the driver's (and the system's) I/O performance by
requiring excessive data-cache flushing to maintain data integrity.
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) can call
[NdisMGetDmaAlignment](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetdmaalignment) to determine the
alignment boundary in the current platform for device-accessible buffers that the driver will set up
within an allocated range of shared memory.

A miniport driver should set a limit on how much shared memory it can allocate. This limit is
driver-specific and should be high enough so that the driver does not run out of buffers. Do not set a
limit that is excessively high, as this could result in a wasteful consumption of shared memory that
could reduce system performance.

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) also might call
[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount) before
it calls
**NdisMAllocateSharedMemory** if the driver writer decides to allocate a larger shared memory block in
multiprocessor machines on the assumption that any SMP machine is likely to be a network server with
higher network-transfer demands on the NIC than a workstation.

If its call to
**NdisMAllocateSharedMemory** fails,
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) can call again requesting a smaller allocation. However, if
*MiniportInitializeEx* cannot allocate sufficient shared memory for the NIC, it must release all
resources it has already allocated and fail initialization.

If the miniport driver subsequently indicates receives with
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists), it must allocate some number of buffer descriptors from buffer
pool that map the NIC's receive buffers in the shared memory block.

If the allocated memory is cached and, therefore, needs to be flushed on transfers, the miniport
driver must call
[NdisAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatemdl) to allocate an
NDIS_BUFFER-type descriptor for the shared memory range. The miniport driver must call
[KeFlushIoBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushiobuffers) with this buffer descriptor
to perform such a flush.

If a miniport driver calls
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) or
**NdisMAllocateSharedMemory**, it must release all outstanding allocations with one or more calls to
[NdisMFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreesharedmemory) when a NIC is
removed, that is, when its
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function is called.

## See also

[KeFlushIoBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushiobuffers)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete)

[NdisAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatemdl)

[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist)

[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex)

[NdisMFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreesharedmemory)

[NdisMGetDmaAlignment](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetdmaalignment)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount)