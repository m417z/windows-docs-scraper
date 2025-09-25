# _D3DDDIARG_VOLUMEBLT structure

## Description

The D3DDDIARG_VOLUMEBLT structure describes parameters for a volume bit-block transfer (bitblt) operation.

## Members

### `hDstResource` [in]

A handle to the destination surface.

### `hSrcResource` [in]

A handle to the source surface.

### `DstX` [in]

The width, in screen coordinates, of the destination volume in which the source volume is copied.

### `DstY` [in]

The height, in screen coordinates, of the destination volume in which the source volume is copied.

### `DstZ` [in]

The depth, in screen coordinates, of the destination volume in which the source volume is copied.

### `SrcBox` [in]

A D3DDDIBOX structure that describes the source volume texture to copy to the destination.

## See also

[VolBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_volblt)