# PFND3DDDI_SETDEPTHSTENCIL callback function

## Description

The *SetDepthStencil* function sets the depth buffer in the driver's context.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETDEPTHSTENCIL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdepthstencil) structure that specifies the depth buffer.

## Return value

*SetDepthStencil* returns S_OK or an appropriate error result if the depth buffer is not successfully set.

## Remarks

The user-mode display driver should store the depth buffer in the driver's context when the Microsoft Direct3D runtime calls *SetDepthStencil*.

## See also

[D3DDDIARG_SETDEPTHSTENCIL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdepthstencil)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)