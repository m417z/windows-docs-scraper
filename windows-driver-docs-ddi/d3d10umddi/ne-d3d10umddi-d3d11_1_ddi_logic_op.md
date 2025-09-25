# D3D11_1_DDI_LOGIC_OP enumeration

## Description

Indicates shader logic operations used in a blend state. In the following notation, the output value of each logic operation is given in terms of these values:

* *s* is the pixel shader output
* *d* is the contents of the render target view (RTV)

## Constants

### `D3D11_1_DDI_LOGIC_OP_CLEAR`

0

### `D3D11_1_DDI_LOGIC_OP_SET`

1

### `D3D11_1_DDI_LOGIC_OP_COPY`

*s*

### `D3D11_1_DDI_LOGIC_OP_COPY_INVERTED`

~*s*

### `D3D11_1_DDI_LOGIC_OP_NOOP`

*d*

### `D3D11_1_DDI_LOGIC_OP_INVERT`

~*d*

### `D3D11_1_DDI_LOGIC_OP_AND`

*s* AND *d*

### `D3D11_1_DDI_LOGIC_OP_NAND`

~(*s* AND *d*)

### `D3D11_1_DDI_LOGIC_OP_OR`

*s* OR *d*

### `D3D11_1_DDI_LOGIC_OP_NOR`

~(*s* OR *d*)

### `D3D11_1_DDI_LOGIC_OP_XOR`

*s* ^ *d*

### `D3D11_1_DDI_LOGIC_OP_EQUIV`

~(*s* ^ *d*)

### `D3D11_1_DDI_LOGIC_OP_AND_REVERSE`

*s* AND ~*d*

### `D3D11_1_DDI_LOGIC_OP_AND_INVERTED`

~*s* AND *d*

### `D3D11_1_DDI_LOGIC_OP_OR_REVERSE`

*s* OR ~*d*

### `D3D11_1_DDI_LOGIC_OP_OR_INVERTED`

~*s* OR *d*

## Remarks

The **D3D11_1_DDI_LOGIC_OP** blend state logic operations are specified by the [**D3D11_1_DDI_BLEND_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_blend_desc).**LogicOp** member in a call to the [**CreateBlendState(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createblendstate) function.

## See also

[**CreateBlendState(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createblendstate)

[**D3D11_1_DDI_BLEND_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_blend_desc)