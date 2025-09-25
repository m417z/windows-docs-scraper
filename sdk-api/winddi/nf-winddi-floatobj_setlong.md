# FLOATOBJ_SetLong function

## Description

The **FLOATOBJ_SetLong** function assigns the value of type LONG to the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj).

## Parameters

### `unnamedParam1` [out]

Pointer to the FLOATOBJ that will receive the value of *l*.

### `unnamedParam2` [in]

Specifies the LONG value. This value is converted to a FLOATOBJ for the assignment.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)