# EngCreatePath function

## Description

The **EngCreatePath** function allocates a path for the driver's temporary use.

## Return value

The return value is a pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure if the function is successful. Otherwise, it is null, and an error code is logged.

## Remarks

The driver should delete the path, allocated by **EngCreatePath**, before returning to GDI from its current drawing call.

Functions that create and modify paths are provided to assist devices in clipping paths. A driver can create a path, fill it with lines and pass the path to [PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines) for clipping against the complex region.

A PATHOBJ structure is a locked object, and thus should not be locked for a long time by the driver.

If the driver uses **EngCreatePath** to create a PATHOBJ structure, it should be deleted by using [EngDeletePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletepath) as soon as the driver finishes with it.

The returned PATHOBJ structure is used in calls to [PATHOBJ_bMoveTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bmoveto), [PATHOBJ_bPolyLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bpolylineto), [PATHOBJ_vEnumStartClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstartcliplines), and [PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines)

## See also

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines)