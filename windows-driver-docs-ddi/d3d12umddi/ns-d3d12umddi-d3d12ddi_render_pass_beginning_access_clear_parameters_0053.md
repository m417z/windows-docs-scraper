# D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS_0053 structure

## Description

The **D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS_0053** structure describes the clear value to which resource(s) should be cleared at the beginning of a render pass.

## Members

### `ClearValue`

A [**D3D12DDI_CLEAR_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_clear_values) structure that specifies the clear parameters to which the resource(s) should be cleared.

## Remarks

This structure is used when the beginning access [**Type**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_0053) for a resource within a render pass is **D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_CLEAR**.

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_0053)

[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053)

[**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053)
[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)