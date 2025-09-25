# D3D12_GPU_DESCRIPTOR_HANDLE structure

## Description

Describes a GPU descriptor handle.

## Members

### `ptr`

The address of the descriptor.

## Remarks

This structure is returned by [ID3D12DescriptorHeap::GetGPUDescriptorHandleForHeapStart](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12descriptorheap-getgpudescriptorhandleforheapstart).

This structure is passed into the following methods:

* [ID3D12GraphicsCommandList::ClearUnorderedAccessViewFloat](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearunorderedaccessviewfloat)
* [ID3D12GraphicsCommandList::ClearUnorderedAccessViewUint](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearunorderedaccessviewuint)
* [ID3D12GraphicsCommandList:SetComputeRootDescriptorTable](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setcomputerootdescriptortable)
* [ID3D12GraphicsCommandList::SetGraphicsRootDescriptorTable](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setgraphicsrootdescriptortable)

To get the handle increment size use [ID3D12Device.GetDescriptorHandleIncrementSize](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getdescriptorhandleincrementsize)

## See also

[CD3DX12_GPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-gpu-descriptor-handle)
[ID3D12Device.GetDescriptorHandleIncrementSize](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getdescriptorhandleincrementsize)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)