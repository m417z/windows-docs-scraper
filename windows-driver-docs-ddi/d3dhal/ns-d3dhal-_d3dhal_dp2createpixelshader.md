# _D3DHAL_DP2CREATEPIXELSHADER structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2CREATEPIXELSHADER structure is used to create a pixel shader when a D3DDP2OP_CREATEPIXELSHADER opcode is received by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwHandle`

Specifies the handle to the pixel shader that is assigned by the runtime. This value is guaranteed to be subzero.

### `dwCodeSize`

Specifies the size, in bytes, of the shader code following this data structure in the DP2 stream.

## Remarks

The runtime generates a handle for this shader before calling the driver. The shader code itself follows the D3DHAL_DP2CREATEPIXELSHADER in the DP2 stream. See [Direct3D Driver Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/) for information about the format of an individual shader code and the tokens that comprise each shader code.

Before calling the driver, the runtime validates the pixel shader code to ensure that it is legal for the specified shader language version.

It is important to note that the creation of a pixel shader does not imply the setting of the current shader.

## See also

D3DDP2OP_CREATEPIXELSHADER

[D3DHAL_DP2PIXELSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2pixelshader)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)