# D3D12_DESCRIPTOR_HEAP_DESC structure

## Description

Describes the descriptor heap.

## Members

### `Type`

A [D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)-typed value that specifies the types of descriptors in the heap.

### `NumDescriptors`

The number of descriptors in the heap.

### `Flags`

A combination of [D3D12_DESCRIPTOR_HEAP_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_descriptor_heap_flags)-typed values that are combined by using a bitwise OR operation. The resulting value specifies options for the heap.

### `NodeMask`

For single-adapter operation, set this to zero.
If there are multiple adapter nodes, set a bit to identify the node (one of the device's physical adapters) to which the descriptor heap applies.
Each bit in the mask corresponds to a single node.
Only one bit must be set.
See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

## Remarks

This structure is used by the following:

* [ID3D12DescriptorHeap::GetDesc](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12descriptorheap-getdesc)
* [ID3D12Device::CreateDescriptorHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createdescriptorheap)

## See also

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)

[Creating Descriptor Heaps](https://learn.microsoft.com/windows/win32/direct3d12/creating-descriptor-heaps)

[Descriptor Heaps](https://learn.microsoft.com/windows/win32/direct3d12/descriptor-heaps)