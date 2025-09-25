# D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW structure

## Description

Arguments used to create a depth stencil view.

## Members

### `hDrvResource`

A handle to the display driver resource.

### `Format`

A DXGI_FORMAT-typed value that indicates the pixel format of the depth stencil view.

### `ResourceDimension`

A [D3D12DDI_RESOURCE_DIMENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_dimension) value that indicates the resource type and dimensionality of the base resource

### `Flags`

A [D3D12DDI_CREATE_DEPTH_STENCIL_VIEW_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_create_depth_stencil_view_flags) flag.

### `Tex1D`

If the value in the *ResourceDimension* member is set to D3D12DDI_RD_TEXTURE1D, a member in the union that is contained in D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW that can hold a [D3D12DDIARG_TEX1D_DEPTH_STENCIL_VIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_tex1d_depth_stencil_view) structure for a one-dimensional texture

### `Tex2D`

If the value in the *ResourceDimension* member is set to D3D12DDI_RD_TEXTURE2D, a member in the union that is contained in D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW that can hold a [D3D12DDIARG_TEX2D_DEPTH_STENCIL_VIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_tex2d_depth_stencil_view) structure for a two-dimensional texture

### `TexCube`

If the value in the *ResourceDimension* member is set to D3D12DDI_RD_TEXTURECUBE, a member in the union that is contained in D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW that can hold a [D3D12DDIARG_TEXCUBE_DEPTH_STENCIL_VIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_texcube_depth_stencil_view) structure for a cube texture

## Remarks

## See also