# PFND3DDDI_SETVERTEXSHADERCONSTI callback function

## Description

The *SetVertexShaderConstI* function sets one or more vertex shader constant registers with integer values.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETVERTEXSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setvertexshaderconst) structure that specifies how to set the vertex shader constant registers.

### `unnamedParam3`

*pRegisters* [in]

A pointer to a buffer that contains INT values to copy.

## Return value

*SetVertexShaderConstI* returns S_OK or an appropriate error result if the vertex shader constant register is not successfully set with integer values.

## See also

[D3DDDIARG_SETVERTEXSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setvertexshaderconst)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)