# _D3DDDIARG_CREATEPIXELSHADER structure

## Description

The D3DDDIARG_CREATEPIXELSHADER structure specifies a shader handle to associate with pixel shader code.

## Members

### `CodeSize` [in]

The size, in bytes, of the pixel shader code that is passed in the *pCode* parameter in a call to the user-mode display driver's [CreatePixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpixelshader) function.

### `ShaderHandle` [out]

A handle to the pixel shader code.

## Remarks

For more information about programming shader assemblers, see [Processing Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/display/processing-shader-codes).

## See also

[CreatePixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpixelshader)