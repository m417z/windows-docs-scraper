# _D3DHAL_DP2CREATEVERTEXSHADERFUNC structure

## Description

 DirectX 9.0 and later versions only.

The D3DHAL_DP2CREATEVERTEXSHADERFUNC structure is used to create a vertex shader code object when a D3DDP2OP_CREATEVERTEXSHADERFUNC opcode is received by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwHandle`

Specifies the handle to the vertex shader code that is assigned by the runtime. This value is guaranteed to be subzero.

### `dwSize`

Specifies the shader code size in bytes.

## Remarks

When the runtime calls the driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) function with this token, the driver should validate the given shader code and report success or failure accordingly.

Vertex shader code follows D3DHAL_DP2CREATEVERTEXSHADERFUNC in the command stream. See [Direct3D Driver Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/) for information about the format of individual shader code and the tokens that comprise each shader code.

The DirectX 9.0 runtime sets **dwHandle** to zero to indicate a fixed function pipeline.

## See also

D3DDP2OP_CREATEVERTEXSHADERFUNC

[D3DHAL_DP2CREATEVERTEXSHADERDECL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createvertexshaderdecl)

[D3DHAL_DP2VERTEXSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2vertexshader)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)