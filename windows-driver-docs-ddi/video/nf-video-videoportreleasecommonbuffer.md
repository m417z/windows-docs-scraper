# VideoPortReleaseCommonBuffer function

## Description

The **VideoPortReleaseCommonBuffer** function frees a common buffer that was previously allocated by [VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VpDmaAdapter` [in]

Pointer to the [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that represents the bus-master adapter. This is the structure returned after a call to [VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter).

### `Length` [in]

Specifies the number of bytes of memory to be freed.

### `LogicalAddress` [in]

Specifies the logical address of the buffer to be freed.

### `VirtualAddress` [in]

Pointer to the corresponding virtual address of the allocated memory range. This value was obtained in a prior call to [VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer).

### `CacheEnabled` [in]

Indicates whether the allocated memory is cached. A value of **TRUE** indicates that the allocated memory is cached.

## Return value

None

## Remarks

The parameters passed to **VideoPortFreeCommonBuffer** must match exactly those passed to and returned from **VideoPortAllocateCommonBuffer**. A driver cannot free only part of an allocated common buffer.

## See also

[VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85))

[VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer)

[VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter)