# LineDDA function

## Description

The **LineDDA** function determines which pixels should be highlighted for a line defined by the specified starting and ending points.

## Parameters

### `xStart` [in]

Specifies the x-coordinate, in logical units, of the line's starting point.

### `yStart` [in]

Specifies the y-coordinate, in logical units, of the line's starting point.

### `xEnd` [in]

Specifies the x-coordinate, in logical units, of the line's ending point.

### `yEnd` [in]

Specifies the y-coordinate, in logical units, of the line's ending point.

### `lpProc` [in]

Pointer to an application-defined callback function. For more information, see the [LineDDAProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nc-wingdi-lineddaproc) callback function.

### `data` [in]

Pointer to the application-defined data.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **LineDDA** function passes the coordinates for each point along the line, except for the line's ending point, to the application-defined callback function. In addition to passing the coordinates of a point, this function passes any existing application-defined data.

The coordinates passed to the callback function match pixels on a video display only if the default transformations and mapping modes are used.

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[LineDDAProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nc-wingdi-lineddaproc)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)