## Description

The **D3D12DDI_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS_0101** structure specifies parameters for preserving a local portion of a resource at the end of a render pass.

## Members

### `AdditionalWidth`

Specifies the additional width, in pixels, to be preserved on either side of the preserved region. A value of 0 means no extra pixels are preserved beyond the specified region. See Remarks.

### `AdditionalHeight`

Specifies the additional height, in pixels, to be preserved above and below the preserved region. A value of 0 means no extra pixels are preserved beyond the specified region. See Remarks.

## Remarks

This structure is used when the ending access [**Type**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_0053) for a resource within a render pass is one of the following values. For each of these types, the beginning of the previous pass must specify the matching [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_PRESERVE_LOCAL_*XXX***](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) value and the same **AdditionalWidth**/**AdditionalHeight** parameters.

* **D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER**

* **D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_SRV**

* **D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_UAV**

**AdditionalWidth** and **AdditionalHeight** must be set to 0 for **D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER** because they don't make sense in the context of rendering.

If **AdditionalWidth**/**AdditionalHeight** parameters for the pass are nonzero, they define a border of additional pixel locations around the current one that can also be read. For instance, **AdditionalWidth** of 1 and **AdditionalHeight** of 2 means a region 3 pixels wide and 5 pixels tall around the current pixel can be read by the current pixel.

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053)

[**D3D12DDI_RENDER_PASS_ENDING_ACCESS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_0053)

[**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053)

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)