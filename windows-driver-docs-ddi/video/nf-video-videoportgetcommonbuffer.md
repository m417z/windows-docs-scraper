# VideoPortGetCommonBuffer function

## Description

The **VideoPortGetCommonBuffer** function is **obsolete** in Windows XP and later, and is supported only for backward compatibility with existing drivers. In its place, driver writers should use [VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer).

**VideoPortGetCommonBuffer** allocates and maps system memory so that it is simultaneously accessible from both the processor and a device for common-buffer DMA operations.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `DesiredLength` [in]

Specifies the requested number of bytes of memory.

### `Alignment` [in]

Specifies the requested alignment of the buffer. The video port driver currently ignores this parameter.

### `LogicalAddress` [out]

Pointer to a variable that receives the logical address to be used by the adapter to access the allocated buffer.

### `pActualLength` [out]

Pointer to a variable that receives the actual size, in bytes, of the buffer allocated for this request.

### `CacheEnabled` [in]

Specifies whether the allocated memory can be cached.

## Return value

**VideoPortGetCommonBuffer** returns the base virtual address of the allocated buffer if successful; otherwise, returns **NULL** if the buffer cannot be allocated.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.

## See also

[VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer)