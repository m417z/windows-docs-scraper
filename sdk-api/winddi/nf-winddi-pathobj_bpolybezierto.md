# PATHOBJ_bPolyBezierTo function

## Description

The **PATHOBJ_bPolyBezierTo** function draws Bezier curves on a path.

## Parameters

### `ppo`

Pointer to the [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure created by the driver.

### `pptfx`

Pointer to the array of POINTFIX structures that define control points. Each set of three control points, along with the preceding control point, or current position, determines a Bezier curve. For a description of this data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `cptfx`

Specifies the count of points in *pptfx*. Must be a multiple of three.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

**PATHOBJ_bPolyBezierTo** must be called only with a PATHOBJ structure created by [EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath).

## See also

[EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[PATHOBJ_bPolyLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bpolylineto)