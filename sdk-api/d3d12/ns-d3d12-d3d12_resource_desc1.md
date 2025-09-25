## Description

Describes a resource, such as a texture, including a mip region. This structure is used in several methods.

## Members

### `Dimension`

One member of [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension), specifying the dimensions of the resource (for example, D3D12_RESOURCE_DIMENSION_TEXTURE1D), or whether it is a buffer ((D3D12_RESOURCE_DIMENSION_BUFFER).

### `Alignment`

Specifies the alignment.

### `Width`

Specifies the width of the resource.

### `Height`

Specifies the height of the resource.

### `DepthOrArraySize`

Specifies the depth of the resource, if it is 3D, or the array size if it is an array of 1D or 2D resources.

### `MipLevels`

Specifies the number of MIP levels.

### `Format`

Specifies one member of [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `SampleDesc`

Specifies a [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure.

### `Layout`

Specifies one member of [D3D12_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout).

### `Flags`

Bitwise-OR'd flags, as [D3D12_RESOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags) enumeration constants.

### `SamplerFeedbackMipRegion`

A [D3D12_MIP_REGION](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_mip_region) struct.

## Remarks

For remarks, see [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc).

## See also

* [Core structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)

* [Sampler feedback specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html)