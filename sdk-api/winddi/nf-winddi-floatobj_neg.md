# FLOATOBJ_Neg function

## Description

The **FLOATOBJ_Neg** function negates the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj).

## Parameters

### `unnamedParam1` [in, out]

Pointer to the FLOATOBJ to be negated. When the function returns, **pf* will contain the negated value.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)