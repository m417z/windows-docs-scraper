## Description

For purposes of sampler feedback, creates a descriptor suitable for binding.

## Parameters

### `pTargetedResource`

Type: \_In\_opt\_ **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12heap)\***

The targeted resource, such as a texture, to create a descriptor for.

### `pFeedbackResource`

Type: \_In\_opt\_ **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12heap)\***

The feedback resource, such as a texture, to create a descriptor for.

### `DestDescriptor`

Type: \_In\_ **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

The CPU descriptor handle.

## See also

* [Sampler feedback specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html)