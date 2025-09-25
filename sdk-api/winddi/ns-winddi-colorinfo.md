# COLORINFO structure

## Description

The COLORINFO structure defines a device's colors in [CIE](https://learn.microsoft.com/windows-hardware/drivers/) coordinate space.

## Members

### `Red`

### `Green`

### `Blue`

### `Cyan`

### `Magenta`

### `Yellow`

### `AlignmentWhite`

Specify [CIECHROMA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ciechroma) structures that each define the x-coordinate, y-coordinate, and Y-coordinate (luminance) of the named color.

The **Cyan** member can have a special meaning for monochrome printers. **Cyan.Y** must be set to 65534 (0xFFFE) to enable all of the grayscale halftone pattern sizes. For more information, see the following Remarks section.

### `RedGamma`

### `GreenGamma`

### `BlueGamma`

Are the gamma corrections of display devices that permit the display device to display colors between the primary colors with accuracy. The values of these members should be in the range from 0 through 6.5535, which means that the numbers that are actually stored in these members must be in the range from 0 through 65535. For more information about these members and this data type, see the following Remarks section.

### `MagentaInCyanDye`

### `YellowInCyanDye`

### `CyanInMagentaDye`

### `YellowInMagentaDye`

### `CyanInYellowDye`

### `MagentaInYellowDye`

Used for printing devices to describe color purity and concentration. Values should be between zero and one, which means that the numbers actually stored in these members must be in the range 0 through 10000. For more information about this data type, see the following Remarks section.

## Remarks

The LDECI4 type is used to represent real numbers to four decimal places. For example, (LDECI4) 10000 represents the real number 1.0000, and (LDECI4) -12345 represents -1.2345.

For a monochrome printer, if you set the luminance for the **Cyan** member (that is, **Cyan.Y**) to 65534 (0xFFFE), you can select any of the available halftone pattern sizes. To select a halftone pattern size for a monochrome printer, set the **ulHTPatternSize** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure to the halftone pattern size that you want. If **Cyan.Y** is not set to 65534 (0xFFFE), halftone pattern sizes other than HT_PATSIZE_8x8_M or HT_PATSIZE_8x8 are converted to HT_PATSIZE_DEFAULT.

Setting the **RedGamma**, **BlueGamma**, and **GreenGamma** members of this structure to 0xFFFF can affect color management in printers when [Image Color Management](https://learn.microsoft.com/windows-hardware/drivers/display/image-color-management) (ICM) is disabled. In this situation, the GDI halftone module switches from performing its own color management to performing none, which potentially can cause a significant change in the resulting printer output. When ICM is enabled (and **RedGamma**, **BlueGamma**, and **GreenGamma** are set to 0XFFFF), there is no difference in color output. For more information, see [Color Management for Printers](https://learn.microsoft.com/windows-hardware/drivers/print/color-management-for-printers).

Any values in the COLORINFO structure that are out of the specified range default to the NTSC values.

## See also

[CIECHROMA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ciechroma)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo)