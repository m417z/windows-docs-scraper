# PFND3DWDDM1_3DDI_COPYTILEMAPPINGS callback function

## Description

Copies mappings from a source tiled resource to a destination tiled resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hDestTiledResource`

A handle to the destination tiled resource.

### `pDestRegionStartCoord`

A pointer to a [D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate) structure that describes the starting coordinates of the destination tiled resource.

### `hSourceTiledResource`

A handle to the source tiled resource.

### `pSourceRegionStartCoord`

A pointer to a [D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate) structure that describes the starting coordinates of the source tiled resource.

### `pTileRegionSize`

A pointer to a [D3DWDDM1_3DDI_TILE_REGION_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size) structure that describes the size of the tiled region.

### `Flags`

A combination of [D3DWDDM1_3DDI_TILE_MAPPING_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_mapping_flag) values that are combined by using a bitwise **OR** operation.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code. The driver can set **E_INVALIDARG** if an input parameter does not exist or is **NULL**.

## See also

[D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate)

[D3DWDDM1_3DDI_TILE_MAPPING_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_mapping_flag)

[D3DWDDM1_3DDI_TILE_REGION_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)