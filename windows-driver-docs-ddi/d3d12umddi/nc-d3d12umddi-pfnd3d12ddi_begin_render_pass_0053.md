# PFND3D12DDI_BEGIN_RENDER_PASS_0053 callback function

## Description

This version of the user-mode display driver's (UMD) **pfnBeginRenderPass** callback function marks the beginning of an [extended render pass](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## Parameters

### `unnamedParam1`

[in] A D3D12DDI_HCOMMANDLIST handle through which to reference the command list.

### `NumRenderTargets`

[in/optional] The number of rendering targets that **pRenderTargets** points to.

### `pRenderTargets`

[in/optional] Pointer to a [**D3D12DDIARG_RENDER_PASS_RENDER_TARGET_DESC_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_render_pass_render_target_desc_0053) structure that describes the render target.

### `pDepthStencil`

[in/optional] Pointer to a [**D3D12DDIARG_RENDER_PASS_DEPTH_STENCIL_DESC_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_render_pass_depth_stencil_desc_0053) structure that describes the Render Pass depth stencil.

### `Flags`

[in] Pointer to a [**D3D12DDIARG_RENDER_PASS_FLAGS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddiarg_render_pass_flags_0053) enumeration that specifies the state of the Render Pass.

## Remarks

The caller of **pfnBeginRenderPass** must provide all Resources that the user declared. These resources can be one or both of the following:

* Serving as RTVs (Render Target View) or DSVs (Data Source View) within that Render Pass.
* Resuming from a previous Render Pass, via a [SUSPEND/RESUME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddiarg_render_pass_flags_0053) pair.

The [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) and [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053) enumerations must both be provided for all resources when calling this callback.

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**pfnEndRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_end_render_pass_0053)