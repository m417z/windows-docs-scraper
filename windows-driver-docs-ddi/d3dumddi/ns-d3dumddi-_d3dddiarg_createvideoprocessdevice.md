# _D3DDDIARG_CREATEVIDEOPROCESSDEVICE structure

## Description

The D3DDDIARG_CREATEVIDEOPROCESSDEVICE structure describes a Microsoft DirectX Video Acceleration (DirectX VA) video processing device to create.

## Members

### `pVideoProcGuid` [in]

A pointer to the GUID that represents a DirectX VA video processing device to create. The Microsoft Direct3D runtime can call the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to query for the video processing GUIDs that the driver supports.

### `VideoDesc` [in]

The [DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure for the video stream that the video processing device should process.

### `RenderTargetFormat` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the render target for the video processing device.

### `MaxSubStreams` [in]

The maximum number of video substreams that can be sent to the video processing device. If this value is set to zero, the device never receives any video substreams.

### `hVideoProcess` [in/out]

A handle to the video processing device. The user-mode display driver must set this handle to a value that the Microsoft Direct3D runtime can use to identify the video processing device in subsequent calls.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)