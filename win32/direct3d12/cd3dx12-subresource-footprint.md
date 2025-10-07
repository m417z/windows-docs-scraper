# CD3DX12\_SUBRESOURCE\_FOOTPRINT structure

A helper structure to enable easy initialization of a [**D3D12\_SUBRESOURCE\_FOOTPRINT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_footprint) structure.

## Members

**CD3DX12\_SUBRESOURCE\_FOOTPRINT()**

Creates a new, uninitialized, instance of a CD3DX12\_SUBRESOURCE\_FOOTPRINT.

**explicit CD3DX12\_SUBRESOURCE\_FOOTPRINT(const D3D12\_SUBRESOURCE\_FOOTPRINT &o)**

Creates a new instance of a CD3DX12\_SUBRESOURCE\_FOOTPRINT, initialized with the contents of another [**D3D12\_SUBRESOURCE\_FOOTPRINT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_footprint) structure.

**CD3DX12\_SUBRESOURCE\_FOOTPRINT(DXGI\_FORMAT format, UINT width, UINT height, UINT depth, UINT rowPitch)**

Creates a new instance of a CD3DX12\_SUBRESOURCE\_FOOTPRINT, initializing the following parameters:

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

UINT width

UINT height

UINT depth

UINT rowPitch

**explicit CD3DX12\_SUBRESOURCE\_FOOTPRINT(const D3D12\_RESOURCE\_DESC& resDesc, UINT rowPitch)**

Creates a new instance of a CD3DX12\_SUBRESOURCE\_FOOTPRINT, initializing the following parameters:

[**D3D12\_RESOURCE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc)& resDesc

UINT rowPitch

**operator const D3D12\_SUBRESOURCE\_FOOTPRINT&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_SUBRESOURCE\_FOOTPRINT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_footprint)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

