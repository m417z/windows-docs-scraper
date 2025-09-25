# D3D12_TILE_RANGE_FLAGS enumeration

## Description

Specifies a range of tile mappings.

## Constants

### `D3D12_TILE_RANGE_FLAG_NONE:0`

No tile-mapping flags are specified.

### `D3D12_TILE_RANGE_FLAG_NULL:1`

The tile range is **NULL**.

### `D3D12_TILE_RANGE_FLAG_SKIP:2`

Skip the tile range.

### `D3D12_TILE_RANGE_FLAG_REUSE_SINGLE_TILE:4`

Reuse a single tile in the tile range.

## Remarks

Use these flags with [ID3D12CommandQueue::UpdateTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)