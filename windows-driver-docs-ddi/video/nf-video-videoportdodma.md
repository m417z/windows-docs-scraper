# VideoPortDoDma function

## Description

The **VideoPortDoDma** function is **obsolete** in Windows 2000 and later.

**VideoPortDoDma** causes the miniport driver's *HwVidStartDma* function to be called.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pDma` [in]

Specifies a non-**NULL** DMA handle. This handle was obtained from a prior call to **VideoPortDoDma** or from the **OutputBuffer** member of the [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet) returned by [VideoPortLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages).

### `DmaFlags` [in]

Specifies the action to be performed. This member can be one of the following values:

|Value|Meaning|
|--- |--- |
|VideoPortKeepPagesLockedVideoPortDmaInitOnly|If possible, the video port driver should keep the memory locked for subsequent DMA operation(s).|
|VideoPortUnlockAfterDma|The video port driver should unlock the memory after the DMA operation is performed.|

## Return value

**VideoPortDoDma** always returns **NULL**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.

## See also

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)

[VideoPortLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages)