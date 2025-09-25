# _D3DHAL_DP2CREATEVERTEXSHADERDECL structure

## Description

 DirectX 9.0 and later versions only.

The D3DHAL_DP2CREATEVERTEXSHADERDECL structure is used to create a vertex shader declaration when a D3DDP2OP_CREATEVERTEXSHADERDECL opcode is received by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwHandle`

Specifies the handle to the vertex shader declaration that is assigned by the runtime. This value is guaranteed to be subzero. Flexible vertex format (FVF) codes are part of the shader declaration handle namespace. If bit zero of the handle is set, the handle passed is a shader declaration handle; otherwise, an FVF code.

### `dwNumVertexElements`

Specifies the number of vertex elements that make up the shader declaration.

## Remarks

When the runtime calls the driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) function with this token, the driver should validate the given shader declaration and report success or failure accordingly.

An array of D3DVERTEXELEMENT9 structures that define the vertex elements that make up the shader declaration follow D3DHAL_DP2CREATEVERTEXSHADERDECL in the command stream. For more information about D3DVERTEXELEMENT9, see the latest DirectX SDK documentation.

The DirectX 9.0 runtime specifies a legacy FVF code or a declaration handle in the **dwHandle** member. The runtime indicates a declaration handle by setting bit 0 of the handle.

## See also

D3DDP2OP_CREATEVERTEXSHADERDECL

[D3DHAL_DP2VERTEXSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2vertexshader)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)