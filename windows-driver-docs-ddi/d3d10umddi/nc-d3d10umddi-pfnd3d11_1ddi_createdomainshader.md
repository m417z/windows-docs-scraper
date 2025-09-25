# PFND3D11_1DDI_CREATEDOMAINSHADER callback function

## Description

Creates a domain shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `pShaderCode` [in]

A pointer to an array of CONST UINT tokens that form the shader code. The first token in the shader code stream is always the version token. The next token in the stream is the length token that determines the end of the shader code stream. For more information about the format of Direct3D version 11 shader code, see the comments inside the D3d11tokenizedprogramformat.hpp header file that is included with the WDK.

### `unnamedParam3`

*hShader* [in]

A handle to the driver's private data for the domain shader. The driver returns the size, in bytes, of the memory region that the Microsoft Direct3D runtime must allocate for the private data from a call to the driver's [CalcPrivateTessellationShaderSize(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivatetessellationshadersize) function. The handle is just a pointer to a region of memory, the size of which the driver requested. The driver uses this region of memory to store internal data structures that are related to its tessellation-shader object.

### `unnamedParam4`

*hRTShader* [in]

A handle to the domain shader that the driver should use when it calls back into the Direct3D runtime.

### `unnamedParam5`

*pSignatures* [in]

A pointer to a [D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_tessellation_io_signatures) structure that forms the tessellation-shader's signature.

## See also

[CalcPrivateTessellationShaderSize(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivatetessellationshadersize)

[D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_tessellation_io_signatures)