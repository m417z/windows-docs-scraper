# ID3D11DeviceContext2::UpdateTiles

## Description

Updates tiles by copying from app memory to the tiled resource.

## Parameters

### `pDestTiledResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to a tiled resource to update.

### `pDestTileRegionStartCoordinate` [in]

Type: **const [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate)***

A pointer to a [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate) structure that describes the starting coordinates of the tiled resource.

### `pDestTileRegionSize` [in]

Type: **const [D3D11_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tile_region_size)***

A pointer to a [D3D11_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tile_region_size) structure that describes the size of the tiled region.

### `pSourceTileData` [in]

Type: **const void***

A pointer to memory that contains the source tile data that **UpdateTiles** uses to update the tiled resource.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_TILE_COPY_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ne-d3d11_2-d3d11_tile_copy_flag)-typed values that are combined by using a bitwise OR operation. The only valid value is **D3D11_TILE_COPY_NO_OVERWRITE**.
The other values aren't meaningful here, though
by definition the **D3D11_TILE_COPY_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE** value is basically what **UpdateTiles** does, but sources from app memory.

## Remarks

**UpdateTiles** drops write operations to unmapped areas (except on [Tier_1](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_tiled_resources_tier) tiled resources, where writing to unmapped areas is invalid).

If a copy operation involves writing to the same memory location multiple times because multiple locations in the destination resource are mapped to the same tile memory, the resulting write operations to multi-mapped tiles are non-deterministic and non-repeatable; that is, accesses to the tile memory happen in whatever order the hardware happens to execute the copy operation.

The tiles involved in the copy operation can't include tiles that contain packed mipmaps or results of the copy operation are undefined. To transfer data to and from mipmaps that the hardware packs into one tile, you must use the standard (that is, non-tile specific) copy and update APIs (like [ID3D11DeviceContext1::CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1) and [ID3D11DeviceContext1::UpdateSubresource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-updatesubresource1)) or [ID3D11DeviceContext::GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-generatemips) for the whole mipmap chain.

The memory layout of the data on the source side of the copy operation is linear in memory within 64 KB tiles, which the hardware and driver swizzle and deswizzle per tile as appropriate when they transfer to and from a tiled resource. For multisample antialiasing (MSAA) surfaces, the hardware and driver traverse each pixel's samples in sample-index order before they move to the next pixel. For tiles that are partially filled on the right side (for a surface that has a width not a multiple of tile width in pixels), the pitch and stride to move down a row is the full size in bytes of the number pixels that would fit across the tile if the tile was full. So, there can be a gap between each row of pixels in memory. Mipmaps that are smaller than a tile are not packed together in the linear layout, which might seem to be a waste of memory space, but as mentioned you can't use [ID3D11DeviceContext2::CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-copytiles) or **UpdateTiles** to copy to mipmaps that the hardware packs together. You can just use generic copy and update APIs (like [ID3D11DeviceContext1::CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1) and [ID3D11DeviceContext1::UpdateSubresource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-updatesubresource1)) to copy small mipmaps individually. Although in the case of a generic copy API (like **ID3D11DeviceContext1::CopySubresourceRegion1**), the linear memory must be the same dimension as the tiled resource; **ID3D11DeviceContext1::CopySubresourceRegion1** can't copy from a buffer resource to a Texture2D for instance.

For more info about tiled resources, see [Tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/tiled-resources).

## See also

[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)