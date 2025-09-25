# PFND3DDDI_SETVERTEXSHADERFUNC callback function

## Description

The *SetVertexShaderFunc* function sets the vertex shader code so that all of the subsequent drawing operations use that code.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hShaderHandle* [in]

A handle to the vertex shader code object.

## Return value

*SetVertexShaderFunc* returns S_OK or an appropriate error result if the vertex shader code is not successfully set.

## Remarks

After setting the vertex shader code, all of the drawing operations use that code until another code is selected.

For user-mode display drivers that support vertex shaders before version 2.0, the Microsoft Direct3D runtime passes 0 in the *hShaderHandle* parameter to indicate a fixed-function pipeline. For user-mode display drivers that support vertex shader version 2.0 or later, the runtime converts Direct3D fixed-function vertex state to vertex shader version 2.0. For more information fixed-function state, see [Converting the Direct3D Fixed-Function State](https://learn.microsoft.com/windows-hardware/drivers/display/converting-the-direct3d-fixed-function-state).

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)