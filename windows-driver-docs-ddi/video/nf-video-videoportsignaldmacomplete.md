# VideoPortSignalDmaComplete function

## Description

The **VideoPortSignalDmaComplete** function is **obsolete** in Windows 2000 and later.

**VideoPortSignalDmaComplete** indicates to the video miniport driver whether the current DMA transfer is complete.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pDmaHandle` [in]

Pointer to a DMA handle. To obtain the appropriate DMA handle, use the value in the **OutputBuffer** member of the *pVrp* parameter after [VideoPortLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages) returns.

## Return value

**VideoPortSignalDmaComplete** always returns **FALSE**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.