# D2D1_CAP_STYLE enumeration

## Description

Describes the shape at the end of a line or segment.

## Constants

### `D2D1_CAP_STYLE_FLAT:0`

A cap that does not extend past the last point of the line. Comparable to cap used for objects other than lines.

### `D2D1_CAP_STYLE_SQUARE:1`

Half of a square that has a length equal to the line thickness.

### `D2D1_CAP_STYLE_ROUND:2`

A semicircle that has a diameter equal to the line thickness.

### `D2D1_CAP_STYLE_TRIANGLE:3`

An isosceles right triangle whose hypotenuse is equal in length to the thickness of the line.

### `D2D1_CAP_STYLE_FORCE_DWORD:0xffffffff`

## Remarks

The following illustration shows the available cap styles for lines or segments. The red portion of the line shows the extra area added by the line cap setting.

![Illustration of four cap styles](https://learn.microsoft.com/windows/win32/api/d2d1/images/linecaps.png)