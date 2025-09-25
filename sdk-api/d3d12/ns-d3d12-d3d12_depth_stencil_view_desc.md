# D3D12_DEPTH_STENCIL_VIEW_DESC structure

## Description

Describes the subresources of a texture that are accessible from a depth-stencil view.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format. For allowable formats, see Remarks.

### `ViewDimension`

A [D3D12_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_dsv_dimension)-typed value that specifies how the depth-stencil resource will be accessed. This member also determines which _DSV to use in the following union.

### `Flags`

A combination of [D3D12_DSV_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_dsv_flags) enumeration constants that are combined by using a bitwise OR operation.
The resulting value specifies whether the texture is read only.
Pass 0 to specify that it isn't read only; otherwise, pass one or more of the members of the **D3D12_DSV_FLAGS** enumerated type.

### `Texture1D`

A [D3D12_TEX1D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_dsv) structure that specifies a 1D texture subresource.

### `Texture1DArray`

A [D3D12_TEX1D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_array_dsv) structure that specifies an array of 1D texture subresources.

### `Texture2D`

A [D3D12_TEX2D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_dsv) structure that specifies a 2D texture subresource.

### `Texture2DArray`

A [D3D12_TEX2D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_array_dsv) structure that specifies an array of 2D texture subresources.

### `Texture2DMS`

A [D3D12_TEX2DMS_DSV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2dms_dsv) structure that specifies a multisampled 2D texture.

### `Texture2DMSArray`

A [D3D12_TEX2DMS_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2dms_array_dsv) structure that specifies an array of multisampled 2D textures.

## Remarks

These are valid formats for a depth-stencil view:

* DXGI_FORMAT_D16_UNORM
* DXGI_FORMAT_D24_UNORM_S8_UINT
* DXGI_FORMAT_D32_FLOAT
* DXGI_FORMAT_D32_FLOAT_S8X24_UINT
* DXGI_FORMAT_UNKNOWN

A depth-stencil view can't use a typeless format. If the format chosen is DXGI_FORMAT_UNKNOWN, the format of the parent resource is used.

Pass a depth-stencil-view description into [ID3D12Device::CreateDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createdepthstencilview) to create a depth-stencil view.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)