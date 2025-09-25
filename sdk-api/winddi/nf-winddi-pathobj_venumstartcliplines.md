# PATHOBJ_vEnumStartClipLines function

## Description

The **PATHOBJ_vEnumStartClipLines** function allows the driver to request lines to be clipped against a specified clip region.

## Parameters

### `ppo`

Pointer to the [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that describes the specified clipping object.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that describes the clip region.

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that GDI queries to retrieve information about styling steps.

### `pla`

Pointer to a [LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs) structure that GDI queries to retrieve line width and styling information.

## Return value

None

## Remarks

This function is useful when the clip region is more complex than a simple rectangle.

**PATHOBJ_vEnumStartClipLines** performs calculations for cosmetic wide lines. If the LINEATTRS structure needs a cosmetic wide line, the enumeration walks the given path as many times as needed to complete the widened figure.

This function should not be called for geometric wide lines or paths that contain Bezier curves.

Once begun, this enumeration process should not be restarted.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)