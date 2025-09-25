# _D3DDDIARG_SETDECODERENDERTARGET structure

## Description

The D3DDDIARG_SETDECODERENDERTARGET structure describes the decode render target surface.

## Members

### `hDecode` [in]

A handle to the Microsoft DirectX Video Acceleration (DirectX VA) decode device. The user-mode display driver returns this handle in a call to its [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function.

### `hRenderTarget` [in]

A handle to the decode render target surface.

### `SubResourceIndex` [in]

An index into the resource for the decode render target surface.

## See also

[CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)

[SetDecodeRenderTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdecoderendertarget)