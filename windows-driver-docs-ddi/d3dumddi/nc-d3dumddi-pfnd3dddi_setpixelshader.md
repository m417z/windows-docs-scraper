# PFND3DDDI_SETPIXELSHADER callback function

## Description

The *SetPixelShader* function sets a pixel shader to be used in all drawing operations.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hShaderHandle* [in]

A handle to the pixel shader code object.

## Return value

*SetPixelShader* returns S_OK or an appropriate error result if the pixel shader is not successfully set.

## Remarks

All subsequent drawing operations use the given shader until another is selected.

For user-mode display drivers that support pixel shaders before version 2.0, the Microsoft Direct3D runtime passes 0 in the *hShaderHandle* parameter to indicate a fixed-function pipeline. For user-mode display drivers that support pixel shader version 2.0 or later, the runtime converts Direct3D fixed-function pixel state to pixel shader version 2.0. For more information about fixed-function state, see [Converting the Direct3D Fixed-Function State](https://learn.microsoft.com/windows-hardware/drivers/display/converting-the-direct3d-fixed-function-state).

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)