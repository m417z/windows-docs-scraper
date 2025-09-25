# _D3DDDI_OVERLAYCOLORCONTROLSFLAGS structure

## Description

The D3DDDI_OVERLAYCOLORCONTROLSFLAGS structure identifies color-control settings that the overlay hardware supports.

## Members

### `Brightness`

A UINT value that specifies whether brightness adjustments to the overlay are enabled.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Contrast`

A UINT value that specifies whether contrast adjustments to the overlay are enabled.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Hue`

A UINT value that specifies whether hue adjustments to the overlay are enabled.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `Saturation`

A UINT value that specifies whether saturation adjustments to the overlay are enabled.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Sharpness`

A UINT value that specifies whether sharpness adjustments to the overlay are enabled.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `Gamma`

A UINT value that specifies whether gamma adjustments to the overlay are enabled.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `ColorEnable`

A UINT value that specifies whether color-enable adjustments to the overlay are enabled.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 25 bits (0xFFFFFF80) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_OVERLAYCOLORCONTROLSFLAGS that can hold one 32-bit value that identifies color-control settings that the overlay hardware supports.

## See also

[D3DDDI_OVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrols)