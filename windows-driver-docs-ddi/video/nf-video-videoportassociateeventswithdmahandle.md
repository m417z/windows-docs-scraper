# VideoPortAssociateEventsWithDmaHandle function

## Description

The **VideoPortAssociateEventsWithDmaHandle** function is **obsolete** in Windows 2000 and later.

**VideoPortAssociateEventsWithDmaHandle** associates an event, which is shared by the video display driver and the video miniport driver, with a DMA handle.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pVrp` [in, out]

Pointer to a [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet).

### `MappedUserEvent` [in]

Is reserved for system use.

### `DisplayDriverEvent` [in]

Is reserved for system use.

## Return value

**VideoPortAssociateEventsWithDmaHandle** always returns **NULL**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.