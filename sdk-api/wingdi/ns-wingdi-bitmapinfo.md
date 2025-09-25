# BITMAPINFO structure

## Description

The **BITMAPINFO** structure defines the dimensions and color information for a DIB.

## Members

### `bmiHeader`

A [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure that contains information about the dimensions of color format.

.

### `bmiColors`

The **bmiColors** member contains one of the following:

* An array of [RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad). The elements of the array that make up the color table.
* An array of 16-bit unsigned integers that specifies indexes into the currently realized logical palette. This use of **bmiColors** is allowed for functions that use DIBs. When **bmiColors** elements contain indexes to a realized logical palette, they must also call the following bitmap functions:

  [CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

  [CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

  [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

  The *iUsage* parameter of [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) must be set to DIB_PAL_COLORS.

The number of entries in the array depends on the values of the **biBitCount** and **biClrUsed** members of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

The colors in the **bmiColors** table appear in order of importance. For more information, see the Remarks section.

## Remarks

A DIB consists of two distinct parts: a **BITMAPINFO** structure describing the dimensions and colors of the bitmap, and an array of bytes defining the pixels of the bitmap. The bits in the array are packed together, but each scan line must be padded with zeros to end on a **LONG** data-type boundary. If the height of the bitmap is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If the height is negative, the bitmap is a top-down DIB and its origin is the upper left corner.

A bitmap is packed when the bitmap array immediately follows the **BITMAPINFO** header. Packed bitmaps are referenced by a single pointer. For packed bitmaps, the **biClrUsed** member must be set to an even number when using the DIB_PAL_COLORS mode so that the DIB bitmap array starts on a **DWORD** boundary.

**Note**

The **bmiColors** member should not contain palette indexes if the bitmap is to be stored in a file or transferred to another application.

Unless the application has exclusive use and control of the bitmap, the bitmap color table should contain explicit RGB values.

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad)