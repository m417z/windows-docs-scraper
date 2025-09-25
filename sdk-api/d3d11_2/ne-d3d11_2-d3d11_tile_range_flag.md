# D3D11_TILE_RANGE_FLAG enumeration

## Description

Specifies a range of tile mappings to use with [ID3D11DeviceContext2::UpdateTiles](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-updatetiles).

## Constants

### `D3D11_TILE_RANGE_NULL:0x1`

The tile range is **NULL**.

### `D3D11_TILE_RANGE_SKIP:0x2`

Skip the tile range.

### `D3D11_TILE_RANGE_REUSE_SINGLE_TILE:0x4`

Reuse a single tile in the tile range.

## See also

[ID3D11DeviceContext2::UpdateTiles](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-updatetiles)

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)