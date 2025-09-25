# PFND3D10DDI_CALCPRIVATEDEPTHSTENCILSTATESIZE callback function

## Description

The **CalcPrivateDepthStencilStateSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a depth stencil state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDepthStencilDesc* [in]

A pointer to a [D3D10_DDI_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_depth_stencil_desc) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateDepthStencilStateSize** returns the size of the memory region that the driver requires for creating a depth stencil state.

## Remarks

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10_DDI_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_depth_stencil_desc)