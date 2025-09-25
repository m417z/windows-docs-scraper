# VideoPortCompleteDma function

## Description

The **VideoPortCompleteDma** function flushes any data remaining in a bus-master adapter's internal cache at the end of a DMA transfer operation, and then frees the previously allocated map registers and scatter/gather list used in scatter/gather DMA operations.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VpDmaAdapter` [in]

Pointer to a [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that represents the bus-master adapter. This structure was returned by a call to [VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter).

### `VpScatterGather` [in]

Pointer to the [VP_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_list) structure previously passed to the miniport driver callback routine, [HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma).

### `WriteToDevice` [in]

Specifies the direction of the DMA transfer. A value of **TRUE** denotes a transfer from the buffer to the device, and a value of **FALSE** denotes a transfer from the device to the buffer.

## Return value

**VideoPortCompleteDma** returns NO_ERROR.

## Remarks

The video miniport driver should call **VideoPortCompleteDma** immediately to free up system resources after a DMA transfer has been completed.

It is important to note that the scatter/gather list built by **VideoPortStartDma** becomes invalid when **VideoPortCompleteDma** is called..

## See also

[VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85))

[VP_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_list)

[VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter)

[VideoPortStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstartdma)