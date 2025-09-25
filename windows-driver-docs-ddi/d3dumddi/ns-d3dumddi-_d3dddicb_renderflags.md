# _D3DDDICB_RENDERFLAGS structure

## Description

The D3DDDICB_RENDERFLAGS structure identifies information about a command buffer to be rendered.

## Members

### `ResizeCommandBuffer`

A UINT value that specifies whether to resize the command buffer. The driver puts the requested size in the **NewCommandBufferSize** member of the [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render) structure.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `ResizeAllocationList`

A UINT value that specifies whether to resize the allocation list. The driver puts the requested number of elements in the **NewAllocationListSize** member of [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render).

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `ResizePatchLocationList`

A UINT value that specifies whether to resize the patch-location list. The driver puts the requested number of elements in the **NewPatchLocationListSize** member of [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render).

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `NullRendering`

A UINT value that specifies whether the graphics processing unit (GPU) should process any commands for the rendering context. The **NullRendering** bit-field flag is set to inform the GPU not to process any commands for the rendering context. The **NullRendering** bit-field flag is set only during performance investigating and debugging to simulate an infinitely fast rendering engine that still must perform the overhead of DMA buffer submission and signaling. **NullRendering** is never set during typical operations.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 28 bits (0xFFFFFFF0) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDICB_RENDERFLAGS that can hold one 32-bit value that identifies information about a command buffer to be rendered.

## See also

[D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)