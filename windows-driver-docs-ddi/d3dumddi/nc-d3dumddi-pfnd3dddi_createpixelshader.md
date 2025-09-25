# PFND3DDDI_CREATEPIXELSHADER callback function

## Description

The **CreatePixelShader** function converts pixel shader code into a hardware-specific format and associates this code with a shader handle.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCode* [in]

An array of CONST UINT tokens that make up the pixel shader code.

### `unnamedParam3`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEPIXELSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createpixelshader) structure that retrieves the shader handle that is associated with the pixel shader code that is specified by **pCode**.

## Return value

**CreatePixelShader** returns S_OK or an appropriate error result if the pixel shader code object is not successfully created.

## Remarks

For more information about programming shader assemblers, see [Processing Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/display/processing-shader-codes).

## See also

[D3DDDIARG_CREATEPIXELSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createpixelshader)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)