# _D3DDDI_PRESENTFLAGS structure

## Description

The D3DDDI_PRESENTFLAGS structure identifies how to perform a present operation.

## Members

### `Blt`

A UINT value that specifies whether to perform a bit-block transfer (bitblt) data to the primary surface.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `ColorFill`

A UINT value that specifies whether to perform a colorfill bitblt to the primary surface .

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Flip`

A UINT value that specifies whether to flip to a new surface.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `AllowTearing`

### `AllowFlexibleRefresh`

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_PRESENTFLAGS that can hold one 32-bit value that identifies how to perform a present operation.

## See also

[D3DDDIARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_present)

[Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present)