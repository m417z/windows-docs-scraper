# VideoPortSetBytesUsed function

## Description

The **VideoPortSetBytesUsed** function is **obsolete** in Windows 2000 and later.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pDma` [in, out]

Pointer to a DMA handle. To obtain the appropriate DMA handle, use the value in the **OutputBuffer** member of the *pVrp* parameter after [VideoPortLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages) returns.

### `BytesUsed` [in]

Specifies the number of bytes written to the buffer.

## Return value

None

## See also

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)

[VideoPortGetBytesUsed](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbytesused)