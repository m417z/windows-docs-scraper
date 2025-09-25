# FLOATOBJ_GetLong function

## Description

The **FLOATOBJ_GetLong** function calculates and returns the LONG-equivalent value of the specified [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj).

## Parameters

### `unnamedParam1` [in]

Pointer to the FLOATOBJ to be converted to a LONG.

## Return value

**FLOATOBJ_GetFloat** returns the LONG-equivalent value of **pf*.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)