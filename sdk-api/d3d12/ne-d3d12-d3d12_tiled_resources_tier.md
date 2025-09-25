# D3D12_TILED_RESOURCES_TIER enumeration

## Description

Identifies the tier level at which tiled resources are supported.

## Constants

### `D3D12_TILED_RESOURCES_TIER_NOT_SUPPORTED:0`

Indicates that textures cannot be created with the [D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout) layout.

[ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createreservedresource) cannot be used, not even for buffers.

### `D3D12_TILED_RESOURCES_TIER_1:1`

Indicates that 2D textures can be created with the D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE layout.
Limitations exist for certain resource formats and properties.
For more details, see [D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout).

[ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createreservedresource) can be used.

GPU reads or writes to NULL mappings are undefined.
Applications are encouraged to workaround this limitation by repeatedly mapping the same page to everywhere a NULL mapping would've been used.

When the size of a texture mipmap level is an integer multiple of the standard tile shape for its format, it is guaranteed to be nonpacked.

### `D3D12_TILED_RESOURCES_TIER_2:2`

Indicates that a superset of Tier_1 functionality is supported, including this additional support:

* When the size of a texture mipmap level is at least one standard tile shape for its format, the mipmap level is guaranteed to be nonpacked.
  For more info, see [D3D12_PACKED_MIP_INFO](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_packed_mip_info).
* Shader instructions are available for clamping level-of-detail (LOD) and for obtaining status about the shader operation.
  For info about one of these shader instructions, see Sample(S,float,int,float,uint).
  [Sample(S,float,int,float,uint)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sample-s-float--int-uint-).
* Reading from **NULL**-mapped tiles treat that sampled value as zero.
  Writes to **NULL**-mapped tiles are discarded.

Adapters that support feature level 12_0 all support TIER_2 or greater.

### `D3D12_TILED_RESOURCES_TIER_3:3`

Indicates that a superset of Tier 2 is supported, with the addition that 3D textures ([Volume Tiled Resources](https://learn.microsoft.com/windows/desktop/direct3d12/volume-tiled-resources)) are supported.

### `D3D12_TILED_RESOURCES_TIER_4:4`

## Remarks

This enum is used by the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure.

There are three discrete pieces of functionality bundled together for tiled resource functionality:

* A tile-based texture layout option where nearby texel addresses contain nearby data coordinates.
  A tile of texels contains nearly the same amount of texels in each cardinal dimension of the resource.
  This layout is represented in D3D12 by [D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout).
* Reserve a region of virtual address space for a resource, where each page is initially NULL-mapped.
  In D3D12, this is operation is encapsulated within [ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createreservedresource),
  which only works with textures that have the D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE layout.
* The ability to change page mappings and manipulate texture data on tile granularities.
  In D3D12, these operations are
  [ID3D12CommandQueue::UpdateTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings),
  [ID3D12CommandQueue::CopyTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-copytilemappings), and
  [ID3D12GraphicsCommandList::CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytiles).

Three significant changes over D3D11 are:

* Tile pools are replaced by heaps.
  Heaps provide a superset of capabilities than D3D11 tile pools do.
* Reserved resources may be mapped to pages from multiple heaps at the same time.
  The D3D11 restriction that all non-NULL mapped pages must come from the same heap does not exist.
* Applications should be aware of GPU virtual address capabilities, which enable litmus tests for particular usage scenarios.
  See [D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)