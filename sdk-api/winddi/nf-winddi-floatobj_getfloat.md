# FLOATOBJ_GetFloat function

## Description

The **FLOATOBJ_GetFloat** function calculates and returns the FLOAT-equivalent value of the specified [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj).

## Parameters

### `unnamedParam1` [in]

Pointer to the FLOATOBJ to be converted to a FLOAT.

## Return value

**FLOATOBJ_GetFloat** returns the FLOAT-equivalent value of **pf*. The return value is of type LONG, and needs to be typecast to a FLOAT by the driver.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)