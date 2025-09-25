# PFND3DWDDM1_3DDI_UPDATETILEMAPPINGS callback function

## Description

Updates mappings of tile locations in tiled resources to memory locations in a tile pool.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hTiledResource`

A handle to the tiled resource.

### `NumTiledResourceRegions`

The number of tiled resource regions.

### `pTiledResourceRegionStartCoords`

An array of [D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate) structures that describe the starting coordinates of the tiled resource regions. The *NumTiledResourceRegions* parameter specifies the number of **D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE** structures in the array.

### `pTiledResourceRegionSizes`

An array of [D3DWDDM1_3DDI_TILE_REGION_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size) structures that describe the sizes of the tiled resource regions. The *NumTiledResourceRegions* parameter specifies the number of **D3DWDDM1_3DDI_TILE_REGION_SIZE** structures in the array.

### `hTilePool`

A handle to the tile pool.

### `NumRanges`

The number of tile-pool ranges.

### `pRangeFlags`

An array of values that describe each tile-pool range. The *NumRanges* parameter specifies the number of values in the array. Each value can be a combination of values of type [D3DWDDM1_3DDI_TILE_RANGE_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_range_flag) combined by using a bitwise **OR** operation.

### `pTilePoolStartOffsets`

An array of offsets into the tile pool. These are zero-based tile offsets, counting in tiles (not bytes).

### `pRangeTileCounts`

An array of values that specify the number of tiles in each tile-pool range. The *NumRanges* parameter specifies the number of values in the array.

### `Flags`

A combination of [D3DWDDM1_3DDI_TILE_MAPPING_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_mapping_flag) values that are combined by using a bitwise **OR** operation.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code. The driver can set **E_INVALIDARG** if a required input parameter does not exist or is **NULL**.

## See also

[D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate)

[D3DWDDM1_3DDI_TILE_MAPPING_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_mapping_flag)

[D3DWDDM1_3DDI_TILE_RANGE_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_range_flag)

[D3DWDDM1_3DDI_TILE_REGION_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size)