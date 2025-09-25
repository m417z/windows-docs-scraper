# BITMAPFILEHEADER structure

## Description

The **BITMAPFILEHEADER** structure contains information about the type, size, and layout of a file that contains a DIB.

## Members

### `bfType`

The file type; must be `0x4d42` (the ASCII string "BM").

### `bfSize`

The size, in bytes, of the bitmap file.

### `bfReserved1`

Reserved; must be zero.

### `bfReserved2`

Reserved; must be zero.

### `bfOffBits`

The offset, in bytes, from the beginning of the **BITMAPFILEHEADER** structure to the bitmap bits.

## Remarks

A [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) or [BITMAPCOREINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreinfo) structure immediately follows the **BITMAPFILEHEADER** structure in the DIB file. For more information, see [Bitmap Storage](https://learn.microsoft.com/windows/desktop/gdi/bitmap-storage).

## Examples

For an example, see [Storing an image](https://learn.microsoft.com/windows/win32/gdi/storing-an-image).

## See also

[BITMAPCOREINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreinfo)

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)