# PFND3D10DDI_CREATEPIXELSHADER callback function

## Description

The **CreatePixelShader(D3D10)** function creates a pixel shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `pShaderCode`

An array of CONST UINT tokens that make up the shader code. The first token in the shader code stream is always the version token. The next token in the stream is the length token that determines the end of the shader code stream. For more information about the format of Direct3D version 10 shader code, see the comments inside the *D3d10tokenizedprogramformat.hpp* header file that is included with the WDK.

### `unnamedParam3`

*hShader* [in]

A handle to the driver's private data for the pixel shader. The driver returns the size, in bytes, of the memory region that the Microsoft Direct3D runtime must allocate for the private data from a call to the driver's [CalcPrivateShaderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshadersize) function. The handle is really just a pointer to a region of memory, the size of which the driver requested. The driver uses this region of memory to store internal data structures that are related to its shader object.

### `unnamedParam4`

*hRTShader* [in]

A handle to the pixel shader that the driver should use anytime it calls back into the Direct3D runtime.

### `unnamedParam5`

*pSignatures* [in]

A pointer to a [D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures) structure that makes up the shader's signature.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver can pass E_OUTOFMEMORY (if the driver runs out of memory) or D3DDDIERR_DEVICEREMOVED (if the device has been removed) in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime will determine that any other errors are critical. If the driver passes any errors, including D3DDDIERR_DEVICEREMOVED, the Direct3D runtime will determine that the handle is invalid; therefore, the runtime will not call the [DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader) function to destroy the handle that the *hShader* parameter specifies.

## See also

[CalcPrivateShaderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshadersize)

[D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)