## Description

The values of the **COLORTYPE** enumeration are used by several WCS functions. Variables of type **COLOR** are defined in the color spaces enumerated by the **COLORTYPE** enumeration.

## Constants

### `COLOR_GRAY:1`

The **COLOR** is in the GRAYCOLOR color space.

### `COLOR_RGB`

The **COLOR** is in the RGBCOLOR color space.

### `COLOR_XYZ`

The **COLOR** is in the XYZCOLOR color space.

### `COLOR_Yxy`

The **COLOR** is in the YxyCOLOR color space.

### `COLOR_Lab`

The **COLOR** is in the LabCOLOR color space.

### `COLOR_3_CHANNEL`

The **COLOR** is in the GENERIC3CHANNEL color space.

### `COLOR_CMYK`

The **COLOR** is in the CMYKCOLOR color space.

### `COLOR_5_CHANNEL`

The **COLOR** is in a five channel color space.

### `COLOR_6_CHANNEL`

The **COLOR** is in a six channel color space.

### `COLOR_7_CHANNEL`

The **COLOR** is in a seven channel color space.

### `COLOR_8_CHANNEL`

The **COLOR** is in an eight channel color space.

### `COLOR_NAMED`

The **COLOR** is in a named color space.

## Remarks

In addition to managing the common two, three, and four channel color spaces, WCS 1.0 is able to perform color management with device profiles that contain five through eight [color channels](https://learn.microsoft.com/windows/win32/wcs/c). It is also able to use named color spaces. When five, six, seven, or eight color channels are used, the provider of the device profile is free to determine what the color channels represent. The same is true of named color spaces. WCS 1.0 is able to manage these color spaces as long as there is a mapping in the device profile that maps the channels or the name space into the [PCS](https://learn.microsoft.com/windows/win32/wcs/p). The device profile must also contain a mapping from the PCS into the five, size, seven, or eight channel space, or into the named color space.

## See also