# _D3DDDIARG_SETPIXELSHADERCONST structure

## Description

The D3DDDIARG_SETPIXELSHADERCONST structure describes how to set the pixel shader constant registers.

## Members

### `Register` [in]

The index of the first pixel shader constant register whose value is set.

### `Count` [in]

The number of constant registers to set and, therefore, the number of values in the array that is passed in the *pRegisters* parameter in the call to the user-mode display driver's [SetPixelShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconst), [SetPixelShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconsti), or [SetPixelShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconstb) function.

## Remarks

The **Count** member specifies the following values, depending on the structure type that is used in the call to the [SetPixelShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconst), [SetPixelShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconsti), or [SetPixelShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconstb) function:

* Four-element, single-precision float vectors for the D3DDDIARG_SETPIXELSHADERCONST structure in the [SetPixelShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconst) call.
* Four-integer vectors for the D3DDDIARG_SETPIXELSHADERCONSTI structure in the [SetPixelShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconsti) call.
* Boolean values for the D3DDDIARG_SETPIXELSHADERCONSTB structure in the [SetPixelShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconstb) call.

The preceding structures are identical, as the following definitions show:

```cpp
typedef D3DDDIARG_SETPIXELSHADERCONST D3DDDIARG_SETPIXELSHADERCONSTI;
typedef D3DDDIARG_SETPIXELSHADERCONST D3DDDIARG_SETPIXELSHADERCONSTB;
```

## See also

[SetPixelShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconst)

[SetPixelShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconstb)

[SetPixelShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconsti)