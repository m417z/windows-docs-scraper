# _D3DDDIARG_CREATEVERTEXSHADERDECL structure

## Description

The D3DDDIARG_CREATEVERTEXSHADERDECL structure specifies a shader handle to associate with the vertex shader declaration.

## Members

### `NumVertexElements` [in]

The number of vertex elements in the array that is passed to the *pVertexElements* parameter in a call to the user-mode display driver's [CreateVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderdecl) function.

### `ShaderHandle` [out]

A handle to the vertex shader declaration.

## Remarks

The handle value in the **ShaderHandle** member is guaranteed to be nonzero.

For more information about programming shader assemblers, see [Processing Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/display/processing-shader-codes).

## See also

[CreateVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderdecl)