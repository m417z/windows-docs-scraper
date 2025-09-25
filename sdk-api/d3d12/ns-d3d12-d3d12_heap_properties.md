## Description

Describes heap properties.

## Members

### `Type`

A [D3D12_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type)-typed value that specifies the type of heap.

### `CPUPageProperty`

A [D3D12_CPU_PAGE_PROPERTY](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_cpu_page_property)-typed value that specifies the CPU-page properties for the heap.

### `MemoryPoolPreference`

A [D3D12_MEMORY_POOL](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_memory_pool)-typed value that specifies the memory pool for the heap.

### `CreationNodeMask`

For multi-adapter operation, this indicates the node where the resource should be created.

Exactly one bit of this UINT must be set. See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

Passing zero is equivalent to passing one, in order to simplify the usage of single-GPU adapters.

### `VisibleNodeMask`

For multi-adapter operation, this indicates the set of nodes where the resource is visible.

*VisibleNodeMask* must have the same bit set that is set in *CreationNodeMask*. *VisibleNodeMask* can *also* have additional bits set for cross-node resources, but doing so can potentially reduce performance for resource accesses, so you should do so only when needed.

Passing zero is equivalent to passing one, in order to simplify the usage of single-GPU adapters.

## Remarks

This structure is used by the following:

* [D3D12_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_heap_desc) structure
* [ID3D12Resource::GetHeapProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12resource-getheapproperties)
* [ID3D12Device::GetCustomHeapProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getcustomheapproperties(uint_d3d12_heap_type))
* [ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)

Valid combinations of struct member values:

* When **Type** is [D3D12_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type)_CUSTOM,
  **CPUPageProperty** and **MemoryPoolPreference** must not be ..._UNKNOWN.
* When **Type** is not D3D12_HEAP_TYPE_CUSTOM,
  **CPUPageProperty** and **MemoryPoolPreference** must be ..._UNKNOWN.
* When using D3D12_HEAP_TYPE_CUSTOM and [D3D12_MEMORY_POOL](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_memory_pool)_L1, on NUMA adapters,
  **CPUPageProperty** must be [D3D12_CPU_PAGE_PROPERTY](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_cpu_page_property)_NOT_AVAILABLE.
  To differentiate NUMA from UMA adapters, see
  [D3D12_FEATURE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature)_ARCHITECTURE and
  [D3D12_FEATURE_DATA_ARCHITECTURE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_architecture).

## See also

[CD3DX12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-heap-properties)

[Core structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)

[Descriptor heaps](https://learn.microsoft.com/windows/win32/direct3d12/descriptor-heaps)