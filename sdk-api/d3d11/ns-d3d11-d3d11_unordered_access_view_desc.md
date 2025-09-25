# D3D11_UNORDERED_ACCESS_VIEW_DESC structure

## Description

Specifies the subresources from a resource that are accessible using an unordered-access view.

## Members

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The data format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

### `ViewDimension`

Type: **[D3D11_UAV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_uav_dimension)**

The resource type (see [D3D11_UAV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_uav_dimension)), which specifies how the resource will be accessed.

### `Buffer`

Type: **[D3D11_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_uav)**

Specifies which buffer elements can be accessed (see [D3D11_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_uav)).

### `Texture1D`

Type: **[D3D11_TEX1D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_uav)**

Specifies the subresources in a 1D texture that can be accessed (see [D3D11_TEX1D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_uav)).

### `Texture1DArray`

Type: **[D3D11_TEX1D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_uav)**

Specifies the subresources in a 1D texture array that can be accessed (see [D3D11_TEX1D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_uav)).

### `Texture2D`

Type: **[D3D11_TEX2D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_uav)**

Specifies the subresources in a 2D texture that can be accessed (see [D3D11_TEX2D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_uav)).

### `Texture2DArray`

Type: **[D3D11_TEX2D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_uav)**

Specifies the subresources in a 2D texture array that can be accessed (see [D3D11_TEX2D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_uav)).

### `Texture3D`

Type: **[D3D11_TEX3D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_uav)**

Specifies subresources in a 3D texture that can be accessed (see [D3D11_TEX3D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_uav)).

## Remarks

An unordered-access-view description is passed into [ID3D11Device::CreateUnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createunorderedaccessview) to create a view.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)