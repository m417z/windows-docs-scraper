# PFND3DDDI_SETPIXELSHADERCONSTI callback function

## Description

The *SetPixelShaderConstI* function sets one or more pixel shader constant registers with integer values.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETPIXELSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpixelshaderconst) structure that describes how to set the pixel shader constant registers.

### `unnamedParam3`

*pRegisters* [in]

A pointer to a buffer that contains INT values to copy.

## Return value

*SetPixelShaderConstI* returns S_OK or an appropriate error result if the pixel shader constant registers are not successfully set with integer values.

## See also

[D3DDDIARG_SETPIXELSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpixelshaderconst)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)