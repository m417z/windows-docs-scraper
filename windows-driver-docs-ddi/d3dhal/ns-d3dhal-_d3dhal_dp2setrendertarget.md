# _D3DHAL_DP2SETRENDERTARGET structure

## Description

The D3DHAL_DP2SETRENDERTARGET structure is used with the D3DDP2OP_SETRENDERTARGET opcode to map a new rendering target surface and depth buffer in the current context.

## Members

### `hRenderTarget`

Specifies a handle to the rendering target.

### `hZBuffer`

Specifies a handle to the depth buffer.

## Remarks

The driver should carry out the following tasks in response to a D3DDP2OP_SETRENDERTARGET opcode in the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) command stream:

1. Store the rendering target identified by **hRenderTarget** in the driver's context.
2. Store the depth buffer identified by **hZBuffer** in the driver's context.

See the *p3samp* sample driver that ships with the Microsoft Windows Driver Development Kit (DDK) for more implementation details.

## See also

D3DDP2OP_SETRENDERTARGET

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)