# D3D12_CPU_DESCRIPTOR_HANDLE structure

## Description

Describes a CPU descriptor handle.

## Members

### `ptr`

The address of the descriptor.

## Remarks

This structure is returned by the following methods:

* [ID3D12DescriptorHeap::GetCPUDescriptorHandleForHeapStart](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12descriptorheap-getcpudescriptorhandleforheapstart)

This structure is passed into the following methods:

* [ID3D12Device::CopyDescriptors](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-copydescriptors)
* [ID3D12Device::CopyDescriptorsSimple](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-copydescriptorssimple)
* [ID3D12Device::CreateConstantBufferView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createconstantbufferview)
* [ID3D12Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createshaderresourceview)
* [ID3D12Device::CreateUnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createunorderedaccessview)
* [ID3D12Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrendertargetview)
* [ID3D12Device::CreateDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createdepthstencilview)
* [ID3D12Device::CreateSampler](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createsampler)
* [ID3D12GraphicsCommandList::ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-cleardepthstencilview)
* [ID3D12GraphicsCommandList::ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearrendertargetview)
* [ID3D12GraphicsCommandList::ClearUnorderedAccessViewUint](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearunorderedaccessviewuint)
* [ID3D12GraphicsCommandList::ClearUnorderedAccessViewFloat](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearunorderedaccessviewfloat)
* [ID3D12GraphicsCommandList::OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-omsetrendertargets)

To get the handle increment size use [ID3D12Device.GetDescriptorHandleIncrementSize](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getdescriptorhandleincrementsize)

## See also

[CD3DX12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-cpu-descriptor-handle)
[ID3D12Device.GetDescriptorHandleIncrementSize](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getdescriptorhandleincrementsize)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)