# DXGKDDI_DISPATCH_IO_REQUEST callback function

## Description

The *DxgkDdiDispatchIoRequest* function handles I/O control (IOCTL) requests.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `VidPnSourceId` [in]

An integer that identifies the video present source associated with the I/O request.

### `VideoRequestPacket` [in]

A pointer to a [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet) structure that describes the I/O request.

## Return value

*DxgkDdiDispatchIoRequest* returns STATUS_SUCCESS if it succeeds; otherwise it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The *DxgkDdiDispatchIoRequest* function should be made pageable.

## See also

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)