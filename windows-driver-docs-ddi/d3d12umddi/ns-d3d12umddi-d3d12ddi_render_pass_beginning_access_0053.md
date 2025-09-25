# D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053 structure

## Description

The **D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053** structure specifies the access to the render target view(s) (RTVs) requested at the transition into a render pass.

## Members

### `Type`

A [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) value that specifies the type of access being requested. This value determines which union field is used.

### `Clear`

A [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_clear_parameters_0053) structure with parameters for a clear operation.

### `PreserveLocal`

A [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS_0101**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure with parameters for preserving a local portion of a resource at the beginning of a render pass.

## Remarks

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)