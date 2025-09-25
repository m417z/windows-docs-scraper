# MAGTRANSFORM structure

## Description

Describes a transformation matrix that a magnifier control uses to magnify screen content.

## Members

### `v`

Type: **float[3]**

The transformation matrix.

## Remarks

The transformation matrix is

 (*n*, 0.0, 0.0)

 (0.0, *n*, 0.0)

 (0.0, 0.0, 1.0)

where *n* is the magnification factor.

## See also

[MagGetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetwindowtransform)

[MagSetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowtransform)

**Reference**