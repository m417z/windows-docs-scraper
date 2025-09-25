# _D3DDDIARG_SETLIGHT structure

## Description

The D3DDDIARG_SETLIGHT structure describes how to set light properties.

## Members

### `Index` [in]

An index into an array of lights.

### `DataType` [in]

A valid bitwise OR of the following flags that indicate the type of light data:

| **Value** | **Meaning** |
|:--|:--|
| D3DDDISETLIGHT_DATA | Specifies that a pointer to a [D3DDDI_LIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_light) structure that defines light properties is supplied in the pLightProperties parameter in a call to the user-mode display driver's [SetLight](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setlight) function. |
| D3DDDISETLIGHT_ENABLE | Enables the light whose index is specified in the Index member. |
| D3DDDISETLIGHT_DISABLE | Disables the light whose index is specified in Index. |

## See also

[D3DDDI_LIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_light)

[SetLight](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setlight)