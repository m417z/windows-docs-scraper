# D3D12DDI_CLEAR_VALUES structure

## Description

The **D3D12DDI_CLEAR_VALUES** structure contains values used to optimize clear operations for a particular resource.

## Members

### `Format`

Specifies one member of the [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration.

The format of the commonly cleared color follows the same validation rules as a view/descriptor creation. In general, the format of the clear color can be any format in the same type-less group that the resource format belongs to.

This Format must match the format of the view used during the clear operation. It indicates whether the Color or the DepthStencil member is valid and how to convert the values for usage with the resource.

### `Color`

The color value that the driver should use to clear.

### `DepthStencil`

Pointer to a [**D3D12DDI_DEPTH_STENCIL_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_depth_stencil_values) structure that contains the depth and stencil buffer the driver should clear.

## Remarks

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_clear_parameters_0053)