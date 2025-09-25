# D3D12_RESOURCE_DESC structure

## Description

Describes a resource, such as a texture. This structure is used extensively.

## Members

### `Dimension`

One member of [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_dimension), specifying the dimensions of the resource (for example, D3D12_RESOURCE_DIMENSION_TEXTURE1D), or whether it is a buffer ((D3D12_RESOURCE_DIMENSION_BUFFER).

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

Specifies one member of [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `SampleDesc`

Specifies a [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure.

### `Layout`

Specifies one member of [D3D12_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout).

### `Flags`

Bitwise-OR'd flags, as [D3D12_RESOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) enumeration constants.

## Remarks

Use this structure with:

* [ID3D12Resource::GetDesc](https://learn.microsoft.com/windows/desktop/direct3d12/id3d12resource-getdesc)
* [ID3D12Device::GetResourceAllocationInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc))
* [ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)
* [ID3D12Device::CreatePlacedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createplacedresource)
* [ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createreservedresource)
* [ID3D12Device::GetCopyableFootprints](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getcopyablefootprints)
* A number of the helper functions, refer to [Helper Structures and Functions for D3D12](https://learn.microsoft.com/windows/desktop/direct3d12/helper-structures-and-functions-for-d3d12).

Two common resources are buffers and textures, which both use this structure, but with quite different uses of the fields.

### Buffers

Buffers are a contiguous memory region.
*Width* may be between 1 and either the *MaxGPUVirtualAddressBitsPerResource* field of [D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_gpu_virtual_address_support) for reserved resources or the *MaxGPUVirtualAddressBitsPerProcess* field for committed resources. However, exhaustion of GPU virtual address space, memory residency budget (see [IDXGIAdapter3::QueryVideoMemoryInfo](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo)), and or system memory may easily occur first.

*Alignment* must be 64KB (D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT) or 0, which is effectively 64KB.

*Height*, *DepthOrArraySize*, and *MipLevels* must be 1.

*Format* must be DXGI_FORMAT_UNKNOWN.

*SampleDesc.Count* must be 1 and *Quality* must be 0.

*Layout* must be D3D12_TEXTURE_LAYOUT_ROW_MAJOR, as buffer memory layouts are understood by applications and row-major texture data is commonly marshaled through buffers.

*Flags* must still be accurately filled out by applications for buffers, with minor exceptions. However, applications can use the most amount of capability support without concern about the efficiency impact on buffers. The flags field is meant to control properties related to textures.

### Textures

Textures are a multi-dimensional arrangement of texels in a contiguous region of memory, heavily optimized to maximize bandwidth for rendering and sampling. Texture sizes are hard to predict and vary from adapter to adapter. Applications must use [ID3D12Device::GetResourceAllocationInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc)) to accurately understand their size.

TEXTURE1D, TEXTURE2D, and TEXTURE3D are not supported orthogonally on every format. See the use of D3D12_FORMAT_SUPPORT1_TEXTURE1D, D3D12_FORMAT_SUPPORT1_TEXTURE2D, and D3D12_FORMAT_SUPPORT1_TEXTURE3D in [D3D12_FORMAT_SUPPORT1](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_format_support1).

*Width*, *Height*, and *DepthOrArraySize* must be between 1 and the maximum dimension supported for the particular feature level and texture dimension. However, exhaustion of GPU virtual address space, memory residency budget (see [IDXGIAdapter3::QueryVideoMemoryInfo](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo)), and or system memory may easily occur first. For compressed formats, these dimensions are logical. For example:

* For TEXTURE1D:
  + *Width* must be less than or equal to D3D10_REQ_TEXTURE1D_U_DIMENSION on feature levels less than 11_0 and D3D11_REQ_TEXTURE1D_U_DIMENSION on feature level 11_0 or greater.
  + *Height* must be 1.
  + *DepthOrArraySize* is interpreted as array size and must be less than or equal to D3D10_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION on feature levels less than 11_0 and D3D11_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION on feature levels 11_0 or greater.
* For TEXTURE2D:
  + *Width* and *Height* must be less than or equal to D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION on feature levels less than 11_0 and D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION or feature level 11_0 or greater.
  + *DepthOrArraySize* is interpreted as array size and must be less than or equal to D3D10_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION on feature levels less than 11_0 and D3D11_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION on feature levels 11_0 or greater.
* For TEXTURE3D:
  + *Width* and *Height* and *DepthOrArraySize* must be less than or equal to D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION on feature levels less than 11_0 and D3D11_REQ_TEXTURE2D_U_V_OR_W_DIMENSION on feature level 11_0 or greater.
  + *DepthOrArraySize* is interpreted as depth.

The following notes are for all texture sizes.

### Alignment

*Alignment* may be one of 0, 4KB, 64KB or 4MB.

If *Alignment* is set to 0, the runtime will use 4MB for MSAA textures and 64KB for everything else. The application may choose smaller alignments than these defaults for a couple of texture types when the texture is small.
Textures with UNKNOWN layout and MSAA may be created with 64KB alignment (if they pass the small size restriction detailed below).

Textures with UNKNOWN layout without MSAA and without render-target nor depth-stencil flags may be created with 4KB Alignment (again, passing the small size restriction).

Applications can create smaller aligned resources when the estimated size of the most-detailed mip level is a total of the larger alignment restriction or less. The runtime will use an architecture-independent mechanism of size-estimation, that mimics the way standard swizzle and D3D12 tiled resources are sized. However, the tile sizes will be of the smaller alignment restriction for such calculations.
Using the non-render-target and non-depth-stencil texture as an example, the runtime will assume near-equilateral tile shapes of 4KB, and calculate the number of tiles needed for the most-detailed mip level. If the number of tiles is equal to or less than 16, then the application can create a 4KB aligned resource. So, a mipped tex2d array of any array size and any number of mip levels can be 4KB, as long as the width and height are small enough for the particular format and MSAA.

### MipLevels

*MipLevels* may be 0, or 1 to the maximum mip levels supported by the *Width*, *Height* , and *DepthOrArraySize* dimensions. When 0 is used, the API will automatically calculate the maximum mip levels supported and use that. But, some resource and heap properties preclude mip levels, so the app must specify the value as 1.

Refer to the D3D12_FORMAT_SUPPORT1_MIP field of [D3D12_FORMAT_SUPPORT1](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_format_support1) for per-format restrictions. MSAA resources, textures with D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER, and heaps with D3D12_HEAP_FLAG_ALLOW_DISPLAY all preclude mip levels.

### Format

*Format* must be a valid format supported at the feature level of the device.

### SampleDesc

A *SampleDesc.Count* greater than 1 and/ or non-zero *Quality* are only supported for TEXTURE2D and when either D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET or D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL are set.

 The following are unsupported:

* D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE,
* D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS,
* D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS,
* D3D12_HEAP_FLAG_ALLOW_DISPLAY

See [D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_multisample_quality_levels) for determining valid *Count* and *Quality* values.

## See also

[CD3DX12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-resource-desc)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags)