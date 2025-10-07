# CD3DX12\_TILE\_SHAPE structure

A helper structure to enable easy initialization of a [**D3D12\_TILE\_SHAPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_shape) structure.

## Members

**CD3DX12\_TILE\_SHAPE()**

Creates a new, uninitialized, instance of a CD3DX12\_TILE\_SHAPE.

**explicit CD3DX12\_TILE\_SHAPE(const D3D12\_TILE\_SHAPE &o)**

Creates a new instance of a CD3DX12\_TILE\_SHAPE, initialized with the contents of another [**D3D12\_TILE\_SHAPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_shape) structure.

**CD3DX12\_TILE\_SHAPE(UINT widthInTexels, UINT heightInTexels, UINT depthInTexels)**

Creates a new instance of a CD3DX12\_TILE\_SHAPE, initializing the following parameters:

UINT widthInTexels

UINT heightInTexels

UINT depthInTexels

**operator const D3D12\_TILE\_SHAPE&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_TILE\_SHAPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_shape)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

