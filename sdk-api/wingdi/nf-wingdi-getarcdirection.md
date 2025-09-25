# GetArcDirection function

## Description

The **GetArcDirection** function retrieves the current arc direction for the specified device context. Arc and rectangle functions use the arc direction.

## Parameters

### `hdc` [in]

Handle to the device context.

## Return value

The return value specifies the current arc direction; it can be any one of the following values:

| Value | Meaning |
| --- | --- |
| AD_COUNTERCLOCKWISE | Arcs and rectangles are drawn counterclockwise. |
| AD_CLOCKWISE | Arcs and rectangles are drawn clockwise. |

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[SetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setarcdirection)