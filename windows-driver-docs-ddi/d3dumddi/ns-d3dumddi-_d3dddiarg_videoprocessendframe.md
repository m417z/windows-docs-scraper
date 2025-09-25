# _D3DDDIARG_VIDEOPROCESSENDFRAME structure

## Description

The D3DDDIARG_VIDEOPROCESSENDFRAME structure specifies the Microsoft DirectX Video Accelerator (VA) video process that should stop processing a frame.

## Members

### `hVideoProcess`

A handle to the DirectX VA video process device. The user-mode display driver returns this handle in a call to its [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function.

### `pHandleComplete`

This member is reserved and should be set to **NULL**.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[VideoProcessEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessendframe)