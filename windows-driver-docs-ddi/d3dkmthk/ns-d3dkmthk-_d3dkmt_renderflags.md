# _D3DKMT_RENDERFLAGS structure

## Description

The D3DKMT_RENDERFLAGS structure identifies the type of command buffer to be rendered in a call to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function.

## Members

### `ResizeCommandBuffer`

A UINT value that specifies whether to resize the command buffer. The driver puts the requested size in the **NewCommandBufferSize** member of the [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render) structure. Because a resize request by the driver might not be possible, the driver must always verify the size value that is returned.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

### `ResizeAllocationList`

A UINT value that specifies whether to resize the allocation list. The driver puts the requested number of elements in the **NewAllocationListSize** member of the [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render) structure. Because a resize request by the driver might not be possible, the driver must always verify the size value that is returned.

Setting this member is equivalent to setting the second bit of a 32-bit value (0x00000002).

### `ResizePatchLocationList`

A UINT value that specifies whether to resize the patch-location list. The driver puts the requested number of elements in the **NewPatchLocationListSize** member of the [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render) structure. Because a resize request by the driver might not be possible, the driver must always verify the size value that is returned.

Setting this member is equivalent to setting the third bit of a 32-bit value (0x00000004).

### `NullRendering`

A UINT value that specifies whether the graphics processing unit (GPU) should process any commands for the rendering context. The **NullRendering** bit-field flag is set to inform the GPU not to process any commands for the rendering context. The **NullRendering** bit-field flag is set only during performance investigating and debugging to simulate an infinitely fast rendering engine that still must perform the overhead of DMA buffer submission and signaling. **NullRendering** is never set during typical operations.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `PresentRedirected`

A UINT value that specifies whether to redirect the present command. The command contains a completion of one frame even though the command was completed in the OpenGl ICD.

Setting this member is equivalent to setting the fifth bit of a 32-bit value (0x00000010).

### `RenderKm`

Supported in Windows 7 and later versions.

A UINT value that specifies whether the OpenGL ICD supplies a pointer to the command buffer to be rendered in the ICD's call to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function. If this flag is set, the runtime does not call the display miniport driver's [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function. If this flag is set, the runtime calls the display miniport driver's [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function.

Setting this member is equivalent to setting the sixth bit of a 32-bit value (0x00000020).

### `RenderKmReadback`

### `Reserved`

This member is reserved and should be set to zero. Setting this member is equivalent to setting the remaining 26 bits (0xFFFFFFC0) of a 32-bit value to zeros.

## See also

[D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render)