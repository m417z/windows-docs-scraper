# VideoPortReleaseBuffer function

## Description

The **VideoPortReleaseBuffer** function is **obsolete** in Windows 2000 and later. In its place, video miniport drivers should instead use [VideoPortFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportfreepool).

**VideoPortReleaseBuffer** deallocates a block of paged pool memory.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Buffer` [in]

Specifies the address of the block of pool memory being deallocated.

## Return value

None

## Remarks

This function releases memory allocated by [VideoPortAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatebuffer). A miniport driver must not access the memory block to which *Buffer* points after it has been freed.

## See also

[VideoPortAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatebuffer)