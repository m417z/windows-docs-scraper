# _DXVADDI_VIDEOPROCESSBLTFLAGS structure

## Description

The DXVADDI_VIDEOPROCESSBLTFLAGS structure identifies changes in the current destination surface from the previous destination surface.

## Members

### `BackgroundChanged`

A UINT value that specifies whether the background color of the destination surface changed. Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `TargetRectChanged`

A UINT value that specifies whether the target rectangle of the destination surface changed. Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `ColorDataChanged`

A UINT value that specifies whether format information for the destination surface changed. Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `AlphaChanged`

A UINT value that specifies whether the planar alpha value for the destination surface changed. Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the fifth through sixteenth bits (0x0000FFF0) of the 32-bit **Value** member to zeros.

### `DestData`

A UINT value that contains video processor sample destination data. Setting this member is equivalent to setting the seventeenth through thirty-second bits (0xFFFF0000) of the 32-bit **Value** member. The following bits can be set:

DXVADDI_DESTDATA_RFF (0x0001)

DXVADDI_DESTDATA_TFF (0x0002)

DXVADDI_DESTDATA_RFF_TFF_PRESENT (0x0004)

### `Value`

A 32-bit value that identifies changes in the current destination surface from the previous destination surface.

## See also

[D3DDDIARG_VIDEOPROCESSBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessblt)