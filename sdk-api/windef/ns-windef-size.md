# SIZE structure

## Description

The SIZE structure defines the width and height of a rectangle.

## Members

### `cx`

Specifies the rectangle's width. The units depend on which function uses this structure.

### `cy`

Specifies the rectangle's height. The units depend on which function uses this structure.

## Remarks

The rectangle dimensions stored in this structure can correspond to viewport extents, window extents, text extents, bitmap dimensions, or the aspect-ratio filter for some extended functions.

## See also

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl)