# CD3DX12\_SUBRESOURCE\_TILING structure

A helper structure to enable easy initialization of a [**D3D12\_SUBRESOURCE\_TILING**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_tiling) structure.

## Members

**CD3DX12\_SUBRESOURCE\_TILING()**

Creates a new, uninitialized, instance of a CD3DX12\_SUBRESOURCE\_TILING.

**explicit CD3DX12\_SUBRESOURCE\_TILING(const D3D12\_SUBRESOURCE\_TILING &o)**

Creates a new instance of a CD3DX12\_SUBRESOURCE\_TILING, initialized with the contents of another [**D3D12\_SUBRESOURCE\_TILING**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_tiling) structure.

**CD3DX12\_SUBRESOURCE\_TILING(UINT widthInTiles, UINT16 heightInTiles, UINT16 depthInTiles, UINT startTileIndexInOverallResource)**

Creates a new instance of a CD3DX12\_SUBRESOURCE\_TILING, initializing the following parameters:

UINT widthInTiles

UINT16 heightInTiles

UINT16 depthInTiles

UINT startTileIndexInOverallResource

**operator const D3D12\_SUBRESOURCE\_TILING&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_SUBRESOURCE\_TILING**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_tiling)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

