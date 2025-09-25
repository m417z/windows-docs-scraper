# PFND3DDDI_CREATEVERTEXSHADERDECL callback function

## Description

The **CreateVertexShaderDecl** function converts the vertex shader declaration into a hardware-specific format and associates the declaration with a shader handle.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEVERTEXSHADERDECL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createvertexshaderdecl) structure that retrieves the shader handle that is associated with the vertex shader declaration that is specified by *pVertexElements*.

### `unnamedParam3`

*pVertexElements* [in]

An array of [D3DDDIVERTEXELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddivertexelement) structures that make up the vertex shader declaration.

## Return value

**CreateVertexShaderDecl** returns S_OK or an appropriate error result if the vertex shader declaration object is not successfully created.

## Remarks

The array of D3DDDIVERTEXELEMENT structures specified by *pVertexElements* defines vertex data into the pipeline.

For more information about programming shader assemblers, see [Processing Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/display/processing-shader-codes).

## See also

[D3DDDIARG_CREATEVERTEXSHADERDECL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createvertexshaderdecl)

[D3DDDIVERTEXELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddivertexelement)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)