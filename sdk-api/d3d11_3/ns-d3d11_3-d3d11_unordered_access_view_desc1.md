## Description

Describes the subresources from a resource that are accessible using an unordered-access view.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the data format.

### `ViewDimension`

A [D3D11_UAV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_uav_dimension)-typed value that specifies the resource type of the view. This type is the same as the resource type of the underlying resource. This member also determines which _UAV to use in the union below.

### `Buffer`

A [D3D11_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_uav) structure that specifies which buffer elements can be accessed.

### `Texture1D`

A [D3D11_TEX1D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_uav) structure that specifies the subresources in a 1D texture that can be accessed.

### `Texture1DArray`

A [D3D11_TEX1D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_uav) structure that specifies the subresources in a 1D texture array that can be accessed.

### `Texture2D`

A [D3D11_TEX2D_UAV1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-d3d11_tex2d_uav1) structure that specifies the subresources in a 2D texture that can be accessed.

### `Texture2DArray`

A [D3D11_TEX2D_ARRAY_UAV1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-d3d11_tex2d_array_uav1) structure that specifies the subresources in a 2D texture array that can be accessed.

### `Texture3D`

A [D3D11_TEX3D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_uav) structure that specifies subresources in a 3D texture that can be accessed.

## Remarks

An unordered-access-view description is passed into [ID3D11Device3::CreateUnorderedAccessView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createunorderedaccessview1) to create a view.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)