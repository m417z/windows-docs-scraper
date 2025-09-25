# PATHOBJ_bEnum function

## Description

The **PATHOBJ_bEnum** function retrieves the next PATHDATA record from a specified path and enumerates the curves in the path.

## Parameters

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure whose curves and/or lines are to be enumerated.

### `ppd`

Pointer to a [PATHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathdata) structure that is to be filled.

## Return value

The return value is **TRUE** if the specified path contains more PATHDATA records, indicating that this service should be called again. Otherwise, if the output is the last PATHDATA record in the path, the return value is **FALSE**.

## Remarks

**PATHOBJ_bEnum** can be called only after a call to [PATHOBJ_vEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstart) has been made.

A PATHDATA structure describes all or part of a subpath (a connected part of a path). For example, a **MoveTo** call by the application within a path begins a new subpath.

## See also

[PATHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathdata)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[PATHOBJ_vEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstart)

[PATHOBJ_vEnumStartClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstartcliplines)