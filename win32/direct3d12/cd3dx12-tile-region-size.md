# CD3DX12\_TILE\_REGION\_SIZE structure

A helper structure to enable easy initialization of a [**D3D12\_TILE\_REGION\_SIZE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_region_size) structure.

## Members

**CD3DX12\_TILE\_REGION\_SIZE()**

Creates a new, uninitialized, instance of a CD3DX12\_TILE\_REGION\_SIZE.

**explicit CD3DX12\_TILE\_REGION\_SIZE(const D3D12\_TILE\_REGION\_SIZE &o)**

Creates a new instance of a CD3DX12\_TILE\_REGION\_SIZE, initialized with the contents of another [**D3D12\_TILE\_REGION\_SIZE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_region_size) structure.

**CD3DX12\_TILE\_REGION\_SIZE(UINT numTiles, BOOL useBox, UINT width, UINT16 height, UINT16 depth)**

Creates a new instance of a CD3DX12\_TILE\_REGION\_SIZE, initializing the following parameters:

UINT numTiles

BOOL useBox

UINT width

UINT16 height

UINT16 depth

**operator const D3D12\_TILE\_REGION\_SIZE&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_TILE\_REGION\_SIZE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_region_size)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

