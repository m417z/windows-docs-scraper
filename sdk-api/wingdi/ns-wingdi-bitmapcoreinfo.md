# BITMAPCOREINFO structure

## Description

The **BITMAPCOREINFO** structure defines the dimensions and color information for a DIB.

## Members

### `bmciHeader`

A [BITMAPCOREHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreheader) structure that contains information about the dimensions and color format of a DIB.

### `bmciColors`

Specifies an array of [RGBTRIPLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbtriple) structures that define the colors in the bitmap.

## Remarks

A DIB consists of two parts: a **BITMAPCOREINFO** structure describing the dimensions and colors of the bitmap, and an array of bytes defining the pixels of the bitmap. The bits in the array are packed together, but each scan line must be padded with zeros to end on a **LONG** boundary. The origin of the bitmap is the lower-left corner.

The **bcBitCount** member of the [BITMAPCOREHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreheader) structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 1 | The bitmap is monochrome, and the **bmciColors** member contains two entries. Each bit in the bitmap array represents a pixel. If the bit is clear, the pixel is displayed with the color of the first entry in the **bmciColors** table; if the bit is set, the pixel has the color of the second entry in the table. |
| 4 | The bitmap has a maximum of 16 colors, and the **bmciColors** member contains up to 16 entries. Each pixel in the bitmap is represented by a 4-bit index into the color table. For example, if the first byte in the bitmap is 0x1F, the byte represents two pixels. The first pixel contains the color in the second table entry, and the second pixel contains the color in the sixteenth table entry. |
| 8 | The bitmap has a maximum of 256 colors, and the **bmciColors** member contains up to 256 entries. In this case, each byte in the array represents a single pixel. |
| 24 | The bitmap has a maximum of 2 (24) colors, and the **bmciColors** member is **NULL**. Each three-byte triplet in the bitmap array represents the relative intensities of blue, green, and red, respectively, for a pixel. |

The colors in the **bmciColors** table should appear in order of importance.

Alternatively, for functions that use DIBs, the **bmciColors** member can be an array of 16-bit unsigned integers that specify indexes into the currently realized logical palette, instead of explicit RGB values. In this case, an application using the bitmap must call the DIB functions ( [CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap), [CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush), and [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) ) with the *iUsage* parameter set to DIB_PAL_COLORS.

**Note**

The **bmciColors** member should not contain palette indexes if the bitmap is to be stored in a file or transferred to another application. Unless the application has exclusive use and control of the bitmap, the bitmap color table should contain explicit RGB values.

## See also

[BITMAPCOREHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreheader)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[RGBTRIPLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbtriple)