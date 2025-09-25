# PFND3DWDDM1_3DDI_UPDATETILES callback function

## Description

Updates tiles by copying from app memory to the tiled resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hDestTiledResource`

A handle to the tiled resource.

### `pDestTileRegionStartCoord`

A pointer to a [D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate) structure that describes the starting coordinates of the tiled resource.

### `pDestTileRegionSize`

A pointer to a [D3DWDDM1_3DDI_TILE_REGION_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size) structure that describes the size of the tiled region.

### `pSourceTileData`

A pointer to memory that contains the source tile data that this function uses to update the tiled resource.

### `Flags`

A combination of values of type [D3DWDDM1_3DDI_TILE_COPY_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_copy_flag) that are combined by using a bitwise **OR** operation. The only valid value is **D3DWDDM1_3DDI_TILE_COPY_NO_OVERWRITE**. The other enumeration constant values aren't meaningful here, though by definition using **D3DWDDM1_3DDI_TILE_COPY_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER** results in what the *UpdateTiles* function does, sourcing from app memory.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Direct3D runtime does not expect this function to fail.

## See also

[D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate)

[D3DWDDM1_3DDI_TILE_COPY_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_copy_flag)

[D3DWDDM1_3DDI_TILE_REGION_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size)

[UpdateTiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_updatetiles)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)