# BITMAPV4HEADER structure

## Description

The **BITMAPV4HEADER** structure is the bitmap information header file. It is an extended version of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

Applications can use the
[BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header) structure for added functionality.

## Members

### `bV4Size`

The number of bytes required by the structure. Applications should use this member to determine which bitmap information header structure is being used.

### `bV4Width`

The width of the bitmap, in pixels.

 If **bV4Compression** is BI_JPEG or BI_PNG, **bV4Width** specifies the width of the JPEG or PNG image in pixels.

### `bV4Height`

The height of the bitmap, in pixels. If **bV4Height** is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If **bV4Height** is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

If **bV4Height** is negative, indicating a top-down DIB, **bV4Compression** must be either BI_RGB or BI_BITFIELDS. Top-down DIBs cannot be compressed.

 If **bV4Compression** is BI_JPEG or BI_PNG, **bV4Height** specifies the height of the JPEG or PNG image in pixels.

### `bV4Planes`

The number of planes for the target device. This value must be set to 1.

### `bV4BitCount`

The number of bits-per-pixel. The **bV4BitCount** member of the **BITMAPV4HEADER** structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The number of bits-per-pixel is specified or is implied by the JPEG or PNG file format. |
| 1 | The bitmap is monochrome, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains two entries. Each bit in the bitmap array represents a pixel. If the bit is clear, the pixel is displayed with the color of the first entry in the **bmiColors** table; if the bit is set, the pixel has the color of the second entry in the table. |
| 4 | The bitmap has a maximum of 16 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains up to 16 entries. Each pixel in the bitmap is represented by a 4-bit index into the color table. For example, if the first byte in the bitmap is 0x1F, the byte represents two pixels. The first pixel contains the color in the second table entry, and the second pixel contains the color in the sixteenth table entry. |
| 8 | The bitmap has a maximum of 256 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains up to 256 entries. In this case, each byte in the array represents a single pixel. |
| 16 | The bitmap has a maximum of 2^16 colors. If the **bV4Compression** member of the **BITMAPV4HEADER** structure is BI_RGB, the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each **WORD** in the bitmap array represents a single pixel. The relative intensities of red, green, and blue are represented with five bits for each color component. The value for blue is in the least significant five bits, followed by five bits each for green and red, respectively. The most significant bit is not used. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **bV4ClrUsed** member of the **BITMAPV4HEADER**.If the **bV4Compression** member of the **BITMAPV4HEADER** is BI_BITFIELDS, the **bmiColors** member contains three **DWORD** color masks that specify the red, green, and blue components of each pixel. Each **WORD** in the bitmap array represents a single pixel. |
| 24 | The bitmap has a maximum of 2^24 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each 3-byte triplet in the bitmap array represents the relative intensities of blue, green, and red for a pixel. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **bV4ClrUsed** member of the **BITMAPV4HEADER**. |
| 32 | The bitmap has a maximum of 2^32 colors. If the **bV4Compression** member of the **BITMAPV4HEADER** is BI_RGB, the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each **DWORD** in the bitmap array represents the relative intensities of blue, green, and red for a pixel. The value for blue is in the least significant 8 bits, followed by 8 bits each for green and red. The high byte in each **DWORD** is not used. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **bV4ClrUsed** member of the **BITMAPV4HEADER**.If the **bV4Compression** member of the **BITMAPV4HEADER** is BI_BITFIELDS, the **bmiColors** member contains three **DWORD** color masks that specify the red, green, and blue components of each pixel. Each **DWORD** in the bitmap array represents a single pixel. |

### `bV4V4Compression`

The type of compression for a compressed bottom-up bitmap (top-down DIBs cannot be compressed). This member can be one of the following values.

