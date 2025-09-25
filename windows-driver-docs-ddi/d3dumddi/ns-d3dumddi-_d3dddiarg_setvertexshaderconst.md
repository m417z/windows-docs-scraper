# _D3DDDIARG_SETVERTEXSHADERCONST structure

## Description

The D3DDDIARG_SETVERTEXSHADERCONST structure describes how to set vertex shader constant registers.

## Members

### `Register` [in]

The index of the first vertex shader constant register whose value is set.

### `Count` [in]

The number of constant registers to set and, therefore, the number of values in the array that is passed in the *pRegisters* parameter in the call to the user-mode display driver's [SetVertexShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconst), [SetVertexShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconsti), or [SetVertexShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconstb) function.

## Remarks

The **Count** member specifies the following values, depending on the structure type that is used in the call to the [SetVertexShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconst), [SetVertexShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconsti), or [SetVertexShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconstb) function:

* Four-element, single-precision float vectors for the D3DDDIARG_SETVERTEXSHADERCONST structure in the [SetVertexShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconst) call.
* Four-integer vectors for the D3DDDIARG_SETVERTEXSHADERCONSTI structure in the [SetVertexShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconsti) call.
* Boolean values for the D3DDDIARG_SETVERTEXSHADERCONSTB structure in the [SetVertexShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconstb) call.

The preceding structures are identical, as the following definitions show:

```cpp
typedef D3DDDIARG_SETVERTEXSHADERCONST D3DDDIARG_SETVERTEXSHADERCONSTI;
typedef D3DDDIARG_SETVERTEXSHADERCONST D3DDDIARG_SETVERTEXSHADERCONSTB;
```

## See also

[SetVertexShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconst)

[SetVertexShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconstb)

[SetVertexShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconsti)