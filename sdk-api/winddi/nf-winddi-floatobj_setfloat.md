# FLOATOBJ_SetFloat function

## Description

The **FLOATOBJ_SetFloat** function assigns the value of type FLOATL to the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj).

## Parameters

### `unnamedParam1` [out]

Pointer to the FLOATOBJ that will receive the value of *f*.

### `unnamedParam2` [in]

Specifies the FLOATL value. This value is converted to a FLOATOBJ for the assignment.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)