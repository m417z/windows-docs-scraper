# _D3DDDIARG_VOLUMEBLT1 structure

## Description

Describes parameters for a volume bit-block transfer (bitblt) operation.

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

A [D3DDDIBOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddibox) structure that describes the source volume texture to copy to the destination.

### `CopyFlags`

A value that specifies characteristics of a copy operation as a bitwise OR of the values in the [D3DDDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_copy_flags) enumeration type.

## See also

[D3DDDIBOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddibox)

[D3DDDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_copy_flags)