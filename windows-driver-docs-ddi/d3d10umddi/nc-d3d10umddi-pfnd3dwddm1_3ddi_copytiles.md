# PFND3DWDDM1_3DDI_COPYTILES callback function

## Description

Copies tiles from buffer to tiled resource or vice versa.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hTiledResource`

A handle to the tiled resource.

### `pTileRegionStartCoord`

A pointer to a [**D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate) structure that describes the starting coordinates of the destination tiled resource.

### `pTileRegionSize`

A pointer to a [**D3DWDDM1_3DDI_TILE_REGION_SIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size) structure that describes the size of the tiled region.

### `hBuffer`

A handle to a resource that represents a default, dynamic, or staging buffer.

### `BufferStartOffsetInBytes`

The offset, in bytes, into the buffer at **hBuffer** to start the operation.

### `Flags`

A combination of [**D3DWDDM1_3DDI_TILE_COPY_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_copy_flag) values that are combined by using a bitwise OR operation.

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Direct3D runtime does not expect this function to fail.

## See also

[**D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tiled_resource_coordinate)

[**D3DWDDM1_3DDI_TILE_COPY_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_tile_copy_flag)

[**D3DWDDM1_3DDI_TILE_REGION_SIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_tile_region_size)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)