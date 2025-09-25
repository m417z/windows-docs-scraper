# PFND3D12DDI_BEGIN_RENDER_PASS callback function

## Description

This version of the user-mode display driver's (UMD) **pfnBeginRenderPass** callback function marks the start of a render pass.

## Parameters

### `unnamedParam1`

[in] A D3D12DDI_HCOMMANDLIST handle through which to reference the command list.

### `NumRenderTargets`

[in/optional] The number of rendering targets that **pRenderTargets** points to.

### `pRenderTargets`

[in/optional] Pointer to a [**D3D12DDIARG_RENDER_PASS_RENDER_TARGET_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_render_pass_render_target_desc) structure that describes the render target.

### `pDepthStencil`

[in/optional] Pointer to a [**D3D12DDIARG_RENDER_PASS_DEPTH_STENCIL_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_render_pass_depth_stencil_desc) structure that describes the render pass depth stencil.

### `UnorderedAccessViewAccessFlags`

[in] An unordered access view (UAV), defined by a value in the [**D3D12DDIARG_RENDER_PASS_UAV_ACCESS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddiarg_render_pass_uav_access_flags) enumeration.

## Remarks

For the [extended render passes feature](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes), the [**PFND3D12DDI_BEGIN_RENDER_PASS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053) function is called instead.

The caller of **pfnBeginRenderPass** must provide all Resources that the user declared. These resources can be one or both of the following:

* Serving as RTVs (Render Target View) or DSVs (Data Source View) within that Render Pass.
* Resuming from a previous Render Pass, via a SUSPEND/RESUME pair.

The [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type) and [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type) enumerations must both be provided for all resources when calling this callback.

## See also

[**pfnEndRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_end_render_pass)