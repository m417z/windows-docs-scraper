# _D3DDDI_COLORFILLFLAGS structure

## Description

The D3DDDI_COLORFILLFLAGS structure describes how to color-fill a rectangle on a surface.

## Members

### `PresentToDwm`

A UINT value that specifies whether the Microsoft Direct3D runtime begins and ends a desktop window manager (DWM) present operation during the color-fill operation.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_COLORFILLFLAGS that can hold one 32-bit value that identifies how to color-fill a rectangle on a surface.

## See also

[ColorFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_colorfill)

[D3DDDIARG_COLORFILL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_colorfill)