# RGNDATAHEADER structure

## Description

The **RGNDATAHEADER** structure describes the data returned by the [GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata) function.

## Members

### `dwSize`

The size, in bytes, of the header.

### `iType`

The type of region. This value must be RDH_RECTANGLES.

### `nCount`

The number of rectangles that make up the region.

### `nRgnSize`

The size of the [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) buffer required to receive the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures that make up the region. If the size is not known, this member can be zero.

### `rcBound`

A bounding rectangle for the region in logical units.

## See also

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)

[Region Structures](https://learn.microsoft.com/windows/desktop/gdi/region-structures)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)