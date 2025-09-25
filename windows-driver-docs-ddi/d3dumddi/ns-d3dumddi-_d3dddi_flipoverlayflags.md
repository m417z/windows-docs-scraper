# _D3DDDI_FLIPOVERLAYFLAGS structure

## Description

The D3DDDI_FLIPOVERLAYFLAGS structure identifies how to flip a resource on an overlay.

## Members

### `Even`

A UINT value that specifies whether the interleaved field to be displayed is even. The **Even** bit-field is set when the overlay is requested to deinterlace the data.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Odd`

A UINT value that specifies whether the interleaved field to be displayed is odd. The **Odd** bit-field is set when the overlay is requested to deinterlace the data.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_FLIPOVERLAYFLAGS that can hold one 32-bit value that identifies how to flip a resource on an overlay.

## See also

[D3DDDIARG_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_flipoverlay)