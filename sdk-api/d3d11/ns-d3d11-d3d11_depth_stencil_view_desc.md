# D3D11_DEPTH_STENCIL_VIEW_DESC structure

## Description

Specifies the subresources of a texture that are accessible from a depth-stencil view.

## Members

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

Resource data format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)). See remarks for allowable formats.

### `ViewDimension`

Type: **[D3D11_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_dsv_dimension)**

Type of resource (see [D3D11_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_dsv_dimension)). Specifies how a depth-stencil resource will be accessed; the value is stored in the
union in this structure.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that describes whether the texture is read only. Pass 0 to specify that it is not read only; otherwise, pass one of the members of
the [D3D11_DSV_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_dsv_flag) enumerated type.

### `Texture1D`

Type: **[D3D11_TEX1D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_dsv)**

Specifies a 1D texture subresource (see [D3D11_TEX1D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_dsv)).

### `Texture1DArray`

Type: **[D3D11_TEX1D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_dsv)**

Specifies an array of 1D texture subresources (see [D3D11_TEX1D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_dsv)).

### `Texture2D`

Type: **[D3D11_TEX2D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_dsv)**

Specifies a 2D texture subresource (see [D3D11_TEX2D_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_dsv)).

### `Texture2DArray`

Type: **[D3D11_TEX2D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_dsv)**

Specifies an array of 2D texture subresources (see [D3D11_TEX2D_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_dsv)).

### `Texture2DMS`

Type: **[D3D11_TEX2DMS_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_dsv)**

Specifies a multisampled 2D texture (see [D3D11_TEX2DMS_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_dsv)).

### `Texture2DMSArray`

Type: **[D3D11_TEX2DMS_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_array_dsv)**

Specifies an array of multisampled 2D textures (see [D3D11_TEX2DMS_ARRAY_DSV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_array_dsv)).

## Remarks

These are valid formats for a depth-stencil view:

* DXGI_FORMAT_D16_UNORM
* DXGI_FORMAT_D24_UNORM_S8_UINT
* DXGI_FORMAT_D32_FLOAT
* DXGI_FORMAT_D32_FLOAT_S8X24_UINT
* DXGI_FORMAT_UNKNOWN

A depth-stencil view cannot use a typeless format. If the format chosen is DXGI_FORMAT_UNKNOWN, then the format of the parent resource is used.

A depth-stencil-view description is needed when calling [ID3D11Device::CreateDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdepthstencilview).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)