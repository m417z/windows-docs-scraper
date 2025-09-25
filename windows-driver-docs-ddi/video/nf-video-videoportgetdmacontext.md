# VideoPortGetDmaContext function

## Description

The **VideoPortGetDmaContext** function is **obsolete** in Windows 2000 and later.

**VideoPortGetDmaContext** gets the context previously associated with the specified DMA handle.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pDma` [in]

Pointer to a DMA handle. To obtain the appropriate DMA handle, use the value in the **OutputBuffer** member of the *pVrp* parameter after [VideoPortLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages) returns.

## Return value

**VideoPortGetDmaContext** always returns **NULL**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.