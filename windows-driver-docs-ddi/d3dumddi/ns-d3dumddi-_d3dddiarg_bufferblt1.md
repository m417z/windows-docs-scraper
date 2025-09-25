# _D3DDDIARG_BUFFERBLT1 structure

## Description

Describes the parameters of a buffer bit-block transfer (bitblt) operation.

## Members

### `hDstResource`

A handle to the destination resource.

### `hSrcResource`

A handle to the source resource.

### `Offset`

The offset in the destination surface, in bytes.

### `SrcRange`

The source range.

### `CopyFlags`

A value that specifies characteristics of a copy operation as a bitwise OR of the values in the [D3DDDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_copy_flags) enumeration type.

## See also

[D3DDDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_copy_flags)