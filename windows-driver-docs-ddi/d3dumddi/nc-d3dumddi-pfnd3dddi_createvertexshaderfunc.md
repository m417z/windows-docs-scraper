# PFND3DDDI_CREATEVERTEXSHADERFUNC callback function

## Description

The **CreateVertexShaderFunc** function converts vertex shader code into a hardware-specific format and associates the code with a shader handle.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCode* [in]

An array of CONST UINT tokens that make up the vertex shader code.

### `unnamedParam3`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEVERTEXSHADERFUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createvertexshaderfunc) structure that retrieves the shader handle that is associated with the vertex shader code that is specified by **pCode**.

## Return value

**CreateVertexShaderFunc** returns S_OK or an appropriate error result if the vertex shader code object is not successfully created.

## Remarks

For more information about programming shader assemblers, see [Processing Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/display/processing-shader-codes).

## See also

[D3DDDIARG_CREATEVERTEXSHADERFUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createvertexshaderfunc)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)