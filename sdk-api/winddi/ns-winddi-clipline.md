# CLIPLINE structure

## Description

The CLIPLINE structure gives the driver access to a portion of a line between two [clip regions](https://learn.microsoft.com/windows-hardware/drivers/) used for drawing.

## Members

### `ptfxA`

Specifies a POINTFIX structure that contains the starting point of the line.

### `ptfxB`

Specifies a POINTFIX structure that contains the end point of the line.

### `lStyleState`

Is a pair of 16-bit values supplied by GDI whenever the driver calls [PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines). These two values are packed into a LONG and specify the style offset back to the first pixel of the line segment. This is the first pixel that would be rendered if the line were not clipped. This value allows the styling for the remainder of the line to be computed. Refer to [Styled Cosmetic Lines](https://learn.microsoft.com/windows-hardware/drivers/display/styled-cosmetic-lines) for additional information.

### `c`

Specifies the number of RUN structures in the **arun** array.

### `arun`

Is an array of [RUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-run) structures. The RUN structures describe the start and stop portions of the clip line.

## Remarks

The CLIPLINE structure is used by [PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines). The CLIPLINE structure contains the original, unclipped control points of the line segment.

See [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types) for a description of the POINTFIX structure.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo)

[RUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-run)