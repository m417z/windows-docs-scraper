# _D3DDDIARG_SETVIDEOPROCESSRENDERTARGET structure

## Description

The D3DDDIARG_SETVIDEOPROCESSRENDERTARGET structure describes the render target surface for video processing.

## Members

### `hVideoProcess` [in]

A handle to the Microsoft DirectX Video Acceleration (DirectX VA) video processing device. The user-mode display driver returns this handle in a call to its [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function.

### `hRenderTarget` [in]

A handle to the render target surface for video processing.

### `SubResourceIndex` [in]

An index into the resource for the render target surface.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[SetVideoProcessRenderTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvideoprocessrendertarget)