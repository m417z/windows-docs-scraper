# CD3DX12\_RANGE\_UINT64 structure

A helper structure to enable easy initialization of a [**D3D12\_RANGE\_UINT64**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range_uint64) structure.

## Members

**CD3DX12\_RANGE\_UINT64()**

Creates a new, uninitialized, instance of a CD3DX12\_RANGE\_UINT64.

**explicit CD3DX12\_RANGE\_UINT64(const D3D12\_RANGE\_UINT64 &o)**

Creates a new instance of a CD3DX12\_RANGE\_UINT64, initialized with values copied from a [**D3D12\_RANGE\_UINT64**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range_uint64) structure.

**CD3DX12\_RANGE\_UINT64(UINT64 begin, UINT64 end)**

Creates a new instance of a CD3DX12\_DEPTH\_STENCIL\_DESC1, initialized with the values passed in the parameter list.

**operator const D3D12\_RANGE\_UINT64&() const**

Implicit conversion to a D3D12\_RANGE\_UINT64 structure. Because D3D12\_RANGE\_UINT64 is the underlying type of CD3DX12\_RANGE\_UINT64, the object is simply returned as a const D3D12\_RANGE\_UINT64 reference to itself.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**D3D12\_RANGE\_UINT64**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range_uint64)

