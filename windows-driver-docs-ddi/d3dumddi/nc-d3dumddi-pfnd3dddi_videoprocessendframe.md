# PFND3DDDI_VIDEOPROCESSENDFRAME callback function

## Description

The *VideoProcessEndFrame* function notifies the user-mode display driver that all of the data that is required to process the current frame was submitted.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_VIDEOPROCESSENDFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessendframe) structure that describes the DirectX VA video processor that should stop processing a frame.

## Return value

*VideoProcessEndFrame* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | Processing of the current frame is successfully completed. |
| **E_OUTOFMEMORY** | VideoProcessEndFrame cannot allocate memory required for it to complete. |

## Remarks

The *VideoProcessEndFrame* function notifies the user-mode display driver that its [VideoProcessBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessblt) function can no longer be called on the specified video processing device.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[D3DDDIARG_VIDEOPROCESSENDFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessendframe)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[VideoProcessBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessblt)