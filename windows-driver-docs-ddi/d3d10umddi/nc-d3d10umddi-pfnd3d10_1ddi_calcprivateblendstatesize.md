# PFND3D10_1DDI_CALCPRIVATEBLENDSTATESIZE callback function

## Description

The **CalcPrivateBlendStateSize(D3D10_1)** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a blend state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pBlendDesc* [in]

A pointer to a [D3D10_1_DDI_BLEND_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1_ddi_blend_desc) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateBlendStateSize(D3D10_1)** returns the size of the memory region that the driver requires for creating a blend state.

## See also

[D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)

[D3D10_1_DDI_BLEND_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1_ddi_blend_desc)