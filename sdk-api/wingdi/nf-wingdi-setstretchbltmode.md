# SetStretchBltMode function

## Description

The **SetStretchBltMode** function sets the bitmap stretching mode in the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `mode` [in]

The stretching mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BLACKONWHITE** | Performs a Boolean AND operation using the color values for the eliminated and existing pixels. If the bitmap is a monochrome bitmap, this mode preserves black pixels at the expense of white pixels. |
| **COLORONCOLOR** | Deletes the pixels. This mode deletes all eliminated lines of pixels without trying to preserve their information. |
| **HALFTONE** | Maps pixels from the source rectangle into blocks of pixels in the destination rectangle. The average color over the destination block of pixels approximates the color of the source pixels.<br><br>After setting the HALFTONE stretching mode, an application must call the [SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex) function to set the brush origin. If it fails to do so, brush misalignment occurs. |
| **STRETCH_ANDSCANS** | Same as BLACKONWHITE. |
| **STRETCH_DELETESCANS** | Same as COLORONCOLOR. |
| **STRETCH_HALFTONE** | Same as HALFTONE. |
| **STRETCH_ORSCANS** | Same as WHITEONBLACK. |
| **WHITEONBLACK** | Performs a Boolean OR operation using the color values for the eliminated and existing pixels. If the bitmap is a monochrome bitmap, this mode preserves white pixels at the expense of black pixels. |

## Return value

If the function succeeds, the return value is the previous stretching mode.

If the function fails, the return value is zero.

This function can return the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |

## Remarks

The stretching mode defines how the system combines rows or columns of a bitmap with existing pixels on a display device when an application calls the [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt) function.

The BLACKONWHITE (STRETCH_ANDSCANS) and WHITEONBLACK (STRETCH_ORSCANS) modes are typically used to preserve foreground pixels in monochrome bitmaps. The COLORONCOLOR (STRETCH_DELETESCANS) mode is typically used to preserve color in color bitmaps.

The HALFTONE mode is slower and requires more processing of the source image than the other three modes; but produces higher quality images. Also note that [SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex) must be called after setting the HALFTONE mode to avoid brush misalignment.

Additional stretching modes might also be available depending on the capabilities of the device driver.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstretchbltmode)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)