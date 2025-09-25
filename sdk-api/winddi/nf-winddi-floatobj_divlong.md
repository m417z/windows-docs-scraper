# FLOATOBJ_DivLong function

## Description

The **FLOATOBJ_DivLong** function divides the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) by the value of type LONG, and returns with the result in the first parameter.

## Parameters

### `unnamedParam1` [in, out]

Pointer to the FLOATOBJ operand. When the function returns, **pf* will be reset to the quotient of **pf* divided by *l*.

### `unnamedParam2` [in]

Specifies the LONG operand. This value is converted to a FLOATOBJ for the division.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)