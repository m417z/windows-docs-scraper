# ID3D12Device::CreateShaderResourceView

## Description

Creates a shader-resource view for accessing data in a resource.

## Parameters

### `pResource` [in, optional]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) object that represents the shader resource.

At least one of *pResource* or *pDesc* must be provided.
A null *pResource* is used to initialize a null descriptor, which guarantees D3D11-like null binding behavior (reading 0s, writes are discarded), but must have a valid *pDesc* in order to determine the descriptor type.

### `pDesc` [in, optional]

Type: **const [D3D12_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_resource_view_desc)***

A pointer to a [D3D12_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_resource_view_desc) structure that describes the shader-resource view.

A null *pDesc* is used to initialize a default descriptor, if possible. This behavior is identical to the D3D11 null descriptor behavior, where defaults are filled in. This behavior inherits the resource format and dimension (if not typeless) and for buffers SRVs target a full buffer and are typed (not raw or structured), and for textures SRVs target a full texture, all mips and all array slices. Not all resources support null descriptor initialization.

### `DestDescriptor` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

Describes the CPU descriptor handle that represents the shader-resource view. This handle can be created in a shader-visible or non-shader-visible descriptor heap.

## Remarks

### Processing YUV 4:2:0 video formats

An app must map the luma (Y) plane separately from the chroma (UV) planes. Developers do this by calling **CreateShaderResourceView** twice for the same texture and passing in 1-channel and 2-channel formats. Passing in a 1-channel format compatible with the Y plane maps only the Y plane. Passing in a 2-channel format compatible with the UV planes (together) maps only the U and V planes as a single resource view.

YUV 4:2:0 formats are listed in [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

#### Examples

The [D3D12nBodyGravity](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::CreateShaderResourceView** as follows:

Describe and create two shader resource views based on one description.

```cpp
D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
srvDesc.Format = DXGI_FORMAT_UNKNOWN;
srvDesc.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;
srvDesc.Buffer.FirstElement = 0;
srvDesc.Buffer.NumElements = ParticleCount;
srvDesc.Buffer.StructureByteStride = sizeof(Particle);
srvDesc.Buffer.Flags = D3D12_BUFFER_SRV_FLAG_NONE;

CD3DX12_CPU_DESCRIPTOR_HANDLE srvHandle0(m_srvUavHeap->GetCPUDescriptorHandleForHeapStart(), SrvParticlePosVelo0 + index, m_srvUavDescriptorSize);
CD3DX12_CPU_DESCRIPTOR_HANDLE srvHandle1(m_srvUavHeap->GetCPUDescriptorHandleForHeapStart(), SrvParticlePosVelo1 + index, m_srvUavDescriptorSize);
m_device->CreateShaderResourceView(m_particleBuffer0[index].Get(), &srvDesc, srvHandle0);
m_device->CreateShaderResourceView(m_particleBuffer1[index].Get(), &srvDesc, srvHandle1);

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)