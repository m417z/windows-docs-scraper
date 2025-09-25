# VideoPortGetMdl function

## Description

The **VideoPortGetMdl** function is **obsolete** in Windows 2000 and later.

**VideoPortGetMdl** retrieves the memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) that represents the page table of the locked buffer.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pDma` [in]

Is a handle to the DMA context being queried. This handle was obtained from [VideoPortLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages) or [VideoPortDoDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdodma).

## Return value

**VideoPortGetMdl** returns *pDma*, for compatibility reasons.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.