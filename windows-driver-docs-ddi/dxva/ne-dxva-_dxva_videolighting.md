# _DXVA_VideoLighting enumeration

## Description

The DXVA_VideoLighting enumeration type contains enumerators that identify lighting conditions for viewing video.

## Constants

### `DXVA_VideoLightingShift`

Specifies to shift bits by 18 positions (DXVA_ExtColorData_ShiftBase + 10, or 8 + 10).

### `DXVA_VideoLightingMask`

Specifies the video lighting mask. 4 (0x003C0000) bits of a DWORD can be used to specify video lighting.

### `DXVA_VideoLighting_Unknown`

Specifies that the video lighting condition is not specified. The default is dim.

### `DXVA_VideoLighting_bright`

Specifies bright light for viewing video (for example, outside lighting conditions).

### `DXVA_VideoLighting_office`

Specifies a medium brightness light for viewing video (for example, lighting conditions in home offices).

### `DXVA_VideoLighting_dim`

Specifies a dim light for viewing video (for example, low-level lighting in a living room while watching television).

### `DXVA_VideoLighting_dark`

Specifies near darkness for viewing video (for example, movie-theatre lighting).

## Remarks

One of the enumerators of DXVA_VideoLighting can be specified in the **VideoLighting** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

The video lighting enumerators can be used to alter the gamma to generate a comparable experience in a different lighting condition.

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)