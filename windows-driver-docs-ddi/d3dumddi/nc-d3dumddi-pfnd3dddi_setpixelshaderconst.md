# PFND3DDDI_SETPIXELSHADERCONST callback function

## Description

The *SetPixelShaderConst* function sets one or more pixel shader constant registers with floating-point values.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETPIXELSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpixelshaderconst) structure that describes how to set the pixel shader constant registers.

### `unnamedParam3`

*pRegisters* [in]

A pointer to a buffer that contains 4-float vectors to copy.

## Return value

*SetPixelShaderConst* returns S_OK or an appropriate error result if the pixel shader constant registers are not successfully set with floating-point values.

## See also

[D3DDDIARG_SETPIXELSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpixelshaderconst)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)