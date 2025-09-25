# RGNDATA structure

## Description

The **RGNDATA** structure contains a header and an array of rectangles that compose a region. The rectangles are sorted top to bottom, left to right. They do not overlap.

## Members

### `rdh`

A [RGNDATAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndataheader) structure. The members of this structure specify the type of region (whether it is rectangular or trapezoidal), the number of rectangles that make up the region, the size of the buffer that contains the rectangle structures, and so on.

### `Buffer`

Specifies an arbitrary-size buffer that contains the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures that make up the region.

## See also

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[RGNDATAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndataheader)

[Region Structures](https://learn.microsoft.com/windows/desktop/gdi/region-structures)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)