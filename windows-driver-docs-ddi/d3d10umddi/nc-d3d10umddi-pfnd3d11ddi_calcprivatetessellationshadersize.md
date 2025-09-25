# PFND3D11DDI_CALCPRIVATETESSELLATIONSHADERSIZE callback function

## Description

The **CalcPrivateTessellationShaderSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a hull or domain shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `pShaderCode`

### `unnamedParam3`

*pCode* [in]

 An array of CONST UINT tokens that form the hull-shader code or domain-shader code.

## Return value

**CalcPrivateTessellationShaderSize** returns the size of the memory region that the driver requires to create a hull or domain shader.

## Remarks

The Direct3D runtime calls the driver's **CalcPrivateTessellationShaderSize** function to calculate the size of the memory region for a hull or domain shader. This is similar to the way that the Direct3D runtime calls the driver's [CalcPrivateShaderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshadersize) function to calculate the size of the memory region for a pixel, vertex, or geometry shader (that is, a geometry shader without stream output).

## See also

[CalcPrivateShaderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshadersize)

[D3D11DDIARG_TESSELLATION_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_tessellation_io_signatures)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)