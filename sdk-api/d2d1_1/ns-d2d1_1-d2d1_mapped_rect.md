# D2D1_MAPPED_RECT structure

## Description

 Describes mapped memory from the [ID2D1Bitmap1::Map](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-map) API.

## Members

### `pitch`

The size in bytes of an individual scanline in the bitmap.

### `bits`

The data inside the bitmap.

## Remarks

The mapped rectangle is used to map a rectangle into the caller's address space.

## See also

[ID2D1Bitmap1::Map](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-map)