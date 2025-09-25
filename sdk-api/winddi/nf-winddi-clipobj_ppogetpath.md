# CLIPOBJ_ppoGetPath function

## Description

The **CLIPOBJ_ppoGetPath** function creates a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that contains the outline of the specified clip region.

## Parameters

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the specified clip region.

## Return value

The return value is a pointer to a PATHOBJ structure if the function is successful. Otherwise, it is **NULL**, and an error code is logged.

## Remarks

The returned PATHOBJ structure should be deleted using [EngDeletePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletepath) when the driver no longer needs it.

A driver for a device that can download a clipping path might prefer this function for defining complex regions.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[EngDeletePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletepath)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)