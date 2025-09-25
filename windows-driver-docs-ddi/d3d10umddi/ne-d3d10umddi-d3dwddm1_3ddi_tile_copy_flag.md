# D3DWDDM1_3DDI_TILE_COPY_FLAG enumeration

## Description

Identifies how to copy a tile using the [CopyTiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_copytiles) function.

## Constants

### `D3DWDDM1_3DDI_TILE_COPY_NO_OVERWRITE`

The GPU isn't currently referencing any of the portions of destination memory being written.

### `D3DWDDM1_3DDI_TILE_COPY_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE`

The [CopyTiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_copytiles) operation involves copying a linear buffer to a swizzled tiled resource. This means to copy tile data from the specified buffer location, reading tiles sequentially, to the specified tile region (in *x*, *y*, *z* order if the region is a box), swizzling to optimal hardware memory layout as needed. In this *CopyTiles* call, you specify the source data with the *hBuffer* parameter and the destination with the *hTiledResource* parameter.

### `D3DWDDM1_3DDI_TILE_COPY_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER`

The [CopyTiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_copytiles) operation involves copying a swizzled tiled resource to a linear buffer. This means to copy tile data from the tile region, reading tiles sequentially (in *x*, *y*, *z* order if the region is a box), to the specified buffer location, deswizzling to linear memory layout as needed. In this *CopyTiles* call, you specify the source data with the *hTiledResource* parameter and the destination with the *hBuffer* parameter.

## See also

[CopyTiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_copytiles)