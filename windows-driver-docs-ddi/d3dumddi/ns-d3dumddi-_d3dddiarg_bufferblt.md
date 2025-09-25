# _D3DDDIARG_BUFFERBLT structure

## Description

The D3DDDIARG_BUFFERBLT structure describes the parameters of a buffer bit-block transfer (bitblt) operation.

## Members

### `hDstResource` [in]

A handle to the destination vertex or index buffer.

### `hSrcResource` [in]

A handle to the source vertex or index buffer.

### `Offset` [in]

The offset, in bytes, of the destination buffer that the copy should be directed into.

### `SrcRange` [in]

A D3DDDIRANGE structure that indicates what range of the source buffer should be copied. This D3DDDIRANGE specifies an offset and size, in bytes.

## See also

[BufBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_bufblt)