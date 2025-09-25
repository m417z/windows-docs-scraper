# VideoPortSetDmaContext function

## Description

The **VideoPortSetDmaContext** function is **obsolete** in Windows 2000 and later.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pDma` [out]

Pointer to a DMA handle.

### `InstanceContext` [in]

Pointer to the DMA context to set.

## Return value

None

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.