# D3D12_UNORDERED_ACCESS_VIEW_DESC structure

## Description

Describes the subresources from a resource that are accessible by using an unordered-access view.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format.

### `ViewDimension`

A [D3D12_UAV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_uav_dimension)-typed value that specifies the resource type of the view. This type specifies how the resource will be accessed. This member also determines which _UAV to use in the union below.

### `Buffer`

A [D3D12_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_buffer_uav) structure that specifies which buffer elements can be accessed.

### `Texture1D`

A [D3D12_TEX1D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_uav) structure that specifies the subresources in a 1D texture that can be accessed.

### `Texture1DArray`

A [D3D12_TEX1D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_array_uav) structure that specifies the subresources in a 1D texture array that can be accessed.

### `Texture2D`

A [D3D12_TEX2D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_uav) structure that specifies the subresources in a 2D texture that can be accessed.

### `Texture2DArray`

A [D3D12_TEX2D_ARRAY_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_array_uav) structure that specifies the subresources in a 2D texture array that can be accessed.

### `Texture3D`

A [D3D12_TEX3D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex3d_uav) structure that specifies subresources in a 3D texture that can be accessed.

## Remarks

Pass an unordered-access-view description into [ID3D12Device::CreateUnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createunorderedaccessview) to create a view.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)