# D3D10_DEPTH_STENCIL_VIEW_DESC structure

## Description

Specifies the [subresource(s)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from a texture that are accessible using a depth-stencil view.

## Members

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

Resource data format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)). See remarks for allowable formats.

### `ViewDimension`

Type: **[D3D10_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_dsv_dimension)**

Type of resource (see [D3D10_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_dsv_dimension)). Specifies how a depth-stencil resource will be accessed; the value is stored in the union in this structure.

### `Texture1D`

Type: **[D3D10_TEX1D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_dsv)**

Specifies a 1D texture subresource (see [D3D10_TEX1D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_dsv)).

### `Texture1DArray`

Type: **[D3D10_TEX1D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_array_dsv)**

Specifies an array of 1D texture subresources (see [D3D10_TEX1D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_array_dsv)).

### `Texture2D`

Type: **[D3D10_TEX2D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_dsv)**

Specifies a 2D texture subresource (see [D3D10_TEX2D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_dsv)).

### `Texture2DArray`

Type: **[D3D10_TEX2D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_array_dsv)**

Specifies an array of 2D texture subresources (see [D3D10_TEX2D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_array_dsv)).

### `Texture2DMS`

Type: **[D3D10_TEX2DMS_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_dsv)**

Specifies a multisampled 2D texture contains a single subresource (see [D3D10_TEX2DMS_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_dsv)).

### `Texture2DMSArray`

Type: **[D3D10_TEX2DMS_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_array_dsv)**

Specifies a multisampled 2D texture contains a single subresource per texture (see [D3D10_TEX2DMS_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_array_dsv)).

## Remarks

These are valid formats for a depth-stencil view:

* DXGI_FORMAT_D16_UNORM
* DXGI_FORMAT_D24_UNORM_S8_UINT
* DXGI_FORMAT_D32_FLOAT
* DXGI_FORMAT_D32_FLOAT_S8X24_UINT
* DXGI_FORMAT_UNKNOWN

A depth-stencil view cannot use a [typeless format](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views). If the format chosen is DXGI_FORMAT_UNKNOWN, then the format of the parent resource is used.

A depth-stencil-view description is needed when calling [ID3D10Device::CreateDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createdepthstencilview).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)