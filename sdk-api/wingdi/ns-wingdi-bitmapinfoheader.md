# BITMAPINFOHEADER structure

## Description

The **BITMAPINFOHEADER** structure contains information about the dimensions and color format of a device-independent bitmap (DIB).

## Members

### `biSize`

The number of bytes required by the structure. This value does not include the size of the color table or the size of the color masks, if they are appended to the end of the structure.

### `biWidth`

The width of the bitmap, in pixels.

If **biCompression** is BI_JPEG or BI_PNG, the **biWidth** member specifies the width of the decompressed JPEG or PNG image file, respectively.

### `biHeight`

The height of the bitmap, in pixels. If **biHeight** is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If **biHeight** is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

If **biHeight** is negative, indicating a top-down DIB, **biCompression** must be either BI_RGB or BI_BITFIELDS. Top-down DIBs cannot be compressed.

If **biCompression** is BI_JPEG or BI_PNG, the **biHeight** member specifies the height of the decompressed JPEG or PNG image file, respectively.

### `biPlanes`

The number of planes for the target device. This value must be set to 1.

### `biBitCount`

The number of bits-per-pixel. The **biBitCount** member of the **BITMAPINFOHEADER** structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The number of bits-per-pixel is specified or is implied by the JPEG or PNG format. |
| 1 | The bitmap is monochrome, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains two entries. Each bit in the bitmap array represents a pixel. If the bit is clear, the pixel is displayed with the color of the first entry in the **bmiColors** table; if the bit is set, the pixel has the color of the second entry in the table. |
| 4 | The bitmap has a maximum of 16 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains up to 16 entries. Each pixel in the bitmap is represented by a 4-bit index into the color table. For example, if the first byte in the bitmap is 0x1F, the byte represents two pixels. The first pixel contains the color in the second table entry, and the second pixel contains the color in the sixteenth table entry. |
| 8 | The bitmap has a maximum of 256 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) contains up to 256 entries. In this case, each byte in the array represents a single pixel. |
| 16 | The bitmap has a maximum of 2^16 colors. If the **biCompression** member of the **BITMAPINFOHEADER** is BI_RGB, the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each **WORD** in the bitmap array represents a single pixel. The relative intensities of red, green, and blue are represented with five bits for each color component. The value for blue is in the least significant five bits, followed by five bits each for green and red. The most significant bit is not used. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **biClrUsed** member of the **BITMAPINFOHEADER**.<br><br>If the **biCompression** member of the **BITMAPINFOHEADER** is BI_BITFIELDS, the **bmiColors** member contains three **DWORD** color masks that specify the red, green, and blue components, respectively, of each pixel. Each **WORD** in the bitmap array represents a single pixel.<br><br>When the **biCompression** member is BI_BITFIELDS, bits set in each **DWORD** mask must be contiguous and should not overlap the bits of another mask. All the bits in the pixel do not have to be used. |
| 24 | The bitmap has a maximum of 2^24 colors, and the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each 3-byte triplet in the bitmap array represents the relative intensities of blue, green, and red, respectively, for a pixel. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **biClrUsed** member of the **BITMAPINFOHEADER**. |
| 32 | The bitmap has a maximum of 2^32 colors. If the **biCompression** member of the **BITMAPINFOHEADER** is BI_RGB, the **bmiColors** member of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) is **NULL**. Each **DWORD** in the bitmap array represents the relative intensities of blue, green, and red for a pixel. The value for blue is in the least significant 8 bits, followed by 8 bits each for green and red. The high byte in each **DWORD** is not used. The **bmiColors** color table is used for optimizing colors used on palette-based devices, and must contain the number of entries specified by the **biClrUsed** member of the **BITMAPINFOHEADER**.<br><br>If the **biCompression** member of the **BITMAPINFOHEADER** is BI_BITFIELDS, the **bmiColors** member contains three **DWORD** color masks that specify the red, green, and blue components, respectively, of each pixel. Each **DWORD** in the bitmap array represents a single pixel.<br><br>When the **biCompression** member is BI_BITFIELDS, bits set in each **DWORD** mask must be contiguous and should not overlap the bits of another mask. All the bits in the pixel do not need to be used. |

