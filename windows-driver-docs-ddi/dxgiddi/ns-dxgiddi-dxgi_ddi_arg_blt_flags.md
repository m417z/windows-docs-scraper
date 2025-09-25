# DXGI_DDI_ARG_BLT_FLAGS structure

## Description

The DXGI_DDI_ARG_BLT_FLAGS structure identifies the type of bit-block transfer (bitblt) to perform.

## Members

### `Resolve`

A UINT value that specifies that the bitblt resolves multiple samples to one pixel.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Convert`

A UINT value that specifies that the bitblt also performs a format conversion.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Stretch`

A UINT value that specifies that a stretching bitblt is performed.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `Present`

A UINT value that specifies that a presenting bitblt is performed.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 28 bits (0xFFFFFFF0) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGI_DDI_ARG_BLT_FLAGS contains that can hold a 32-bit value that identifies the bitblt type.

## See also

[DXGI_DDI_ARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt)