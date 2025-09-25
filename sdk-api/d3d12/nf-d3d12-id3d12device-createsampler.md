# ID3D12Device::CreateSampler

## Description

Create a sampler object that encapsulates sampling information for a texture.

## Parameters

### `pDesc` [in]

Type: **const [D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc)***

A pointer to a [D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc) structure that describes the sampler.

### `DestDescriptor` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

Describes the CPU descriptor handle that represents the start of the heap that holds the sampler.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)