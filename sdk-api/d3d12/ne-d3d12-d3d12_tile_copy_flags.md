# D3D12_TILE_COPY_FLAGS enumeration

## Description

Specifies how to copy a tile.

## Constants

### `D3D12_TILE_COPY_FLAG_NONE:0`

No tile-copy flags are specified.

### `D3D12_TILE_COPY_FLAG_NO_HAZARD:0x1`

Indicates that the GPU isn't currently referencing any of the
portions of destination memory being written.

### `D3D12_TILE_COPY_FLAG_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE:0x2`

Indicates that the [ID3D12GraphicsCommandList::CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytiles) operation involves copying a linear buffer to a swizzled tiled resource. This means to copy tile data from the
specified buffer location, reading tiles sequentially,
to the specified tile region (in x,y,z order if the region is a box), swizzling to optimal hardware memory layout as needed.
In this **ID3D12GraphicsCommandList::CopyTiles** call, you specify the source data with the *pBuffer* parameter and the destination with the *pTiledResource* parameter.

### `D3D12_TILE_COPY_FLAG_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER:0x4`

Indicates that the [ID3D12GraphicsCommandList::CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytiles) operation involves copying a swizzled tiled resource to a linear buffer. This means to copy tile data from the tile region, reading tiles sequentially (in x,y,z order if the region is a box),
to the specified buffer location, deswizzling to linear memory layout as needed.
In this **ID3D12GraphicsCommandList::CopyTiles** call, you specify the source data with the *pTiledResource* parameter and the destination with the *pBuffer* parameter.

## Remarks

This enum is used by the [CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytiles) method.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)