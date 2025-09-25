# COLORADJUSTMENT structure

## Description

The **COLORADJUSTMENT** structure defines the color adjustment values used by the [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt) and [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) functions when the stretch mode is HALFTONE. You can set the color adjustment values by calling the [SetColorAdjustment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setcoloradjustment) function.

## Members

### `caSize`

The size, in bytes, of the structure.

### `caFlags`

Specifies how the output image should be prepared. This member may be set to **NULL** or any combination of the following values.

| Value | Meaning |
| --- | --- |
| CA_NEGATIVE | Specifies that the negative of the original image should be displayed. |
| CA_LOG_FILTER | Specifies that a logarithmic function should be applied to the final density of the output colors. This will increase the color contrast when the luminance is low. |

### `caIlluminantIndex`

The type of standard light source under which the image is viewed. This member may be set to one of the following values.

| Value | Meaning |
| --- | --- |
| ILLUMINANT_DEVICE_DEFAULT | Device's default. Standard used by output devices. |
| ILLUMINANT_A | Tungsten lamp. |
| ILLUMINANT_B | Noon sunlight. |
| ILLUMINANT_C | NTSC daylight. |
| ILLUMINANT_D50 | Normal print. |
| ILLUMINANT_D55 | Bond paper print. |
| ILLUMINANT_D65 | Standard daylight. Standard for CRTs and pictures. |
| ILLUMINANT_D75 | Northern daylight. |
| ILLUMINANT_F2 | Cool white lamp. |
| ILLUMINANT_TUNGSTEN | Same as ILLUMINANT_A. |
| ILLUMINANT_DAYLIGHT | Same as ILLUMINANT_C. |
| ILLUMINANT_FLUORESCENT | Same as ILLUMINANT_F2. |
| ILLUMINANT_NTSC | Same as ILLUMINANT_C. |

### `caRedGamma`

Specifies the *n*th power gamma-correction value for the red primary of the source colors. The value must be in the range from 2500 to 65,000. A value of 10,000 means no gamma correction.

### `caGreenGamma`

Specifies the *n*th power gamma-correction value for the green primary of the source colors. The value must be in the range from 2500 to 65,000. A value of 10,000 means no gamma correction.

### `caBlueGamma`

Specifies the *n*th power gamma-correction value for the blue primary of the source colors. The value must be in the range from 2500 to 65,000. A value of 10,000 means no gamma correction.

### `caReferenceBlack`

The black reference for the source colors. Any colors that are darker than this are treated as black. The value must be in the range from 0 to 4000.

### `caReferenceWhite`

The white reference for the source colors. Any colors that are lighter than this are treated as white. The value must be in the range from 6000 to 10,000.

### `caContrast`

The amount of contrast to be applied to the source object. The value must be in the range from -100 to 100. A value of 0 means no contrast adjustment.

### `caBrightness`

The amount of brightness to be applied to the source object. The value must be in the range from -100 to 100. A value of 0 means no brightness adjustment.

### `caColorfulness`

The amount of colorfulness to be applied to the source object. The value must be in the range from -100 to 100. A value of 0 means no colorfulness adjustment.

### `caRedGreenTint`

The amount of red or green tint adjustment to be applied to the source object. The value must be in the range from -100 to 100. Positive numbers adjust toward red and negative numbers adjust toward green. Zero means no tint adjustment.

## See also

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetColorAdjustment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcoloradjustment)

[SetColorAdjustment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setcoloradjustment)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)