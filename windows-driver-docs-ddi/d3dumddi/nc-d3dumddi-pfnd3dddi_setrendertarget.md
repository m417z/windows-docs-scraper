# PFND3DDDI_SETRENDERTARGET callback function

## Description

The *SetRenderTarget* function sets the render target surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETRENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setrendertarget) structure that describes the render target surface.

## Return value

*SetRenderTarget* returns S_OK or an appropriate error result if the render target surface is not successfully set.

## See also

[D3DDDIARG_SETRENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setrendertarget)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)