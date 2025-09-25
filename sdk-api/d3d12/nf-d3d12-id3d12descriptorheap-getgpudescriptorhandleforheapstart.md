# ID3D12DescriptorHeap::GetGPUDescriptorHandleForHeapStart

## Description

Gets the GPU descriptor handle that represents the start of the heap.

## Return value

Type: **[D3D12_GPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle)**

Returns the GPU descriptor handle that represents the start of the heap. If the descriptor heap is not shader-visible, a null handle is returned.

## See also

[ID3D12DescriptorHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12descriptorheap)