# HT_Get8BPPMaskPalette function

## Description

The **HT_Get8BPPMaskPalette** function returns a mask palette for an 8-bits-per-pixel device type.

## Parameters

### `pPaletteEntry` [in, out]

Pointer to the array of PALETTEENTRY structures (described in the Windows SDK documentation) to be filled in. GDI assumes that it points to valid memory space in which GDI can place the entire 8-bit-per-pixel halftone palette.

For a driver that runs on Windows XP and later operating system versions, GDI checks *pPaletteEntry*[0] to determine how to return the composed CMY palette. If *pPaletteEntry*[0] is set to 'RGB0', the palette will be in one of the CMY_INVERTED modes and will have its indexes inverted. That is, index 0 in the palette is black, and index 255 is white. If *pPaletteEntry*[0] is not set to 'RGB0', the palette is a normal CMY palette, with index 0 being white and index 255 being black. See [Using GDI 8-Bit-Per-Pixel CMY Mask Modes](https://learn.microsoft.com/windows-hardware/drivers/display/using-gdi-8-bit-per-pixel-cmy-mask-modes) for new requirements and details on how to use this parameter.

Windows 2000 ignores any value the driver places in *pPaletteEntry*[0]. For this reason, if your driver is intended to run on Windows 2000 *and* on Windows XP or later versions, and your driver sets *pPaletteEntry*[0] to 'RGB0', the bitmaps your driver receives from Windows XP and later might have their colors inverted, relative to those received from Windows 2000. Therefore, such a driver must examine the palette before downloading a bitmap.

### `Use8BPPMaskPal` [in]

Indicates which type of palette should be returned. When *Use8BPPMaskPal* is **TRUE**, **HT_Get8BPPMaskPalette** sets the *pPaletteEntry* parameter with the address of a CMY palette (an array of PALETTEENTRY structures) that is described by the bitmask specified in *CMYMask*. When *Use8BPPMaskPal* is **FALSE**, the function sets *pPaletteEntry* with the address of a standard RGB 8-bit-per-pixel halftone palette.

### `CMYMask` [in]

Specifies information about the array of PALETTEENTRY structures pointed to by *pPaletteEntry*. This parameter can have one of the following values:

| Value | Meaning |
| --- | --- |
| 0 | Gray scale with 256 levels |
| 1 | Five levels each of cyan, magenta, and yellow (each ranging from 0 to 4), for a total of 125 colors |
| 2 | Six levels each of cyan, magenta, and yellow (each ranging from 0 to 5), for a total of 216 colors |
| 3 to 255 | A bitmask that specifies that maximum number of levels of cyan, magenta, and yellow, respectively. |

Drivers running on Windows 2000 should be restricted to 8-bits-per-pixel monochrome. That is, the value of *CMYMask* used should be 0.

For Windows XP and later operating system versions, and for all values of *CMYMask*, the value in *pPaletteEntry*[0] determines whether the palette that follows *pPaletteEntry*[0] is a normal CMY palette, or one of the CMY_INVERTED mode palettes. For more information, see the description of the *pPaletteEntry* parameter.

For values of *CMYMask* from 3 to 255, inclusive, the value is a bitmask in which groups of bits have the following meanings:

* The three highest bits (bits 7,6,5) specify the number of levels of cyan. At most, seven levels of cyan (levels 1 to 7) are possible.
* The middle three bits (bits 4,3,2) specify the number of levels of magenta. At most, seven levels of magenta (levels 1 to 7) are possible.
* The two lowest bits (bits 1,0) specify the number of levels of yellow. At most, three levels of yellow (levels 1 to 3) are possible.

For values of *CMYMask* ranging from 3 to 255, any bitmask combination in which the cyan, magenta, or yellow level bits are zero is invalid. In such cases, **HT_Get8BPPMaskPalette** returns a palette count of zero. See [Using GDI 8-Bit-Per-Pixel CMY Mask Modes](https://learn.microsoft.com/windows-hardware/drivers/display/using-gdi-8-bit-per-pixel-cmy-mask-modes) for more information.

### `RedGamma` [in]

If *Use8BPPMaskPal* is **TRUE**, the value of this parameter is not used. In that case, gamma values will be specified in the **ciDevice** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure.

If *Use8BPPMaskPal* is **FALSE**, the value of this parameter specifies the red gamma value, out of the red, green and blue gamma values that GDI is to use to gamma-correct the palette. The USHORT value is interpreted as a real number whose four least-significant digits are to the right of the decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `GreenGamma` [in]

If *Use8BPPMaskPal* is **TRUE**, the value of this parameter is not used. In that case, gamma values will be specified in the **ciDevice** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure.

If *Use8BPPMaskPal* is **FALSE**, the value of this parameter specifies the green gamma value, out of the red, green and blue gamma values that GDI is to use to gamma-correct the palette. The USHORT value is interpreted as a real number whose four least-significant digits are to the right of the decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `BlueGamma` [in]

If *Use8BPPMaskPal* is **TRUE**, the value of this parameter is not used. In that case, gamma values will be specified in the **ciDevice** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure.

If *Use8BPPMaskPal* is **FALSE**, the value of this parameter specifies the blue gamma value, out of the red, green and blue gamma values that GDI is to use to gamma-correct the palette. The USHORT value is interpreted as a real number whose four least-significant digits are to the right of the decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

## Return value

If *pPaletteEntry* is not **NULL**, **HT_Get8BPPMaskPalette** returns the number of PALETTEENTRY structures that GDI filled out in the array to which *pPaletteEntry* points. If *pPaletteEntry* is **NULL**, the value returned is the total count of PALETTEENTRY structures required to store the halftone palette.

If an illegal value of the *CMYMask* parameter is used in the call to this function, **HT_Get8BPPMaskPalette** returns a value of zero.

## Remarks

The PALETTEENTRY structure is documented in the Windows SDK documentation.

Calling **HT_Get8BPPMaskPalette** with *Use8BPPMaskPal* set **FALSE** is equivalent to calling [HT_Get8BPPFormatPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-ht_get8bppformatpalette).

See [Using GDI 8-Bit-Per-Pixel CMY Mask Modes](https://learn.microsoft.com/windows-hardware/drivers/display/using-gdi-8-bit-per-pixel-cmy-mask-modes) for more information about this function and how its parameters are used.

## See also

[HT_Get8BPPFormatPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-ht_get8bppformatpalette)