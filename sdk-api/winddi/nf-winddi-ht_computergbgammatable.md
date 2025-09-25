# HT_ComputeRGBGammaTable function

## Description

The **HT_ComputeRGBGammaTable** function causes GDI to compute device red, green, and blue intensities based on gamma numbers.

## Parameters

### `GammaTableEntries` [in]

Specifies the total number of steps in the table for each of red, green, and blue intensities. This value must greater than 1 and less than or equal to 256 (that is, 2 <= *GammaTableEntries* <= 256). For example, a value of 256 means there are 256 red entries, 256 green entries, and 256 blue entries in the gamma table.

### `GammaTableType` [in]

Specifies *pGammaTable*'s organization. Valid table types are:

| GammaTableType | Meaning |
| --- | --- |
| 0 | The gamma table's red, green, and blue values are interleaved together. Each gamma step is 3 bytes; 1 byte each for red, green, and blue. |
| 1 | The red, green, and blue tables are packed separately; that is, the entire red table is followed by the entire green table, which is followed by the entire blue table. Individual entries are 1 byte each, making each subtable a total of *GammaTableEntries* bytes in length. |

### `RedGamma` [in]

Specifies the red gamma value. This USHORT value is interpreted as a real number whose four least-significant digits are to the right of the (implied) decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `GreenGamma` [in]

Specifies the green gamma value. This USHORT value is interpreted as a real number whose four least-significant digits are to the right of the (implied) decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `BlueGamma` [in]

Specifies the blue gamma value. This USHORT value is interpreted as a real number whose four least-significant digits are to the right of the (implied) decimal point. For example, a gamma value of 10000 represents the real number 1.0000, and 12345 represents 1.2345. The minimum gamma value allowed is 0.0000, and the maximum allowable value is 6.5535.

### `pGammaTable` [out]

Pointer to the array of bytes in which the gamma table's red, green, and blue intensities will be written. The returned table is organized as specified by the *GammaTableType* parameter.

## Return value

The return value is the number of gamma entries written to *pGammaTable*; upon success, this value is equal to *GammaTableEntries*. If *GammaTableEntries* is less than 2 or greater than 256, the return value is 0.

The red, green, and blue intensities returned in *pGammaTable* range from 0 to 255.

## Remarks

GDI halftone service routines use a special palette to do halftoning. If the device selects an 8-bit per pixel palette from a pool of 24-bit device colors for a 16-bit or 24-bit type surface, GDI assumes red, green, and blue color steps; each has equal brightness.

GDI provides this service so that the driver can query the 8-bit per pixel halftone palette used by GDI or compute gamma corrected and equalized RGB color intensities for the device.