### `biCompression`

The type of compression for a compressed bottom-up bitmap (top-down DIBs cannot be compressed). This member can be one of the following values.

| Value | Description |
| --- | --- |
| **BI_RGB** | An uncompressed format. |
| **BI_RLE8** | A run-length encoded (RLE) format for bitmaps with 8 bpp. The compression format is a 2-byte format consisting of a count byte followed by a byte containing a color index. For more information, see [Bitmap Compression](https://learn.microsoft.com/windows/desktop/gdi/bitmap-compression). |
| **BI_RLE4** | An RLE format for bitmaps with 4 bpp. The compression format is a 2-byte format consisting of a count byte followed by two word-length color indexes. For more information, see [Bitmap Compression](https://learn.microsoft.com/windows/desktop/gdi/bitmap-compression). |
| **BI_BITFIELDS** | Specifies that the bitmap is not compressed and that the color table consists of three **DWORD** color masks that specify the red, green, and blue components, respectively, of each pixel. This is valid when used with 16- and 32-bpp bitmaps. |
| **BI_JPEG** | Indicates that the image is a JPEG image. |
| **BI_PNG** | Indicates that the image is a PNG image. |

### `biSizeImage`

The size, in bytes, of the image. This may be set to zero for BI_RGB bitmaps.

If **biCompression** is BI_JPEG or BI_PNG, **biSizeImage** indicates the size of the JPEG or PNG image buffer, respectively.

### `biXPelsPerMeter`

The horizontal resolution, in pixels-per-meter, of the target device for the bitmap. An application can use this value to select a bitmap from a resource group that best matches the characteristics of the current device.

### `biYPelsPerMeter`

The vertical resolution, in pixels-per-meter, of the target device for the bitmap.

### `biClrUsed`

The number of color indexes in the color table that are actually used by the bitmap. If this value is zero, the bitmap uses the maximum number of colors corresponding to the value of the **biBitCount** member for the compression mode specified by **biCompression**.

If **biClrUsed** is nonzero and the **biBitCount** member is less than 16, the **biClrUsed** member specifies the actual number of colors the graphics engine or device driver accesses. If **biBitCount** is 16 or greater, the **biClrUsed** member specifies the size of the color table used to optimize performance of the system color palettes. If **biBitCount** equals 16 or 32, the optimal color palette starts immediately following the three **DWORD** masks.

When the bitmap array immediately follows the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, it is a packed bitmap. Packed bitmaps are referenced by a single pointer. Packed bitmaps require that the **biClrUsed** member must be either zero or the actual size of the color table.

### `biClrImportant`

The number of color indexes that are required for displaying the bitmap. If this value is zero, all colors are required.

## Remarks

The [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure combines the **BITMAPINFOHEADER** structure and a color table to provide a complete definition of the dimensions and colors of a DIB. For more information about DIBs, see [Device-Independent Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/device-independent-bitmaps) and **BITMAPINFO**.

An application should use the information stored in the **biSize** member to locate the color table in a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, as follows:

```cpp
pColor = ((LPSTR)pBitmapInfo + (WORD)(pBitmapInfo->bmiHeader.biSize));
```

If **biCompression** equals **BI_RGB** and **biBitCount** is 8 bpp or less, an array of [RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad) values immediately follows the **BITMAPINFOHEADER** structure. The number of entries in the array is given by **biClrUsed**, or by 2^**biBitCount** if **biClrUsed** is zero. If **biCompression** equals **BI_BITFIELDS**, three **DWORD** color masks (red, green, and blue, in that order) immediately follow the structure instead.

When a color table or color masks follow the **BITMAPINFOHEADER** structure, you can cast or copy the combined memory block to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, where **bmiHeader** is the **BITMAPINFOHEADER** structure and **bmiColors** is the first entry in the color table or the first color mask.

```cpp
typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD          bmiColors[1];
} BITMAPINFO;
```

Because the color table or color masks are appended after the fixed part of the structure, the actual size of the format block is not necessarily equal to **sizeof(BITMAPINFOHEADER)** or **sizeof(BITMAPINFO)**. Calculate the actual size for each instance rather than assuming one of these fixed sizes.

The **BITMAPINFOHEADER** structure is extended to allow a JPEG or PNG image to be passed as the source image to [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

In an uncompressed bitmap, the stride is the number of bytes needed to go from the start of one row of pixels to the start of the next row. For uncompressed RGB formats, the minimum stride is always the image width in bytes, rounded up to the nearest **DWORD**. To calculate the stride and image size, you can use the **GDI_DIBWIDTHBYTES** and/or **GDI_DIBSIZE** macros, or the following formula:

```cpp
stride = ((((biWidth * biBitCount) + 31) & ~31) >> 3);
biSizeImage = abs(biHeight) * stride;
```

The graphics hardware might require a larger stride for the surface that contains the image than this minimum. If there is padding in the image buffer, never dereference a pointer into the memory that has been reserved for the padding. If the image buffer has been allocated in video memory, the padding might not be readable memory.

### Use with DirectShow and video formats

\[The feature associated with this section, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**BITMAPINFOHEADER** is also used to describe DirectShow video formats. The semantics for video data are slightly different than the semantics used elsewhere in this topic. If you are using this structure to describe video data, use the information given here instead.

* For compressed video and YUV formats, **biCompression** is a FOURCC code, specified as a **DWORD** in little-endian order. For example, YUYV video has the FOURCC 'VYUY' or 0x56595559. For more information, see [FOURCC Codes](https://learn.microsoft.com/windows/desktop/DirectShow/fourcc-codes). Note that **BI_JPEG** and **BI_PNG** are not valid video formats.
* For 16-bpp video bitmaps, if **biCompression** equals **BI_RGB**, the format is always RGB 555. If **biCompression** equals **BI_BITFIELDS**, the format is either RGB 555 or RGB 565. Use the subtype GUID in the [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure to determine the specific RGB type.
* For uncompressed RGB video bitmaps, if **biHeight** is positive, the bitmap is a bottom-up DIB with the origin at the lower left corner; if **biHeight** is negative, the bitmap is a top-down DIB with the origin at the upper left corner. For YUV bitmaps, the bitmap is always top-down, regardless of the sign of **biHeight**. Decoders should offer YUV formats with positive **biHeight**, but for backward compatibility they should accept YUV formats with either positive or negative **biHeight**. For compressed formats, **biHeight** must be positive, regardless of image orientation.
* For uncompressed formats, **biBitCount** is the average number of bits per pixel. For compressed formats, **biBitCount** is the implied bit depth of the uncompressed image, after the image has been decoded.
* If **biCompression** is a video FOURCC, the presence of a color table is implied by the video format. You should not assume that a color table exists when the bit depth is 8 bpp or less. However, some legacy components might assume that a color table is present. Therefore, if you are allocating a **BITMAPINFOHEADER** structure, it is recommended to allocate space for a color table when the bit depth is 8 bpp or less, even if the color table is not used.

#### Calculating surface stride for video

For YUV formats, there is no general rule for calculating the minimum stride. You must understand the rules for the particular YUV format. For a description of the most common YUV formats, see [Recommended 8-Bit YUV Formats for Video Rendering](https://learn.microsoft.com/windows/desktop/medfound/recommended-8-bit-yuv-formats-for-video-rendering).

Decoders and video sources should propose formats where biWidth is the width of the image in pixels. If the video renderer requires a surface stride that is larger than the default image stride, it modifies the proposed media type by setting the following values:

* It sets **biWidth** equal to the surface stride in pixels.
* It sets the **rcTarget** member of the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) or [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure equal to the image width, in pixels.

Then the video renderer proposes the modified format by calling [IPin::QueryAccept](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryaccept) on the upstream pin. For more information about this mechanism, see [Dynamic Format Changes](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-format-changes).

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad)

[BITMAPV4HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv4header)

[BITMAPV5HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapv5header)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Device-Independent Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/device-independent-bitmaps)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[VIDEOINFOHEADER Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader)

[VIDEOINFOHEADER2 Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2)

[Working with Video Frames](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-video-frames)