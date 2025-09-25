# D2D1_LINE_JOIN enumeration

## Description

Describes the shape that joins two lines or segments.

## Constants

### `D2D1_LINE_JOIN_MITER:0`

Regular angular vertices.

### `D2D1_LINE_JOIN_BEVEL:1`

Beveled vertices.

### `D2D1_LINE_JOIN_ROUND:2`

Rounded vertices.

### `D2D1_LINE_JOIN_MITER_OR_BEVEL:3`

Regular angular vertices unless the join would extend beyond the miter limit; otherwise, beveled vertices.

### `D2D1_LINE_JOIN_FORCE_DWORD:0xffffffff`

## Remarks

A miter limit affects how sharp miter joins are allowed to be.
If the line join style is **D2D1_LINE_JOIN_MITER_OR_BEVEL**, then the join will be mitered with regular angular vertices if it doesn't extend
beyond the miter limit; otherwise, the line join will be beveled.

The following illustration shows different line join settings for the same stroked path geometry.

![Illustration of line join settings](https://learn.microsoft.com/windows/win32/api/d2d1/images/StrokeStyle_Join.png)