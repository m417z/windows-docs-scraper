# BITMAPV5HEADER structure

## Description

The **BITMAPV5HEADER** structure is the bitmap information header file. It is an extended version of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

## Members

### `bV5Size`

The number of bytes required by the structure. Applications should use this member to determine which bitmap information header structure is being used.

### `bV5Width`

The width of the bitmap, in pixels.

If **bV5Compression** is BI_JPEG or BI_PNG, the **bV5Width** member specifies the width of the decompressed JPEG or PNG image in pixels.

### `bV5Height`

The height of the bitmap, in pixels. If the value of **bV5Height** is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If **bV5Height** value is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

If **bV5Height** is negative, indicating a top-down DIB, **bV5Compression** must be either BI_RGB or BI_BITFIELDS. Top-down DIBs cannot be compressed.

If **bV5Compression** is BI_JPEG or BI_PNG, the **bV5Height** member specifies the height of the decompressed JPEG or PNG image in pixels.

### `bV5Planes`

The number of planes for the target device. This value must be set to 1.

### `bV5BitCount`

The number of bits that define each pixel and the maximum number of colors in the bitmap.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The number of bits per pixel is specified or is implied by the JPEG or PNG file format. |
| 1 | The bitmap is monochrome, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains two entries. Each bit in the bitmap array represents a pixel. If the bit is clear, the pixel is displayed with the color of the first entry in the **bmiColors** color table. If the bit is set, the pixel has the color of the second entry in the table. |
| 4 | The bitmap has a maximum of 16 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains up to 16 entries. Each pixel in the bitmap is represented by a 4-bit index into the color table. For example, if the first byte in the bitmap is 0x1F, the byte represents two pixels. The first pixel contains the color in the second table entry, and the second pixel contains the color in the sixteenth table entry. |
| 8 | The bitmap has a maximum of 256 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains up to 256 entries. In this case, each byte in the array represents a single pixel. |
| 16 | The bitmap has a maximum of 2^16 colors. If the **bV5Compression** member of the **BITMAPV5HEADER** structure is BI_RGB, the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each **WORD** in the bitmap array represents a single pixel. The relative intensities of red, green, and blue are represented with five bits for each color component. The value for blue is in the least significant five bits, followed by five bits each for green and red. The most significant bit is not used. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **bV5ClrUsed** member of the **BITMAPV5HEADER**.If the **bV5Compression** member of the **BITMAPV5HEADER** is BI_BITFIELDS, the **bmiColors** member contains three **DWORD** color masks that specify the red, green, and blue components, respectively, of each pixel. Each **WORD** in the bitmap array represents a single pixel.<br><br>When the **bV5Compression** member is BI_BITFIELDS, bits set in each **DWORD** mask must be contiguous and should not overlap the bits of another mask. All the bits in the pixel do not need to be used. |
| 24 | The bitmap has a maximum of 2^24 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each 3-byte triplet in the bitmap array represents the relative intensities of blue, green, and red, respectively, for a pixel. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **bV5ClrUsed** member of the **BITMAPV5HEADER** structure. |
| 32 | The bitmap has a maximum of 2^32 colors. If the **bV5Compression** member of the **BITMAPV5HEADER** is BI_RGB, the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each **DWORD** in the bitmap array represents the relative intensities of blue, green, and red for a pixel. The value for blue is in the least significant 8 bits, followed by 8 bits each for green and red. The high byte in each **DWORD** is not used. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **bV5ClrUsed** member of the **BITMAPV5HEADER**.If the **bV5Compression** member of the **BITMAPV5HEADER** is BI_BITFIELDS, the **bmiColors** member contains three **DWORD** color masks that specify the red, green, and blue components of each pixel. Each **DWORD** in the bitmap array represents a single pixel. |

### `bV5Compression`

