# PFND3DDDI_SETVERTEXSHADERDECL callback function

## Description

The *SetVertexShaderDecl* function sets the vertex shader declaration so that all of the subsequent drawing operations use that declaration.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hShaderHandle* [in]

A handle to the vertex shader declaration object.

## Return value

*SetVertexShaderDecl* returns S_OK or an appropriate error result if the vertex shader declaration is not successfully set.

## Remarks

After setting the vertex shader declaration, all of the drawing operations use that declaration until another declaration is selected.

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)