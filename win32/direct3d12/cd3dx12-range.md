# CD3DX12\_RANGE structure

A helper structure to enable easy initialization of a [**D3D12\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range) structure.

## Members

**CD3DX12\_RANGE()**

Creates a new, uninitialized, instance of a CD3DX12\_RANGE.

**explicit CD3DX12\_RANGE(const D3D12\_RANGE &o)**

Creates a new instance of a CD3DX12\_RANGE, initialized with the contents of another [**D3D12\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range) structure.

**CD3DX12\_RANGE(SIZE\_T begin, SIZE\_T end)**

Creates a new instance of a CD3DX12\_RANGE, initializing the following parameters:

SIZE\_T begin

SIZE\_T end

**operator const D3D12\_RANGE&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

