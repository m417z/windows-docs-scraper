# PATHOBJ_bPolyLineTo function

## Description

The **PATHOBJ_bPolyLineTo** function draws lines from the current position in a path through the specified points.

## Parameters

### `ppo`

Pointer to the [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure created by the driver.

### `pptfx`

Pointer to an array of POINTFIX structures that define control points. The first line is drawn from the current position to the first point in this array; lines are then drawn to each subsequent point in the array. For a description of this data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `cptfx`

Specifies the count of points in *pptfx*. This is also the number of lines that will be added to the path.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

**PATHOBJ_bPolyLineTo** should only be called with PATHOBJ structures created by [EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath).

## See also

[EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[PATHOBJ_bPolyBezierTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bpolybezierto)