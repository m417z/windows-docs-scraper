# PATHOBJ_vEnumStart function

## Description

The **PATHOBJ_vEnumStart** function notifies a given PATHOBJ structure that the driver will be calling [PATHOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benum) to enumerate lines and/or curves in the path.

## Parameters

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure whose lines and/or curves are to be enumerated.

## Return value

None

## Remarks

**PATHOBJ_vEnumStart** can be called at any time to restart an enumeration.

## See also

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[PATHOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benum)