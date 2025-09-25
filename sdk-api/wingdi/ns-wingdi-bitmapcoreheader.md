# BITMAPCOREHEADER structure

## Description

The **BITMAPCOREHEADER** structure contains information about the dimensions and color format of a DIB.

## Members

### `bcSize`

The number of bytes required by the structure.

### `bcWidth`

The width of the bitmap, in pixels.

### `bcHeight`

The height of the bitmap, in pixels.

### `bcPlanes`

The number of planes for the target device. This value must be 1.

### `bcBitCount`

The number of bits-per-pixel. This value must be 1, 4, 8, or 24.

## Remarks

The [BITMAPCOREINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreinfo) structure combines the **BITMAPCOREHEADER** structure and a color table to provide a complete definition of the dimensions and colors of a DIB. For more information about specifying a DIB, see **BITMAPCOREINFO**.

An application should use the information stored in the **bcSize** member to locate the color table in a [BITMAPCOREINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreinfo) structure, using a method such as the following:

```cpp

pColor = ((LPBYTE) pBitmapCoreInfo +
        (WORD) (pBitmapCoreInfo -> bcSize))

```

## See also

[BITMAPCOREINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapcoreinfo)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)