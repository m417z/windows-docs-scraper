# VideoPortUnlockPages function

## Description

The **VideoPortUnlockPages** function is **obsolete** in Windows 2000 and later. Use [VideoPortUnlockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunlockbuffer) in place of this function.

**VideoPortUnlockPages** releases memory used for packet-based DMA.

## Parameters

### `hwDeviceExtension`

Pointer to the miniport driver's device extension.

### `pDma`

Specifies a non-**NULL** DMA handle.

## Return value

**VideoPortUnlockPages** always returns **TRUE**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.

This function can be called only within the context of a DMA IOCTL. It cannot be called from an ISR or DPC.

## See also

[VideoPortUnlockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunlockbuffer)