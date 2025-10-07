# CD3DX12\_TEXTURE\_COPY\_LOCATION structure

A helper structure to enable easy initialization of a [**D3D12\_TEXTURE\_COPY\_LOCATION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location) structure.

## Members

**CD3DX12\_TEXTURE\_COPY\_LOCATION()**

Creates a new, uninitialized, instance of a CD3DX12\_TEXTURE\_COPY\_LOCATION.

**explicit CD3DX12\_TEXTURE\_COPY\_LOCATION(const D3D12\_TEXTURE\_COPY\_LOCATION &o)**

Creates a new instance of a CD3DX12\_TEXTURE\_COPY\_LOCATION, initialized with the contents of another [**D3D12\_TEXTURE\_COPY\_LOCATION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location) structure.

**CD3DX12\_TEXTURE\_COPY\_LOCATION(ID3D12Resource\* pRes)**

Creates a new instance of a CD3DX12\_TEXTURE\_COPY\_LOCATION, initializing the following parameters:

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pRes

**CD3DX12\_TEXTURE\_COPY\_LOCATION(ID3D12Resource\* pRes, D3D12\_PLACED\_SUBRESOURCE\_FOOTPRINT const& Footprint)**

Creates a new instance of a CD3DX12\_TEXTURE\_COPY\_LOCATION, initializing the following parameters:

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pRes

[**D3D12\_PLACED\_SUBRESOURCE\_FOOTPRINT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) const& Footprint

**CD3DX12\_TEXTURE\_COPY\_LOCATION(ID3D12Resource\* pRes, UINT Sub)**

Creates a new instance of a CD3DX12\_TEXTURE\_COPY\_LOCATION, initializing the following parameters:

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pRes

UINT Sub

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_TEXTURE\_COPY\_LOCATION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

