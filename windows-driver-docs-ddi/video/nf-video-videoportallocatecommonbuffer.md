# VideoPortAllocateCommonBuffer function

## Description

The **VideoPortAllocateCommonBuffer** function allocates and maps system memory so that it is simultaneously accessible from both the processor and a device for common-buffer DMA operations.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VpDmaAdapter` [in]

Pointer to the [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that represents the bus-master adapter. This structure was returned by a previous call to [VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter).

### `DesiredLength` [in]

Specifies the requested number of bytes of memory.

### `LogicalAddress` [out]

Pointer to a memory location that receives the logical address to be used by the adapter to access the allocated buffer.

### `CacheEnabled` [in]

Specifies whether the allocated memory can be cached. For more information, see the description of the *CacheEnabled* parameter for [AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer).

### `Reserved` [out]

Is currently ignored by the video port driver; should be set to **NULL**.

## Return value

**VideoPortAllocateCommonBuffer** returns the base virtual address of the allocated buffer if successful; otherwise, it returns **NULL** if the buffer cannot be allocated.

## Remarks

When the buffer is no longer needed, the video miniport driver should release it by calling [VideoPortReleaseCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasecommonbuffer).

## See also

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85))

[VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter)

[VideoPortReleaseCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasecommonbuffer)