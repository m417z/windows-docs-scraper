# _KSPROPERTY_SPHLI structure

## Description

The KSPROPERTY_SPHLI structure is used to describe a rectangle of subpicture or screen whose color or contrast is to be changed.

## Members

### `HLISS`

Indicates the highlight status of the current selection. A value of zero indicates that all highlights are invalid and the decoder should disable all highlights.

### `Reserved`

Reserved. Do not use.

### `StartPTM`

Indicates the start of presentation time.

### `EndPTM`

Indicates the end of presentation time.

### `StartX`

Indicates the start x-coordinate pixel of the current highlight button.

### `StartY`

Indicates the start y-coordinate pixel of the current highlight button.

### `StopX`

Indicates the ending x-coordinate pixel of the current highlight button.

### `StopY`

Indicates the ending y-coordinate pixel of the current highlight button.

### `ColCon`

Specifies the color/contrast of the highlight rectangle.

## Remarks

The KSPROPERTY_SPHLI structure is used by the [KSPROPERTY_DVDSUBPIC_HLI](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdsubpic-hli) property.

## See also

[KSPROPERTY_DVDSUBPIC_HLI](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdsubpic-hli)