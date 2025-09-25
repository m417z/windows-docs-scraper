# _D3DDDIARG_CREATEVERTEXSHADERFUNC structure

## Description

The D3DDDIARG_CREATEVERTEXSHADERFUNC structure specifies a shader handle to associate with vertex shader code.

## Members

### `Size` [in]

The size, in bytes, of the vertex shader code that is passed to the *pCode* parameter in a call to the user-mode display driver's [CreateVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderfunc) function.

### `ShaderHandle` [out]

A handle to the vertex shader code.

## Remarks

For more information about programming shader assemblers, see [Processing Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/display/processing-shader-codes).

## See also

[CreateVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderfunc)