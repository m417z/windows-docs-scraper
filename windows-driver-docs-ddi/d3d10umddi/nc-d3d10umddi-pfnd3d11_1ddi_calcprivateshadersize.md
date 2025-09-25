# PFND3D11_1DDI_CALCPRIVATESHADERSIZE callback function

## Description

Determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `pShaderCode`

A pointer to an array of CONST UINT tokens that make up the shader code.

### `unnamedParam3`

*pSignatures* [in]

A pointer to a [D3D11_1DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_stage_io_signatures) structure that makes up the shader's signature.

## Return value

The size of the memory region that the driver requires for creating a shader.

## See also

[D3D11_1DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_stage_io_signatures)