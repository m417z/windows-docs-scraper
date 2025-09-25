# PEXECUTE_DMA callback function

## Description

*HwVidExecuteDma* is a miniport driver-implemented callback routine that is responsible for retrieving physical address/length pairs from a scatter/gather list, and for programming the hardware to start the actual DMA transfer.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `VpDmaAdapter`

Pointer to the [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that represents the bus-master adapter. This structure was returned by a call to [VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter).

### `SGList`

Pointer to a [VP_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_list) structure. The video port driver fills in the information in this structure, and passes this structure to the miniport driver.

### `Context`

Pointer to the driver-determined context passed in from **VideoPortStartDma**.

## Remarks

This function is available in Windows XP and later.

If the miniport driver reports that the device does not support scatter/gather, there will be only a single element in the scatter/gather list passed to this routine. The scatter/gather list is valid until [VideoPortCompleteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcompletedma) is called.

The last task that the video port driver's **VideoPortStartDma** function performs is to call the miniport driver's *HwVidExecuteDma* callback routine. It is this callback that actually carries out the DMA transfer operation.

*HwVidExecuteDma* must be in nonpaged memory and must not access any pageable code or data.

## See also

[VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85))

[VP_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_list)

[VideoPortCompleteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcompletedma)

[VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter)

[VideoPortStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstartdma)