# VideoPortStartDma function

## Description

The **VideoPortStartDma** function prepares the system for a DMA operation. As soon as the appropriate resource is available, **VideoPortStartDma** creates a scatter/gather list, initializes the system resources, and calls the video miniport driver-supplied [HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma) routine to carry out the DMA operation.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VpDmaAdapter` [in]

Pointer to the [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure that represents the bus-master adapter. This structure is returned from a call to [VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter).

### `Mdl` [in]

Pointer to the [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) that describes the buffer. This pointer is returned from a call to the video port driver's [VideoPortLockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockbuffer) function.

### `Offset` [in]

Specifies the byte offset in the buffer at which the DMA operation begins. The *Mdl* parameter describes this buffer.

### `pLength` [in, out]

Pointer to a variable that specifies the requested transfer size, in bytes, and that will receive the actual size to be transferred. The variable will be updated when either of the following events occurs: **VideoPortStartDma** returns or [HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma) is called. It is therefore safe to read this variable from within *HwVidExecuteDma* even before **VideoPortStartDma** returns.

### `ExecuteDmaRoutine` [in]

Pointer to a miniport driver-supplied [HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma) callback routine. **VideoPortStartDma** calls this routine to program the hardware registers and start the actual DMA operation.

### `Context` [in]

Pointer to the driver-determined context to be passed to the miniport driver's *HwVidExecuteDma* callback routine. Since the *HwVidExecuteDma* callback routine runs at DISPATCH_LEVEL, the data that *Context* points to should be in nonpaged memory.

### `WriteToDevice` [in]

Specifies the direction of the DMA transfer. A value of **TRUE** denotes a transfer from the buffer to the device, and a value of **FALSE** denotes a transfer from the device to the buffer.

## Return value

**VideoPortStartDma** returns one of the following status codes:

|Return code|Description|
|--- |--- |
|NO_ERROR|The operation was successfully carried out.|
|ERROR_NOT_ENOUGH_MEMORY|There are not enough system resources for this operation.|

## Remarks

To prepare for a DMA-transfer operation, **VideoPortStartDma**:

* Flushes the memory region in the host processor's caches.
* Builds a scatter/gather list.
* Calls the video miniport driver's [HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma) callback.

It is possible that not all of the requested data has been transferred, since the actual amount of memory transferred is limited by the number of map registers available to the driver. Callers of this function should inspect the actual transfer size returned at *pLength* to determine whether additional data remains to be transferred. If so, the miniport driver should call **VideoPortStartDma** (and subsequently, [VideoPortCompleteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcompletedma)) as many times as necessary to fulfill the entire transfer request.

## See also

[HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma)

[VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85))

[VideoPortCompleteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcompletedma)

[VideoPortGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdmaadapter)