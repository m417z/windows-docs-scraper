# VideoPortPutDmaAdapter function

## Description

The **VideoPortPutDmaAdapter** function frees a [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that was previously allocated by a call to [VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VpDmaAdapter` [in]

Pointer to the [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that represents the bus-master adapter.

## Return value

None

## Remarks

A miniport driver should call this function only if it will not use the same VP_DMA_ADAPTER structure again.

## See also

[VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85))

[VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter)