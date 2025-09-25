# STROBJ_vEnumStart function

## Description

The **STROBJ_vEnumStart** function defines the form, or type, for data that will be returned from GDI in subsequent calls to [STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum).

## Parameters

### `pstro`

Pointer to the [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure whose data form is to be defined.

## Return value

None

## Remarks

This function also restarts the enumeration of the [GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos) array.

This function should be called by the driver prior to calling **STROBJ_bEnum**.

## See also

[GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum)