# CD3DX12\_TILED\_RESOURCE\_COORDINATE structure

A helper structure to enable easy initialization of a [**D3D12\_TILED\_RESOURCE\_COORDINATE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate) structure.

## Members

**CD3DX12\_TILED\_RESOURCE\_COORDINATE()**

Creates a new, uninitialized, instance of a CD3DX12\_TILED\_RESOURCE\_COORDINATE.

**explicit CD3DX12\_TILED\_RESOURCE\_COORDINATE(const D3D12\_TILED\_RESOURCE\_COORDINATE &o)**

Creates a new instance of a CD3DX12\_TILED\_RESOURCE\_COORDINATE, initialized with the contents of another [**D3D12\_TILED\_RESOURCE\_COORDINATE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate) structure.

**CD3DX12\_TILED\_RESOURCE\_COORDINATE(UINT x, UINT y, UINT z, UINT subresource)**

Creates a new instance of a CD3DX12\_TILED\_RESOURCE\_COORDINATE, initializing the following parameters:

UINT x

UINT y

UINT z

UINT subresource

**operator const D3D12\_TILED\_RESOURCE\_COORDINATE&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_TILED\_RESOURCE\_COORDINATE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

