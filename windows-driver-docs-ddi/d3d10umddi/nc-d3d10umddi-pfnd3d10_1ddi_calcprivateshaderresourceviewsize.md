# PFND3D10_1DDI_CALCPRIVATESHADERRESOURCEVIEWSIZE callback function

## Description

The **CalcPrivateShaderResourceViewSize(D3D10_1)** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a shader resource view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateShaderResourceView* [in]

A pointer to a [D3D10_1DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddiarg_createshaderresourceview) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateShaderResourceViewSize(D3D10_1)** returns the size of the memory region that the driver requires for creating a shader resource view.

## See also

[D3D10_1DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddiarg_createshaderresourceview)

[D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)