# _DXVADDI_VIDEOSAMPLEFLAGS structure

## Description

The DXVADDI_VIDEOSAMPLEFLAGS structure identifies changes in the current sample frame from the previous sample frame.

## Members

### `PaletteChanged`

A UINT value that specifies whether the palette of the sample frame changed. Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `SrcRectChanged`

A UINT value that specifies whether the source rectangle of the sample frame changed. Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `DstRectChanged`

A UINT value that specifies whether the destination rectangle of the sample frame changed. Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `ColorDataChanged`

A UINT value that specifies whether the color data of the sample frame changed. Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `PlanarAlphaChanged`

A UINT value that specifies whether the alpha (transparency) data of the sample frame changed. Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the sixth through sixteenth bits (0x0000FFE0) of the 32-bit **Value** member to zeros.

### `SampleData`

A UINT value that contains video sample data. Setting this member is equivalent to setting the seventeenth through thirty-second bits (0xFFFF0000) of the 32-bit **Value** member. The following bits can be set:

DXVADDI_SAMPLEDATA_RFF (0x0001)

DXVADDI_SAMPLEDATA_TFF (0x0002)

DXVADDI_SAMPLEDATA_RFF_TFF_PRESENT (0x0004)

### `Value`

A member in the union that is contained in DXVADDI_VIDEOSAMPLEFLAGS that can hold one 32-bit value that identifies changes in the current sample frame from the previous sample frame.

## See also

[DXVADDI_VIDEOSAMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videosample)