Specifies that the bitmap is not compressed. The **bV5RedMask**, **bV5GreenMask**, and **bV5BlueMask** members specify the red, green, and blue components of each pixel. This is valid when used with 16- and 32-bpp bitmaps. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| BI_RGB | An uncompressed format. |
| BI_RLE8 | A run-length encoded (RLE) format for bitmaps with 8 bpp. The compression format is a two-byte format consisting of a count byte followed by a byte containing a color index. If **bV5Compression** is BI_RGB and the **bV5BitCount** member is 16, 24, or 32, the bitmap array specifies the actual intensities of blue, green, and red rather than using color table indexes. For more information, see [Bitmap Compression](https://learn.microsoft.com/windows/desktop/gdi/bitmap-compression). |
| BI_RLE4 | An RLE format for bitmaps with 4 bpp. The compression format is a two-byte format consisting of a count byte followed by two word-length color indexes. For more information, see [Bitmap Compression](https://learn.microsoft.com/windows/desktop/gdi/bitmap-compression). |
| BI_BITFIELDS | Specifies that the bitmap is not compressed and that the color masks for the red, green, and blue components of each pixel are specified in the **bV5RedMask**, **bV5GreenMask**, and **bV5BlueMask** members. This is valid when used with 16- and 32-bpp bitmaps. |
| BI_JPEG | Specifies that the image is compressed using the JPEG file Interchange Format. JPEG compression trades off compression against loss; it can achieve a compression ratio of 20:1 with little noticeable loss. |
| BI_PNG | Specifies that the image is compressed using the PNG file Interchange Format. |

### `bV5SizeImage`

The size, in bytes, of the image. This may be set to zero for BI_RGB bitmaps.

If **bV5Compression** is BI_JPEG or BI_PNG, **bV5SizeImage** is the size of the JPEG or PNG image buffer.

### `bV5XPelsPerMeter`

The horizontal resolution, in pixels-per-meter, of the target device for the bitmap. An application can use this value to select a bitmap from a resource group that best matches the characteristics of the current device.

### `bV5YPelsPerMeter`

The vertical resolution, in pixels-per-meter, of the target device for the bitmap.

### `bV5ClrUsed`

The number of color indexes in the color table that are actually used by the bitmap. If this value is zero, the bitmap uses the maximum number of colors corresponding to the value of the **bV5BitCount** member for the compression mode specified by **bV5Compression**.

If **bV5ClrUsed** is nonzero and **bV5BitCount** is less than 16, the **bV5ClrUsed** member specifies the actual number of colors the graphics engine or device driver accesses. If **bV5BitCount** is 16 or greater, the **bV5ClrUsed** member specifies the size of the color table used to optimize performance of the system color palettes. If **bV5BitCount** equals 16 or 32, the optimal color palette starts immediately following the **BITMAPV5HEADER**. If **bV5ClrUsed** is nonzero, the color table is used on palettized devices, and **bV5ClrUsed** specifies the number of entries.

### `bV5ClrImportant`

The number of color indexes that are required for displaying the bitmap. If this value is zero, all colors are required.

### `bV5RedMask`

Color mask that specifies the red component of each pixel, valid only if **bV5Compression** is set to BI_BITFIELDS.

### `bV5GreenMask`

Color mask that specifies the green component of each pixel, valid only if **bV5Compression** is set to BI_BITFIELDS.

### `bV5BlueMask`

Color mask that specifies the blue component of each pixel, valid only if **bV5Compression** is set to BI_BITFIELDS.

### `bV5AlphaMask`

Color mask that specifies the alpha component of each pixel.

### `bV5CSType`

The color space of the DIB.

The following table specifies the values for **bV5CSType**.

| Value | Meaning |
| --- | --- |
| LCS_CALIBRATED_RGB | This value implies that endpoints and gamma values are given in the appropriate fields. |
| LCS_sRGB | Specifies that the bitmap is in sRGB color space. |
| LCS_WINDOWS_COLOR_SPACE | This value indicates that the bitmap is in the system default color space, sRGB. |
| PROFILE_LINKED | This value indicates that **bV5ProfileData** points to the file name of the profile to use (gamma and endpoints values are ignored). |
| PROFILE_EMBEDDED | This value indicates that **bV5ProfileData** points to a memory buffer that contains the profile to be used (gamma and endpoints values are ignored). |

See the [LOGCOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logcolorspacea) structure for information that defines a logical color space.

### `bV5Endpoints`

A [CIEXYZTRIPLE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-ciexyztriple) structure that specifies the x, y, and z coordinates of the three colors that correspond to the red, green, and blue endpoints for the logical color space associated with the bitmap. This member is ignored unless the **bV5CSType** member specifies LCS_CALIBRATED_RGB.

### `bV5GammaRed`

Toned response curve for red. Used if **bV5CSType** is set to LCS_CALIBRATED_RGB. Specify in unsigned fixed 16.16 format. The upper 16 bits are the unsigned integer value. The lower 16 bits are the fractional part.

### `bV5GammaGreen`

Toned response curve for green. Used if **bV5CSType** is set to LCS_CALIBRATED_RGB. Specify in unsigned fixed 16.16 format. The upper 16 bits are the unsigned integer value. The lower 16 bits are the fractional part.

### `bV5GammaBlue`

Toned response curve for blue. Used if **bV5CSType** is set to LCS_CALIBRATED_RGB. Specify in unsigned fixed 16.16 format. The upper 16 bits are the unsigned integer value. The lower 16 bits are the fractional part.

### `bV5Intent`

Rendering intent for bitmap. This can be one of the following values.

| Value | Intent | ICC name | Meaning |
| --- | --- | --- | --- |
| LCS_GM_ABS_COLORIMETRIC | Match | Absolute Colorimetric | Maintains the white point. Matches the colors to their nearest color in the destination gamut. |
| LCS_GM_BUSINESS | Graphic | Saturation | Maintains saturation. Used for business charts and other situations in which undithered colors are required. |
| LCS_GM_GRAPHICS | Proof | Relative Colorimetric | Maintains colorimetric match. Used for graphic designs and named colors. |
| LCS_GM_IMAGES | Picture | Perceptual | Maintains contrast. Used for photographs and natural images. |

### `bV5ProfileData`

The offset, in bytes, from the beginning of the **BITMAPV5HEADER** structure to the start of the profile data. If the profile is embedded, profile data is the actual profile, and it is linked. (The profile data is the null-terminated file name of the profile.) This cannot be a Unicode string. It must be composed exclusively of characters from the Windows character set (code page 1252). These profile members are ignored unless the **bV5CSType** member specifies PROFILE_LINKED or PROFILE_EMBEDDED.

### `bV5ProfileSize`

Size, in bytes, of embedded profile data.

### `bV5Reserved`

This member has been reserved. Its value should be set to zero.

## Remarks

If **bV5Height** is negative, indicating a top-down DIB, **bV5Compression** must be either BI_RGB or BI_BITFIELDS. Top-down DIBs cannot be compressed.

The Independent Color Management interface (ICM) 2.0 allows International Color Consortium (ICC) color profiles to be linked or embedded in DIBs (DIBs). See [Using Structures](https://learn.microsoft.com/windows/win32/wcs/using-structures-in-wcs-1-0) for more information.

When a DIB is loaded into memory, the profile data (if present) should follow the color table, and the **bV5ProfileData** should provide the offset of the profile data from the beginning of the **BITMAPV5HEADER** structure. The value stored in **bV5ProfileData** will be different from the value returned by the **sizeof** operator given the **BITMAPV5HEADER** argument, because **bV5ProfileData** is the offset in bytes from the beginning of the **BITMAPV5HEADER** structure to the start of the profile data. (Bitmap bits do not follow the color table in memory). Applications should modify the **bV5ProfileData** member after loading the DIB into memory.

For packed DIBs, the profile data should follow the bitmap bits similar to the file format. The **bV5ProfileData** member should still give the offset of the profile data from the beginning of the **BITMAPV5HEADER**.

Applications should access the profile data only when **bV5Size** equals the size of the **BITMAPV5HEADER** and **bV5CSType** equals PROFILE_EMBEDDED or PROFILE_LINKED.

If a profile is linked, the path of the profile can be any fully qualified name (including a network path) that can be opened using the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[BITMAPV4HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv4header)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CIEXYZTRIPLE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-ciexyztriple)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[LOGCOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logcolorspacea)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)