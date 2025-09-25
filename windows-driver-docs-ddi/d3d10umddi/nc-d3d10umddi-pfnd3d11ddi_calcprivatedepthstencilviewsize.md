# PFND3D11DDI_CALCPRIVATEDEPTHSTENCILVIEWSIZE callback function

## Description

The **CalcPrivateDepthStencilViewSize(D3D11)** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a depth-stencil view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateDepthStencilView* [in]

A pointer to a [D3D11DDIARG_CREATEDEPTHSTENCILVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdepthstencilview) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateDepthStencilViewSize(D3D11)** returns the size of the memory region that the driver requires to create a depth-stencil view.

## Remarks

## See also

[D3D11DDIARG_CREATEDEPTHSTENCILVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdepthstencilview)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)