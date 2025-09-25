# LOGCOLORSPACEA structure

## Description

The **LOGCOLORSPACE** structure contains information that defines a logical [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space).

## Members

### `lcsSignature`

Color space signature. At present, this member should always be set to LCS_SIGNATURE.

### `lcsVersion`

Version number; must be 0x400.

### `lcsSize`

Size of this structure, in bytes.

### `lcsCSType`

Color space type. The member can be one of the following values.

| Value | Meaning |
| --- | --- |
| LCS_CALIBRATED_RGB | Color values are calibrated RGB values. The values are translated using the endpoints specified by the **lcsEndpoints** member before being passed to the device. |
| LCS_sRGB | Color values are values are sRGB values. |
| LCS_WINDOWS_COLOR_SPACE | Color values are Windows default color space color values. |

If LCS_CALIBRATED_RGB is not specified, the **lcsEndpoints** member is ignored.

### `lcsIntent`

The gamut mapping method. This member can be one of the following values.

| Value | Intent | ICC Name | Meaning |
| --- | --- | --- | --- |
| LCS_GM_ABS_COLORIMETRIC | Match | Absolute Colorimetric | Maintain the white point. Match the colors to their nearest color in the destination gamut. |
| LCS_GM_BUSINESS | Graphic | Saturation | Maintain saturation. Used for business charts and other situations in which undithered colors are required. |
| LCS_GM_GRAPHICS | Proof | Relative Colorimetric | Maintain colorimetric match. Used for graphic designs and named colors. |
| LCS_GM_IMAGES | Picture | Perceptual | Maintain contrast. Used for photographs and natural images. |

### `lcsEndpoints`

Red, green, blue endpoints.

### `lcsGammaRed`

Scale of the red coordinate.

### `lcsGammaGreen`

Scale of the green coordinate.

### `lcsGammaBlue`

Scale of the blue coordinate.

### `lcsFilename`

A null-terminated string that names a color profile file. This member is typically set to zero, but may be used to set the color space to be exactly as specified by the color profile. This is useful for devices that input color values for a specific printer, or when using an installable image color matcher. If a color profile is specified, all other members of this structure should be set to reasonable values, even if the values are not completely accurate.

## Remarks

Like palettes, but unlike pens and brushes, a pointer must be passed when creating a LogColorSpace.

If the **lcsCSType** member is set to LCS_sRGB or LCS_WINDOWS_COLOR_SPACE, the other members of this structure are ignored, and WCS uses the sRGB color space. The **lcsEndpoints,****lcsGammaRed, lcsGammaGreen,** and **lcsGammaBlue** members are used to describe the logical color space. The **lcsEndpoints** member is a **CIEXYZTRIPLE** that contains the x, y, and z values of the color space's RGB endpoint.

The required DWORD bit format for the **lcsGammaRed**, **lcsGammaGreen**, and **lcsGammaBlue** is an 8.8 fixed point integer left-shifted by 8 bits. This means 8 integer bits are followed by 8 fraction bits. Taking the bit shift into account, the required format of the 32-bit DWORD is:

00000000nnnnnnnnffffffff00000000

Whenever the **lcsFilename** member contains a file name and the **lcsCSType** member is set to LCS_CALIBRATED_RGB, WCS ignores the other members of this structure. It uses the color space in the file as the color space to which this **LOGCOLORSPACE** structure refers.

The relation between tri-stimulus values X,Y,Z and chromaticity values x,y,z is as follows:

x = X/(X+Y+Z)

y = Y/(X+Y+Z)

z = Z/(X+Y+Z)

If the lcsCSType member is set to LCS_sRGB or LCS_WINDOWS_COLOR_SPACE, the other members of this structure are ignored, and ICM uses the sRGB color space. Applications should still initialize the rest of the structure since CreateProfileFromLogColorSpace ignores lcsCSType member and uses lcsEndpoints, lcsGammaRed, lcsGammaGreen, lcsGammaBlue members to create a profile, which may not be initialized in case of LCS_sRGB or LCS_WINDOWS_COLOR_SPACE color spaces.

> [!NOTE]
> The wingdi.h header defines LOGCOLORSPACE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BITMAPV4HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv4header)

[BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header)

[CMYK](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-cmyk)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)