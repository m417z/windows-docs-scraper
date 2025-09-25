# D3D12_HEAP_DESC structure

## Description

Describes a heap.

## Members

### `SizeInBytes`

The size, in bytes, of the heap.
To avoid wasting memory, applications should pass *SizeInBytes* values which are multiples of the effective *Alignment*;
but non-aligned *SizeInBytes* is also supported, for convenience.
To find out how large a heap must be to support textures with undefined layouts and adapter-specific sizes, call [ID3D12Device::GetResourceAllocationInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc)).

### `Properties`

A [D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) structure that describes the heap properties.

### `Alignment`

The alignment value for the heap. Valid values:

| Value | Description |
| --- | --- |
| 0 | An alias for 64KB. |
| D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT | #defined as 64KB. |
| D3D12_DEFAULT_MSAA_RESOURCE_PLACEMENT_ALIGNMENT | #defined as 4MB. An application must decide whether the heap will contain multi-sample anti-aliasing (MSAA), in which case, the application must choose D3D12_DEFAULT_MSAA_RESOURCE_PLACEMENT_ALIGNMENT. |

### `Flags`

A combination of [D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags)-typed values that are combined by using a bitwise-OR operation.
The resulting value identifies heap options.
When creating heaps to support adapters with resource heap tier 1, an application must choose some flags.

## Remarks

This structure is used by the [CreateHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createheap) method, and returned by the [GetDesc](https://learn.microsoft.com/windows/desktop/direct3d12/id3d12heap-getdesc) method.

## See also

[CD3DX12_HEAP_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-heap-desc)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Descriptor Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/descriptor-heaps)