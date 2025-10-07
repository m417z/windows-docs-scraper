# CD3DX12\_HEAP\_PROPERTIES structure

A helper structure to enable easy initialization of a [**D3D12\_HEAP\_PROPERTIES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) structure.

## Members

**CD3DX12\_HEAP\_PROPERTIES()**

Creates a new, uninitialized, instance of a CD3DX12\_HEAP\_PROPERTIES.

**explicit CD3DX12\_HEAP\_PROPERTIES(const D3D12\_HEAP\_PROPERTIES &o)**

Creates a new instance of a CD3DX12\_HEAP\_PROPERTIES, initialized with the contents of another [**D3D12\_HEAP\_PROPERTIES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) structure.

**CD3DX12\_HEAP\_PROPERTIES(D3D12\_CPU\_PAGE\_PROPERTY cpuPageProperty, D3D12\_MEMORY\_POOL memoryPoolPreference, UINT creationNodeMask = 1, UINT nodeMask = 1)**

Creates a new instance of a CD3DX12\_HEAP\_PROPERTIES, initializing the following parameters:

[**D3D12\_CPU\_PAGE\_PROPERTY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_cpu_page_property) cpuPageProperty

[**D3D12\_MEMORY\_POOL**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool) memoryPoolPreference

(opt) UINT creationNodeMask = 1

(opt) UINT nodeMask = 1

**explicit CD3DX12\_HEAP\_PROPERTIES(D3D12\_HEAP\_TYPE type, UINT creationNodeMask = 1, UINT nodeMask = 1)**

Creates a new instance of a CD3DX12\_HEAP\_PROPERTIES, initializing the following parameters:

[**D3D12\_HEAP\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_type) type

(opt) UINT creationNodeMask = 1

(opt) UINT nodeMask = 1

**operator const D3D12\_HEAP\_PROPERTIES&() const**

Defines the & pass-by-reference operator for the parent structure type.

**inline operator==( const D3D12\_HEAP\_PROPERTIES& l, const D3D12\_HEAP\_PROPERTIES& r )**

Tests for equality between the specified D3D12\_HEAP\_PROPERTIES instances, based on equality of all member fields.

**inline operator!=( const D3D12\_HEAP\_PROPERTIES& l, const D3D12\_HEAP\_PROPERTIES& r )**

Tests for inequality between the specified D3D12\_HEAP\_PROPERTIES instances. Implemented by taking the inverse of the **operator==** value.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_HEAP\_PROPERTIES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

