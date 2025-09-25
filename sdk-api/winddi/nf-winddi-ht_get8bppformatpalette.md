# HT_Get8BPPFormatPalette function

## Description

The **HT_Get8BPPFormatPalette** function returns a halftone palette for use on standard 8-bits per pixel device types.

## Parameters

### `pPaletteEntry` [out]

Pointer to an array of PALETTEENTRY structures (described in the Microsoft Windows SDK documentation). When this pointer is not **NULL**, GDI assumes that it points to valid memory space in which GDI can place the entire 8-bits per pixel halftone palette.

### `RedGamma` [in]

Specifies the red, green, and blue gamma value. This USHORT value is interpreted as a real number whose four least-significant digits are to the right of the (implied) decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `GreenGamma` [in]

Specifies the red, green, and blue gamma value. This USHORT value is interpreted as a real number whose four least-significant digits are to the right of the (implied) decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `BlueGamma` [in]

Specifies the red, green, and blue gamma value. This USHORT value is interpreted as a real number whose four least-significant digits are to the right of the (implied) decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

## Return value

If *pPaletteEntry* is not **NULL**, the return value is the number of PALETTEENTRY structures that GDI filled in starting at the memory location pointed to by *pPaletteEntry*. If *pPaletteEntry* is **NULL**, the return value is the total count of PALETTEENTRY structures required to store the 8-bits per pixel halftone palette.

## Remarks

**HT_Get8BPPFormatPalette** is a halftone-related GDI service that drivers can use to acquire the system's standard 8-bits per pixel halftone palette.