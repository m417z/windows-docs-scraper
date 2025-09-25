# VideoPortAllocateContiguousMemory function

## Description

The **VideoPortAllocateContiguousMemory** function is **obsolete** in Windows 2000 and later. Video miniport drivers should use [VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer) in its place.

**VideoPortAllocateContiguousMemory** allocates a range of physically contiguous, cache-aligned memory from the nonpaged pool.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `NumberOfBytes` [in]

Specifies the size in bytes of the block of contiguous memory to be allocated.

### `HighestAcceptableAddress` [in]

Specifies the highest valid physical address the miniport driver can use. For example, if a device can only reference physical memory in the lower 16MB, this value would be set to 0x00000000FFFFFF.

## Return value

**VideoPortAllocateContiguousMemory** returns the base virtual address for the allocated memory, if the call is successful. If the request cannot be satisfied, **NULL** is returned.

## Remarks

**VideoPortAllocateContiguousMemory** can be called to allocate a contiguous block of physical memory for a long-term internal buffer.

A miniport driver that must use contiguous memory should allocate only what it needs during driver initialization because nonpaged pool is likely to become fragmented as the system runs. If the miniport driver is unloaded, it must deallocate the memory. Contiguous allocations are aligned on an integral multiple of the processor's data-cache-line size to prevent cache and coherency problems.

## See also

[VideoPortAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatebuffer)