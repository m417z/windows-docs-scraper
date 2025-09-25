# _D3DHAL_DP2VERTEXSHADER structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2VERTEXSHADER structure sets the current vertex shader, or deletes a vertex shader, depending on the opcode received (D3DDP2OP_SETVERTEXSHADER or D3DDP2OP_DELETEVERTEXSHADER) by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwHandle`

A handle to the display.

## Remarks

All DirectX 8.0 level drivers must support the D3DDP2OP_SETVERTEXSHADER token because it is sent even if the driver does not support programmable vertex processing. In that case, however, the shader handle is always an FVF code indicating fixed function processing of the vertex data. The driver should use the FVF code stored in the **dwHandle** member as the format of the vertex data in stream zero. A driver that does support programmable vertex processing must examine the handle to determine whether it refers to a shader previously created with D3DDP2OP_CREATEVERTEXSHADER or an FVF code and take the appropriate action.

Pixel and vertex shaders are orthogonal. Thus, if a legacy FVF code is selected as the current vertex shader this does not imply legacy pixel processing. In order to reset pixel processing to a subprogrammable mode the current pixel shader must also be set to zero. Care should be taken in the driver to only reset vertex processing state to a fixed function mode and not pixel processing state when the vertex shader is set to an FVF code.

When switching from fixed function vertex processing to programmable vertex processing, the values of legacy render state and matrices should be preserved. If and when a switch from programmable to fixed function vertex processing occurs (the driver receives a D3DDP2OP_SETVERTEXSHADER with an FVF as the shader handle), that preserved state should be restored.

When switching between programmable shaders, any constant register that has a value specified in the definition of that shader should be set to that value. The values of all other constant registers should remain unchanged.

For D3DDP2OP_SETVERTEXSHADERDECL operations, the runtime specifies a legacy FVF code or a DirectX 9.0 declaration handle in the **dwHandle** member. The runtime indicates a DirectX 9.0 declaration handle by setting bit 0 of the handle. For D3DDP2OP_SETVERTEXSHADERFUNC operations, the runtime sets **dwHandle** to zero to indicate a fixed function pipeline.

## See also

D3DDP2OP_CREATEVERTEXSHADER

D3DDP2OP_DELETEVERTEXSHADER

D3DDP2OP_DELETEVERTEXSHADERDECL

D3DDP2OP_DELETEVERTEXSHADERFUNC

D3DDP2OP_SETSTREAMSOURCE

D3DDP2OP_SETSTREAMSOURCEUM

D3DDP2OP_SETVERTEXSHADER

D3DDP2OP_SETVERTEXSHADERDECL

D3DDP2OP_SETVERTEXSHADERFUNC

[D3DHAL_DP2CREATEVERTEXSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createvertexshader)

[D3DHAL_DP2SETVERTEXSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setvertexshaderconst)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)