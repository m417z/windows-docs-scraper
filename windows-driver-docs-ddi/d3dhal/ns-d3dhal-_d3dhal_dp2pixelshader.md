# _D3DHAL_DP2PIXELSHADER structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2PIXELSHADER structure is used to set the current pixel shader, or delete a pixel shader, depending on the opcode received (D3DDP2OP_SETPIXELSHADER or D3DDP2OP_DELETEPIXELSHADER) by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwHandle`

Specifies the handle to the pixel shader that is assigned by the runtime. For delete requests, the handle is guaranteed to be subzero. For set requests, the handle can be zero. If set to zero, the driver should reset any programmable pixel state and revert to fixed function pixel processing behavior (for example, by using render states).

## Remarks

When switching from fixed function pixel processing to programmable vertex processing the values of, for example, legacy render states and texture stage states should be preserved. If and when a switch from programmable to fixed function pixel processing occurs (the driver receives a D3DDP2OP_SETPIXELSHADER with a shader handle of zero), that preserved state should be restored.

When switching between programmable shaders, any constant register that has a value specified in the definition of that shader should be set to that value. The values of all other constant registers should remain unchanged.

## See also

[D3DHAL_DP2CREATEPIXELSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createpixelshader)

[D3DHAL_DP2SETPIXELSHADERCONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setpixelshaderconst)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)