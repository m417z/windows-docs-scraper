# PFND3D12DDI_END_RENDER_PASS callback function

## Description

The user-mode display driver's (UMD) **pfnEndRenderPass** callback function marks the end of a render pass.

## Parameters

### `unnamedParam1`

[in] A D3D12DDI_HCOMMANDLIST (command list) that contains the Render Pass.

## Remarks

For the [extended render passes feature](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes), the [**PFND3D12DDI_END_RENDER_PASS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_end_render_pass_0053) function is called instead.

## See also

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass)