# ID2D1Device4::SetMaximumColorGlyphCacheMemory

## Description

Sets the maximum capacity of the color glyph cache.

## Parameters

### `maximumInBytes`

Type: **UINT64**

The maximum capacity of the color glyph cache.

## Remarks

The color glyph cache is used to store color bitmap glyphs and SVG glyphs, enabling faster performance if the same
glyphs are needed again. The capacity determines the amount of memory that D2D may use to store glyphs that the application does not already reference. If the
application references a glyph using [GetColorBitmapGlyphImage](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1devicecontext4-getcolorbitmapglyphimage) or
[GetSvgGlyphImage](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1devicecontext4-getsvgglyphimage), after it has been evicted, this
glyph does not count toward the cache capacity.

## See also

[ID2D1Device4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1device4)