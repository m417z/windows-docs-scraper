# _D3DHAL_DP2SETPIXELSHADERCONST structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2SETPIXELSHADERCONST structure is used to set one or more of the pixel shader constant registers when the D3DDP2OP_SETPIXELSHADERCONST opcode is received by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwRegister`

Specifies the index of the first register to set.

### `dwCount`

Specifies the number of registers to set. Immediately following this data structure in the DP2 stream are **dwCount** vectors of four single precision floating-point numbers. This is the data to copy to the target registers.

## Remarks

The runtime passes the first register to set and the number of registers to set. The actual data to copy to those registers consists of vectors of four, single precision floating-point numbers. These vectors (the same number as there are registers to set) follow this token and its associated data structure in the DP2 stream.

The runtime validates that the specified register range lies within the legal range for the version of the current pixel shader.

## See also

D3DDP2OP_SETPIXELSHADERCONST

[D3DHAL_DP2CREATEPIXELSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createpixelshader)

[D3DHAL_DP2PIXELSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2pixelshader)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)