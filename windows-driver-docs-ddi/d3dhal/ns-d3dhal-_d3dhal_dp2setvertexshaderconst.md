# _D3DHAL_DP2SETVERTEXSHADERCONST structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2SETVERTEXSHADERCONST structure is used to set one or more of the vertex shader constant registers when the D3DDP2OP_SETVERTEXSHADERCONST opcode is received by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwRegister`

Specifies the index of the first vertex shader constant to have its value sent.

### `dwCount`

Specifies the number of constant registers to set and, therefore, the number of four element, single precision float vectors to read from the DP2 stream.

## Remarks

A start register and register count are given. One or more vectors of four single precision floating-point values immediately follow the D3DHAL_DP2SETVERTEXSHADERCONST data structure in the DP2 stream.

The runtime validates that the range of registers specified is legal given the level of vertex shader support reported to the driver. Furthermore, if the driver does not support any form of programmable vertex processing the runtime does not send this token to the driver.

## See also

D3DDP2OP_SETVERTEXSHADERCONST

[D3DHAL_DP2CREATEVERTEXSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createvertexshader)

[D3DHAL_DP2VERTEXSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2vertexshader)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)