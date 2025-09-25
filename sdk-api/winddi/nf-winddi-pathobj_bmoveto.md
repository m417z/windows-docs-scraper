# PATHOBJ_bMoveTo function

## Description

The **PATHOBJ_bMoveTo** function sets the current position in a given path.

## Parameters

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure created by the driver.

### `ptfx`

Pointer to a POINTFIX structure that specifies the new position. For a description of this data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

This function should only be called with PATHOBJ structures created by [EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath).

## See also

[EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)