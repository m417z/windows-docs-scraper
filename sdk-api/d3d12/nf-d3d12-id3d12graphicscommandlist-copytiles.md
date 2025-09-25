# ID3D12GraphicsCommandList::CopyTiles

## Description

Copies tiles from buffer to tiled resource or vice versa.

## Parameters

### `pTiledResource` [in]

Type: **ID3D12Resource***

A pointer to a tiled resource.

### `pTileRegionStartCoordinate` [in]

Type: **const [D3D12_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate)***

A pointer to a
[D3D12_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate) structure that describes the starting coordinates of the tiled resource.

### `pTileRegionSize` [in]

Type: **const [D3D12_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_region_size)***

A pointer to a [D3D12_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_region_size) structure that describes the size of the tiled region.

### `pBuffer` [in]

Type: **ID3D12Resource***

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) that represents a default, dynamic, or staging buffer.

### `BufferStartOffsetInBytes`

Type: **UINT64**

The offset in bytes into the buffer at *pBuffer* to start the operation.

### `Flags`

Type: **[D3D12_TILE_COPY_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_tile_copy_flags)**

A combination of [D3D12_TILE_COPY_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_tile_copy_flags)-typed values that are combined by using a bitwise OR operation and that identifies how to copy tiles.

## Remarks

**CopyTiles** drops write operations to
unmapped areas and handles read operations from unmapped areas
(except on Tier_1 tiled resources,
where reading and writing unmapped areas is invalid - refer to [D3D12_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_tiled_resources_tier)).

If a copy operation involves writing to the same memory location multiple times because multiple locations in the
destination resource are mapped to the same tile memory, the resulting write operations to multi-mapped tiles are
non-deterministic and non-repeatable; that is, accesses to the tile memory happen in whatever order the hardware
happens to execute the copy operation.

The tiles involved in the copy operation can't include tiles that contain packed mipmaps or results of the copy
operation are undefined. To transfer data to and from mipmaps that the hardware packs into the one-or-more tiles that constitute the packed mips, you must
use the standard (that is, non-tile specific) copy APIs
like [CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion).

**CopyTiles** does copy data in a slightly different pattern than the standard copy methods.

The memory layout of the tiles in the non-tiled buffer resource side of the copy operation is linear in memory within 64 KB tiles, which the hardware and driver swizzle and de-swizzle per tile as appropriate when they transfer to and from a tiled resource. For multisample antialiasing (MSAA) surfaces, the hardware and driver traverse each pixel's samples in sample-index order before they move to the next pixel. For tiles that are partially filled on the right side (for a surface that has a width not a multiple of tile width in pixels), the pitch and stride to move down a row is the full size in bytes of the number pixels that would fit across the tile if the tile was full. So, there can be a gap between each row of pixels in memory. Mipmaps that are smaller than a tile are not packed together in the linear layout, which might seem to be a waste of memory space, but as mentioned you can't use **CopyTiles** to copy to mipmaps that the hardware packs together. You can just use generic copy APIs, like [CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion), to copy small mipmaps individually.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)

[Tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/tiled-resources)