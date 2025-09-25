# GetStretchBltMode function

## Description

The **GetStretchBltMode** function retrieves the current stretching mode. The stretching mode defines how color data is added to or removed from bitmaps that are stretched or compressed when the [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt) function is called.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is the current stretching mode. This can be one of the following values.

| Value | Description |
| --- | --- |
| BLACKONWHITE | Performs a Boolean AND operation using the color values for the eliminated and existing pixels. If the bitmap is a monochrome bitmap, this mode preserves black pixels at the expense of white pixels. |
| COLORONCOLOR | Deletes the pixels. This mode deletes all eliminated lines of pixels without trying to preserve their information. |
| HALFTONE | Maps pixels from the source rectangle into blocks of pixels in the destination rectangle. The average color over the destination block of pixels approximates the color of the source pixels. |
| STRETCH_ANDSCANS | Same as BLACKONWHITE. |
| STRETCH_DELETESCANS | Same as COLORONCOLOR. |
| STRETCH_HALFTONE | Same as HALFTONE. |
| STRETCH_ORSCANS | Same as WHITEONBLACK. |
| WHITEONBLACK | Performs a Boolean OR operation using the color values for the eliminated and existing pixels. If the bitmap is a monochrome bitmap, this mode preserves white pixels at the expense of black pixels. |

If the function fails, the return value is zero.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)