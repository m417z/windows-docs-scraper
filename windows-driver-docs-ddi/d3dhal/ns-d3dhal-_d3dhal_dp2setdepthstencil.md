# _D3DHAL_DP2SETDEPTHSTENCIL structure

## Description

 DirectX 9.0 and later versions only.

The D3DHAL_DP2SETDEPTHSTENCIL structure is used to map a new depth buffer in the driver's current context when the D3DDP2OP_SETDEPTHSTENCIL operation code is received by [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `hZBuffer`

Specifies a handle to the depth buffer.

## Remarks

The driver should store the depth buffer identified by **hZBuffer** in the driver's context when the runtime sends a D3DDP2OP_SETDEPTHSTENCIL operation code in the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) command stream.

## See also

D3DDP2OP_SETDEPTHSTENCIL

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)