# D3DWDDM1_3DDI_TILE_RANGE_FLAG enumeration

## Description

Specifies a range of tile mappings to use with the UpdateTileMappings function.

## Constants

### `D3DWDDM_1_3DDI_TILE_RANGE_NULL`

The tile range is **NULL**.

If this flag is set in the UpdateTileMappings function's *pRangeFlags* parameter, the *pRangeTileCounts* parameter specifies the total
number of tiles in all the tile regions, and the *pTilePoolStartOffsets* parameter is ignored.

### `D3DWDDM_1_3DDI_TILE_RANGE_SKIP`

Tiles should be skipped over, and existing tile mappings should be left unchanged.

If this flag is set in the UpdateTileMappings function's *pRangeFlags* parameter, the *pRangeTileCounts* parameter specifies how many tiles from the tile regions to skip over, and the *pTilePoolStartOffsets* parameter is ignored.

### `D3DWDDM_1_3DDI_TILE_RANGE_REUSE_SINGLE_TILE`

A single tile in the tile pool should be reused.

If this flag is set in the UpdateTileMappings function's *pRangeFlags* parameter, the *pTilePoolStartOffsets* parameter specifies the single tile in the tile pool to map to, and the *pRangeTileCounts* parameter specifies how many tiles from the tile region to map to that tile pool location.