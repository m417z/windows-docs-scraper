# VideoPortLockPages function

## Description

The **VideoPortLockPages** function is **obsolete** in Windows 2000 and later. Use [VideoPortLockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockbuffer) in place of this function.

**VideoPortLockPages** locks the specified virtual memory and possibly performs part or all of a DMA transfer.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pVrp` [in, out]

Pointer to a [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet) structure. The miniport driver must have set **InputBuffer** and **InputBufferLength** to contain the virtual address and the size in bytes, respectively, of the memory to be locked for the transfer. This memory was allocated by the display driver and passed to the miniport driver through an IOCTL. The video port returns a pointer to and the size in bytes of the scatter/gather list in **OutputBuffer** and **OutputBufferLength**, respectively.

### `pUEvent` [in]

Pointer to a mapped user event that is to be set by the miniport driver, or **NULL**. The user event was mapped by the display driver and passed to the miniport driver through an IOCTL.

### `pDisplayEvent` [in]

Pointer to an event that is to be set by the miniport driver, or **NULL**. This event was created by and received from the display driver through an IOCTL.

### `DmaFlags` [in]

Specifies the action to be performed. This parameter must be one of the following values:

|Value|Meaning|
|--- |--- |
|VideoPortDmaInitOnly|VideoPortLockPages locks the requested memory.|
|VideoPortKeepPagesLocked|VideoPortLockPages takes no action.|
|VideoPortUnlockAfterDma|VideoPortLockPages takes no action.|

## Return value

**VideoPortLockPages** returns **TRUE** upon successful completion of the action requested of it. It returns **FALSE** if the *DmaFlags* parameter is not equal to **VideoPortDmaInitOnly**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.

**VideoPortLockPages** cannot be called from an ISR or DPC.

## See also

[VideoPortLockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockbuffer)