# NdisAllocateMdl function

## Description

The
**NdisAllocateMdl** function allocates an MDL that describes the memory buffer at the specified virtual
address.

## Parameters

### `NdisHandle` [in]

An NDIS handle that was obtained during caller initialization. For more information, see
[Obtaining Pool Handles](https://learn.microsoft.com/windows-hardware/drivers/network/obtaining-pool-handles).

### `VirtualAddress` [in]

A pointer to the base virtual address of the buffer that the MDL is to describe.

**Important**

The **VirtualAddress** parameter for **NdisAllocateMdl** only accepts memory from the nonpaged pool. In other words, it requires memory from [ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)*(NonPagedNx), [NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority), or [NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory). In particular, it should **not** be used with memory from the stack, paged pool, driver global data, or other memory regions.

If a driver needs to build an MDL for one of these non-nonpaged pool regions, it should use the appropriate kernel APIs for that type of memory, such as [IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl) combined with [MmProbeAndLockPages.](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

### `Length` [in]

The size, in bytes, of the memory buffer.

## Return value

**NdisAllocateMdl** returns a pointer to the allocated MDL. If the allocation fails, the return value
is **NULL**.

## Remarks

All MDLs that are allocated by calling
**NdisAllocateMdl** must be freed by calling the
[NdisFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreemdl) function.

**NdisAllocateMdl** allocates memory and builds the MDL in one step. This process is different from
[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl), which only allocates memory for
the MDL, meaning the caller must build the MDL by calling either
[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool) or
[MmProbeAndLockPages.](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

## See also

[ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)

[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)

[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreemdl)

[NdisMAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemory)