# FLOATOBJ_AddLong function

## Description

The **FLOATOBJ_AddLong** function adds the value of type LONG to the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj), and returns with the result in the first parameter.

## Parameters

### `unnamedParam1` [in, out]

Pointer to the FLOATOBJ operand. When the function returns, **pf* will be reset to the sum of **pf* and **f*.

### `unnamedParam2` [in]

Specifies the LONG operand. This value is converted to a FLOATOBJ for the summation.

## Remarks

The **FLOATOBJ_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)