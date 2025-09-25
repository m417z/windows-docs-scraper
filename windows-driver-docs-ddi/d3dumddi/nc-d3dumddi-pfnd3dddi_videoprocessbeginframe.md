# PFND3DDDI_VIDEOPROCESSBEGINFRAME callback function

## Description

The *VideoProcessBeginFrame* function notifies the user-mode display driver that processing of a video frame can begin on the specified Microsoft DirectX Video Accelerator (VA) video processing device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hVideoProcess` [in]

The handle to the DirectX VA video processing device that should start processing the video frame. The [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function created this handle.

## Return value

*VideoProcessBeginFrame* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Video frame processing successfully began.|
|E_OUTOFMEMORY|VideoProcessBeginFrame could not allocate the required memory for it to complete.|

## Remarks

The *VideoProcessBeginFrame* function notifies the user-mode display driver that its [VideoProcessBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessblt) function can be called on the specified video processing device.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[VideoProcessBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessblt)