# D3D12_TEXTURE_LAYOUT enumeration

## Description

Specifies texture layout options.

## Constants

### `D3D12_TEXTURE_LAYOUT_UNKNOWN:0`

Indicates that the layout is unknown, and is likely adapter-dependent.
During creation, the driver chooses the most efficient layout based on other resource properties, especially resource size and flags.
Prefer this choice unless certain functionality is required from another texture layout.

Zero-copy texture upload optimizations exist for UMA architectures; see [ID3D12Resource::WriteToSubresource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12resource-writetosubresource).

### `D3D12_TEXTURE_LAYOUT_ROW_MAJOR:1`

Indicates that data for the texture is stored in row-major order (sometimes called "pitch-linear order").

This texture layout locates consecutive texels of a row contiguously in memory, before the texels of the next row.
Similarly, consecutive texels of a particular depth or array slice are contiguous in memory before the texels of the next depth or array slice.
Padding may exist between rows and between depth or array slices to align collections of data.
A stride is the distance in memory between rows, depth, or array slices; and it includes any padding.

This texture layout enables sharing of the texture data between multiple adapters, when other layouts aren't available.

Many restrictions apply, because this layout is generally not efficient for extensive usage:

* The locality of nearby texels is not rotationally invariant.
* Only the following texture properties are supported:
  + [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension)_TEXTURE_2D.
  + A single mip level.
  + A single array slice.
  + 64KB alignment.
  + Non-MSAA.
  + No [D3D12_RESOURCE_FLAG](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags)_ALLOW_DEPTH_STENCIL.
  + The format cannot be a YUV format.
* The texture must be created on a heap with [D3D12_HEAP_FLAG](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags)_SHARED_CROSS_ADAPTER.

Buffers are created with [D3D12_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout)_ROW_MAJOR, because row-major texture data can be located in them without creating a texture object.
This is commonly used for uploading or reading back texture data, especially for discrete/NUMA adapters.
However, **D3D12_TEXTURE_LAYOUT**_ROW_MAJOR can also be used when marshaling texture data between GPUs or adapters.
For examples of usage with [ID3D12GraphicsCommandList::CopyTextureRegion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion), see some of the following topics:

* [Default Texture Mapping and Standard Swizzle](https://learn.microsoft.com/windows/win32/direct3d12/default-texture-mapping)
* [Predication](https://learn.microsoft.com/windows/win32/direct3d12/predication)
* [Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)
* [Uploading Texture Data](https://learn.microsoft.com/windows/win32/direct3d12/upload-and-readback-of-texture-data)

### `D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE:2`

Indicates that the layout within 64KB tiles and tail mip packing is up to the driver.
No standard swizzle pattern.

This texture layout is arranged into contiguous 64KB regions, also known as tiles, containing near equilateral amount of consecutive number of texels along each dimension.
Tiles are arranged in row-major order.
While there is no padding between tiles, there are typically unused texels within the last tile in each dimension.
The layout of texels within the tile is undefined.
Each subresource immediately follows where the previous subresource end, and the subresource order follows the same sequence as subresource ordinals.
However, tail mip packing is adapter-specific.
For more details, see tiled resource tier and [ID3D12Device::GetResourceTiling](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getresourcetiling).

This texture layout enables partially resident or sparse texture scenarios when used together with virtual memory page mapping functionality.
This texture layout must be used together with [ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource) to enable the usage of [ID3D12CommandQueue::UpdateTileMappings](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings).

Some restrictions apply to textures with this layout:

* The adapter must support [D3D12_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_tiled_resources_tier) 1 or greater.
* 64KB alignment must be used.
* [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension)_TEXTURE1D is not supported, nor are all formats.
* The tiled resource tier indicates whether textures with [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension)_TEXTURE3D is supported.

### `D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE:3`

Indicates that a default texture uses the standardized swizzle pattern.

This texture layout is arranged the same way that D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE is, except that the layout of texels within the tile is defined. Tail mip packing is adapter-specific.

This texture layout enables optimizations when marshaling data between multiple adapters or between the CPU and GPU.
The amount of copying can be reduced when multiple components understand the texture memory layout.
This layout is generally more efficient for extensive usage than row-major layout, due to the rotationally invariant locality of neighboring texels.
This layout can typically only be used with adapters that support standard swizzle, but exceptions exist for cross-adapter shared heaps.

The restrictions for this layout are that the following aren't supported:

* [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension)_TEXTURE1D
* Multi-sample anti-aliasing (MSAA)
* [D3D12_RESOURCE_FLAG](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags)_ALLOW_DEPTH_STENCIL
* Formats within the [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)_R32G32B32_TYPELESS group

## Remarks

This enum is used by the [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc) structure.

This enumeration controls the swizzle pattern of default textures and enable map support on default textures.
Callers must query [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) to ensure that each option is supported.

The standard swizzle formats applies within each page-sized chunk, and pages are laid out in linear order with respect to one another.
A 16-bit interleave pattern defines the conversion from pre-swizzled intra-page location to the post-swizzled location.

![Standard swizzle patterns](https://learn.microsoft.com/windows/win32/api/d3d12/images/d3d12_standardswizzle.png)

To demonstrate, consider the 2D 32bpp swizzle format above.
This is represented by the following interleave masks, where bits on the left are most-significant:

``` syntax
UINT xBytesMask = 1010 1010 1000 1111
UINT yMask =      0101 0101 0111 0000
```

To compute the swizzled address, the following code could be used (where the **_pdep_u32** intrinsic instruction is supported):

``` syntax
UINT swizzledOffset = resourceBaseOffset +
                      _pdep_u32(xOffset, xBytesMask) +
                      _pdep_u32(yOffset, yBytesMask);
```

## See also

[CD3DX12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-resource-desc)

[Core Enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-enumerations)

[UMA Optimizations: CPU Accessible Textures and Standard Swizzle](https://learn.microsoft.com/windows/win32/direct3d12/default-texture-mapping)