# DWRITE_GLYPH_IMAGE_DATA structure

## Description

Data for a single glyph from GetGlyphImageData.

## Members

### `imageData`

Pointer to the glyph data.

### `imageDataSize`

Size of glyph data in bytes.

### `uniqueDataId`

Unique identifier for the glyph data. Clients may use this to cache a parsed/decompressed version and tell whether a repeated call to the same font returns the same data.

### `pixelsPerEm`

Pixels per em of the returned data. For non-scalable raster data (PNG/TIFF/JPG), this can be larger or smaller than requested from GetGlyphImageData when there isn't an exact match.
For scaling intermediate sizes, use: desired pixels per em * font em size / actual pixels per em.

### `pixelSize`

Size of image when the format is pixel data.

### `horizontalLeftOrigin`

Left origin along the horizontal Roman baseline.

### `horizontalRightOrigin`

Right origin along the horizontal Roman baseline.

### `verticalTopOrigin`

Top origin along the vertical central baseline.

### `verticalBottomOrigin`

Bottom origin along vertical central baseline.