| Value | Description |
| --- | --- |
| BI_RGB | An uncompressed format. |
| BI_RLE8 | A run-length encoded (RLE) format for bitmaps with 8 bpp. The compression format is a 2-byte format consisting of a count byte followed by a byte containing a color index. For more information, see [Bitmap Compression](https://learn.microsoft.com/windows/desktop/gdi/bitmap-compression). |
| BI_RLE4 | An RLE format for bitmaps with 4 bpp. The compression format is a 2-byte format consisting of a count byte followed by two word-length color indexes. For more information, see [Bitmap Compression](https://learn.microsoft.com/windows/desktop/gdi/bitmap-compression). |
| BI_BITFIELDS | Specifies that the bitmap is not compressed. The members **bV4RedMask**, **bV4GreenMask**, and **bV4BlueMask** specify the red, green, and blue components for each pixel. This is valid when used with 16- and 32-bpp bitmaps. |
| BI_JPEG | Specifies that the image is compressed using the JPEG file interchange format. JPEG compression trades off compression against loss; it can achieve a compression ratio of 20:1 with little noticeable loss. |
| BI_PNG | Specifies that the image is compressed using the PNG file interchange format. |

### `bV4SizeImage`

The size, in bytes, of the image. This may be set to zero for BI_RGB bitmaps.

 If **bV4Compression** is BI_JPEG or BI_PNG, **bV4SizeImage** is the size of the JPEG or PNG image buffer.

### `bV4XPelsPerMeter`

The horizontal resolution, in pixels-per-meter, of the target device for the bitmap. An application can use this value to select a bitmap from a resource group that best matches the characteristics of the current device.

### `bV4YPelsPerMeter`

The vertical resolution, in pixels-per-meter, of the target device for the bitmap.

### `bV4ClrUsed`

The number of color indexes in the color table that are actually used by the bitmap. If this value is zero, the bitmap uses the maximum number of colors corresponding to the value of the **bV4BitCount** member for the compression mode specified by **bV4Compression**.

If **bV4ClrUsed** is nonzero and the **bV4BitCount** member is less than 16, the **bV4ClrUsed** member specifies the actual number of colors the graphics engine or device driver accesses. If **bV4BitCount** is 16 or greater, the **bV4ClrUsed** member specifies the size of the color table used to optimize performance of the system color palettes. If **bV4BitCount** equals 16 or 32, the optimal color palette starts immediately following the **BITMAPV4HEADER**.

### `bV4ClrImportant`

The number of color indexes that are required for displaying the bitmap. If this value is zero, all colors are important.

### `bV4RedMask`

Color mask that specifies the red component of each pixel, valid only if **bV4Compression** is set to BI_BITFIELDS.

### `bV4GreenMask`

Color mask that specifies the green component of each pixel, valid only if **bV4Compression** is set to BI_BITFIELDS.

### `bV4BlueMask`

Color mask that specifies the blue component of each pixel, valid only if **bV4Compression** is set to BI_BITFIELDS.

### `bV4AlphaMask`

Color mask that specifies the alpha component of each pixel.

### `bV4CSType`

The color space of the DIB. The following table lists the value for **bV4CSType**.

| Value | Meaning |
| --- | --- |
| LCS_CALIBRATED_RGB | This value indicates that endpoints and gamma values are given in the appropriate fields. |

See the [LOGCOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logcolorspacea) structure for information that defines a logical color space.

### `bV4Endpoints`

A [CIEXYZTRIPLE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-ciexyztriple) structure that specifies the x, y, and z coordinates of the three colors that correspond to the red, green, and blue endpoints for the logical color space associated with the bitmap. This member is ignored unless the **bV4CSType** member specifies LCS_CALIBRATED_RGB.

**Note** A *color space* is a model for representing color numerically in terms of three or more coordinates. For example, the RGB color space represents colors in terms of the red, green, and blue coordinates.

### `bV4GammaRed`

Tone response curve for red. This member is ignored unless color values are calibrated RGB values and **bV4CSType** is set to LCS_CALIBRATED_RGB. Specify in unsigned fixed 16.16 format. The upper 16 bits are the unsigned integer value. The lower 16 bits are the fractional part.

### `bV4GammaGreen`

Tone response curve for green. Used if **bV4CSType** is set to LCS_CALIBRATED_RGB. Specify in unsigned fixed 16.16 format. The upper 16 bits are the unsigned integer value. The lower 16 bits are the fractional part.

### `bV4GammaBlue`

Tone response curve for blue. Used if **bV4CSType** is set to LCS_CALIBRATED_RGB. Specify in unsigned fixed 16.16 format. The upper 16 bits are the unsigned integer value. The lower 16 bits are the fractional part.

## Remarks

The **BITMAPV4HEADER** structure is extended to allow a JPEG or PNG image to be passed as the source image to [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CIEXYZTRIPLE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-ciexyztriple)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[LOGCOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logcolorspacea)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)