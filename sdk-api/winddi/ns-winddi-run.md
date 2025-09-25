# RUN structure

## Description

The RUN structure is used to describe a linear set of pixels that is not clipped by the [CLIPLINE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipline) structure.

## Members

### `iStart`

Specifies the starting point for a field of pixels to be drawn. The first pixel of the unclipped line is pixel 0.

### `iStop`

Specifies the stopping point for a field of pixels to be drawn.

## Remarks

If the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) is complex, a single line segment can be broken into many RUNs. The same segment is returned as many times as necessary to list all of its RUNs.

## See also

[PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines)