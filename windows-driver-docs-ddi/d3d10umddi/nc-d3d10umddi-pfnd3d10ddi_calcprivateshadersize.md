# PFND3D10DDI_CALCPRIVATESHADERSIZE callback function

## Description

The **CalcPrivateShaderSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `pShaderCode`

*pShaderCode* [in]

An array of CONST UINT tokens that make up the shader code.

### `unnamedParam3`

*pSignatures* [in]

A pointer to a [D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures) structure that makes up the shader's signature.

## Return value

*CalcPrivateShaderSize* returns the size of the memory region that the driver requires for creating a shader.

## See also

[D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)