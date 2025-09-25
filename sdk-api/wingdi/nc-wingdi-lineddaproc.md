# LINEDDAPROC callback function

## Description

The **LineDDAProc** function is an application-defined callback function used with the [LineDDA](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-linedda) function. It is used to process coordinates. The **LINEDDAPROC** type defines a pointer to this callback function. **LineDDAProc** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

#### - X [in]

Specifies the x-coordinate, in logical units, of the current point.

#### - Y [in]

Specifies the y-coordinate, in logical units, of the current point.

#### - lpData [in]

Pointer to the application-defined data.

## Remarks

An application registers a **LineDDAProc** function by passing its address to the [LineDDA](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-linedda) function.

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[LineDDA](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-linedda)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)