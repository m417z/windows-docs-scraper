# VideoPortAllocateBuffer function

## Description

The **VideoPortAllocateBuffer** function is **obsolete** in Windows 2000 and later. In its place, video miniport drivers should instead use [VideoPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatepool).

**VideoPortAllocateBuffer** allocates a buffer of paged pool memory.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Size` [in]

Specifies the size of the buffer to allocate, in bytes.

### `Buffer` [out]

Is the location in which the video port driver returns a pointer to a pointer to the allocated pool memory.

## Return value

**VideoPortAllocateBuffer** returns NO_ERROR when it successfully completes the allocation request, or ERROR_NOT_ENOUGH_MEMORY if it is unable to allocate a buffer of *Size* bytes. A return value of ERROR_INSUFFICIENT_BUFFER indicates that a miniport driver has exceeded its maximum allowable allocation of memory.

## Remarks

A miniport driver can use the return value of this function to determine whether the buffer allocation succeeded.

## See also

[VideoPortReleaseBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasebuffer)