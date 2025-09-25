# MFVideoArea structure

## Description

Specifies a rectangular area within a video frame.

## Members

### `OffsetX`

An [MFOffset](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfoffset) structure that contains the x-coordinate of the upper-left corner of the rectangle. This coordinate might have a fractional value.

### `OffsetY`

An [MFOffset](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfoffset) structure that contains the y-coordinate of the upper-left corner of the rectangle. This coordinate might have a fractional value.

### `Area`

A [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that contains the width and height of the rectangle.

## See also

[MFOffset](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfoffset)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)