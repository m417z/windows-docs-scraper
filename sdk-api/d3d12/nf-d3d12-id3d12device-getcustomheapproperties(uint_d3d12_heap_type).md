## Description

Divulges the equivalent custom heap properties that are used for non-custom heap types, based on the adapter's architectural properties.

## Parameters

### `nodeMask` [in]

Type: **UINT**

For single-GPU operation, set this to zero.
If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter).
Each bit in the mask corresponds to a single node.
Only 1 bit must be set.
See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `heapType`

Type: **[D3D12_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type)**

A [D3D12_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type)-typed value that specifies the heap to get properties for.
D3D12_HEAP_TYPE_CUSTOM is not supported as a parameter value.

## Return value

Type: **[D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_heap_properties)**

Returns a [D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_heap_properties) structure that provides properties for the specified heap.
The **Type** member of the returned D3D12_HEAP_PROPERTIES is always D3D12_HEAP_TYPE_CUSTOM.

When [D3D12_FEATURE_DATA_ARCHITECTURE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_architecture)::UMA is FALSE, the returned D3D12_HEAP_PROPERTIES members convert as follows:

| Heap Type | How the returned D3D12_HEAP_PROPERTIES members convert |
| --- | --- |
| D3D12_HEAP_TYPE_UPLOAD | **CPUPageProperty** = WRITE_COMBINE, **MemoryPoolPreference** = L0. |
| D3D12_HEAP_TYPE_DEFAULT | **CPUPageProperty** = NOT_AVAILABLE, **MemoryPoolPreference** = L1. |
| D3D12_HEAP_TYPE_READBACK | **CPUPageProperty** = WRITE_BACK, **MemoryPoolPreference** = L0. |

When D3D12_FEATURE_DATA_ARCHITECTURE::UMA is TRUE and D3D12_FEATURE_DATA_ARCHITECTURE::CacheCoherentUMA is FALSE, the returned D3D12_HEAP_PROPERTIES members convert as follows:

| Heap Type | How the returned D3D12_HEAP_PROPERTIES members convert |
| --- | --- |
| D3D12_HEAP_TYPE_UPLOAD | **CPUPageProperty** = WRITE_COMBINE, **MemoryPoolPreference** = L0. |
| D3D12_HEAP_TYPE_DEFAULT | **CPUPageProperty** = NOT_AVAILABLE, **MemoryPoolPreference** = L0. |
| D3D12_HEAP_TYPE_READBACK | **CPUPageProperty** = WRITE_BACK, **MemoryPoolPreference** = L0. |

When D3D12_FEATURE_DATA_ARCHITECTURE::UMA is TRUE and D3D12_FEATURE_DATA_ARCHITECTURE::CacheCoherentUMA is TRUE, the returned D3D12_HEAP_PROPERTIES members convert as follows:

| Heap Type | How the returned D3D12_HEAP_PROPERTIES members convert |
| --- | --- |
| D3D12_HEAP_TYPE_UPLOAD | **CPUPageProperty** = WRITE_BACK, **MemoryPoolPreference** = L0. |
| D3D12_HEAP_TYPE_DEFAULT | **CPUPageProperty** = NOT_AVAILABLE, **MemoryPoolPreference** = L0. |
| D3D12_HEAP_TYPE_READBACK | **CPUPageProperty** = WRITE_BACK, **MemoryPoolPreference** = L0. |

## See also

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)