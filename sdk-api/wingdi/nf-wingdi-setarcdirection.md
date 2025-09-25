# SetArcDirection function

## Description

The **SetArcDirection** sets the drawing direction to be used for arc and rectangle functions.

## Parameters

### `hdc` [in]

A handle to the device context.

### `dir` [in]

The new arc direction. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AD_COUNTERCLOCKWISE** | Figures drawn counterclockwise. |
| **AD_CLOCKWISE** | Figures drawn clockwise. |

## Return value

If the function succeeds, the return value specifies the old arc direction.

If the function fails, the return value is zero.

## Remarks

The default direction is counterclockwise.

The **SetArcDirection** function specifies the direction in which the following functions draw:

* [Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)
* [ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)
* [Chord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-chord)
* [Ellipse](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ellipse)
* [Pie](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-pie)
* [Rectangle](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rectangle)
* [RoundRect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-roundrect)

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)