# _DXVADDI_VIDEOLIGHTING enumeration

## Description

The DXVADDI_VIDEOLIGHTING enumeration type contains values that identify lighting conditions for viewing video.

## Constants

### `DXVADDI_VideoLightingMask`

The video lighting mask. The first 4 (0x0F) bits of a DWORD can be used to specify video lighting.

### `DXVADDI_VideoLighting_Unknown`

The video lighting condition is not specified. The default is dim.

### `DXVADDI_VideoLighting_bright`

A bright light for viewing video (for example, outside lighting conditions).

### `DXVADDI_VideoLighting_office`

A medium brightness light for viewing video (for example, lighting conditions in home offices).

### `DXVADDI_VideoLighting_dim`

A dim light for viewing video (for example, low-level lighting in a living room while watching television).

### `DXVADDI_VideoLighting_dark`

Near-darkness for viewing video (for example, movie-theatre lighting).

## Remarks

One of the values of DXVADDI_VIDEOLIGHTING can be specified in the **VideoLighting** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat).

The video lighting values can be used to alter the gamma to generate a comparable experience in a different lighting condition.

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)