# D3D12_FEATURE_DATA_EXISTING_HEAPS structure

## Description

Provides detail about whether the adapter supports creating heaps from existing system memory. Such heaps are not intended for general use, but are exceptionally useful for diagnostic purposes, because they are guaranteed to persist even after the adapter faults or experiences a device-removal event. Persistence is not guaranteed for heaps returned by [ID3D12Device::CreateHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createheap) or [ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource), even when the heap resides in system memory.

## Members

### `Supported`

**TRUE** if the adapter can create a heap from existing system memory. Otherwise, **FALSE**.

## Remarks

For a variety of performance and compatibility reasons, applications should not make use of this feature except for diagnostic purposes. In particular, heaps created using this feature only support system-memory heaps with cross-adapter properties, which precludes many optimization opportunities that typical application scenarios could otherwise take advantage of.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)

[ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)

[ID3D12Device::CreateHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createheap)