# XLATEOBJ_piVector function

## Description

The **XLATEOBJ_piVector** function retrieves a translation vector that the driver can use to translate source indices to destination indices.

## Parameters

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the indexed source object.

## Return value

The return value is a pointer to a vector of translation entries if the function is successful. Otherwise, it is null, and an error code is logged.

## Remarks

This function can be used only if the source palette is an indexed palette.

## See also

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)