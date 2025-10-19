# PixelOffsetMode enumeration

## Description

The **PixelOffsetMode** enumeration specifies the pixel offset mode of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. This enumeration is used by the [Graphics::GetPixelOffsetMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getpixeloffsetmode) and [Graphics::SetPixelOffsetMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setpixeloffsetmode) methods of the
**Graphics** class.

## Constants

### `PixelOffsetModeInvalid`

Used internally.

### `PixelOffsetModeDefault`

Equivalent to PixelOffsetModeNone.

### `PixelOffsetModeHighSpeed`

Equivalent to PixelOffsetModeNone.

### `PixelOffsetModeHighQuality`

Equivalent to PixelOffsetModeHalf.

### `PixelOffsetModeNone`

Indicates that pixel centers have integer coordinates.

### `PixelOffsetModeHalf`

Indicates that pixel centers have coordinates that are half way between integer values.

## Remarks

Consider the pixel in the upper-left corner of an image with address (0, 0). With **PixelOffsetModeNone**, the pixel covers the area between
–0.5 and 0.5 in both the x and y directions; that is, the pixel center is at (0, 0). With **PixelOffsetModeHalf**, the pixel covers the area between 0 and 1 in both the x and y directions; that is, the pixel center is at (0.5, 0.5).

## See also

[Graphics::GetPixelOffsetMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getpixeloffsetmode)

[Graphics::SetPixelOffsetMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setpixeloffsetmode)