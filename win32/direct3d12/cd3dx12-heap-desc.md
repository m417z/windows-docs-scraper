# CD3DX12\_HEAP\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_HEAP\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_desc) structure.

## Members

**CD3DX12\_HEAP\_DESC()**

Creates a new, uninitialized, instance of a CD3DX12\_HEAP\_DESC.

**explicit CD3DX12\_HEAP\_DESC(const D3D12\_HEAP\_DESC &o)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initialized with the contents of another [**D3D12\_HEAP\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_desc) structure.

**CD3DX12\_HEAP\_DESC(UINT64 size, D3D12\_HEAP\_PROPERTIES properties, UINT64 alignment = 0, D3D12\_HEAP\_FLAGS flags = D3D12\_HEAP\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initializing the following parameters:

UINT64 size

[**D3D12\_HEAP\_PROPERTIES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) properties

(opt) UINT64 alignment = 0

(opt) [**D3D12\_HEAP\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) flags = D3D12\_HEAP\_FLAG\_NONE

**CD3DX12\_HEAP\_DESC(UINT64 size, D3D12\_HEAP\_TYPE type, UINT64 alignment = 0, D3D12\_HEAP\_FLAGS flags = D3D12\_HEAP\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initializing the following parameters:

UINT64 size

[**D3D12\_HEAP\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_type) type

(opt) UINT64 alignment = 0

(opt) [**D3D12\_HEAP\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) flags = D3D12\_HEAP\_FLAG\_NONE

**CD3DX12\_HEAP\_DESC(UINT64 size, D3D12\_CPU\_PAGE\_PROPERTY cpuPageProperty, D3D12\_MEMORY\_POOL memoryPoolPreference, UINT64 alignment = 0, D3D12\_HEAP\_FLAGS flags = D3D12\_HEAP\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initializing the following parameters:

UINT64 size

[**D3D12\_CPU\_PAGE\_PROPERTY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_cpu_page_property) cpuPageProperty

[**D3D12\_MEMORY\_POOL**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool) memoryPoolPreference

(opt) UINT64 alignment = 0

(opt) [**D3D12\_HEAP\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) flags = D3D12\_HEAP\_FLAG\_NONE

**CD3DX12\_HEAP\_DESC(const D3D12\_RESOURCE\_ALLOCATION\_INFO& resAllocInfo, D3D12\_HEAP\_PROPERTIES properties, D3D12\_HEAP\_FLAGS flags = D3D12\_HEAP\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initializing the following parameters:

[**D3D12\_RESOURCE\_ALLOCATION\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_allocation_info)& resAllocInfo

[**D3D12\_HEAP\_PROPERTIES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) properties

(opt) [**D3D12\_HEAP\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) flags = D3D12\_HEAP\_FLAG\_NONE

**CD3DX12\_HEAP\_DESC(const D3D12\_RESOURCE\_ALLOCATION\_INFO& resAllocInfo, D3D12\_HEAP\_TYPE type, D3D12\_HEAP\_FLAGS flags = D3D12\_HEAP\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initializing the following parameters:

[**D3D12\_RESOURCE\_ALLOCATION\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_allocation_info)& resAllocInfo

[**D3D12\_HEAP\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_type) type

(opt) [**D3D12\_HEAP\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) flags = D3D12\_HEAP\_FLAG\_NONE

**CD3DX12\_HEAP\_DESC(const D3D12\_RESOURCE\_ALLOCATION\_INFO& resAllocInfo, D3D12\_CPU\_PAGE\_PROPERTY cpuPageProperty, D3D12\_MEMORY\_POOL memoryPoolPreference, D3D12\_HEAP\_FLAGS flags = D3D12\_HEAP\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_HEAP\_DESC, initializing the following parameters:

[**D3D12\_RESOURCE\_ALLOCATION\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_allocation_info)& resAllocInfo

[**D3D12\_CPU\_PAGE\_PROPERTY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_cpu_page_property) cpuPageProperty

[**D3D12\_MEMORY\_POOL**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool) memoryPoolPreference

(opt) [**D3D12\_HEAP\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) flags = D3D12\_HEAP\_FLAG\_NONE

**operator const D3D12\_HEAP\_DESC&() const**

Defines the & pass-by-reference operator for the CD3DX12\_HEAP\_DESC structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_HEAP\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

