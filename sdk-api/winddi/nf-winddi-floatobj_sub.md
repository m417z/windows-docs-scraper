# FLOATOBJ_Sub function

## Description

The **FLOATOBJ_Sub** function subtracts the second [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) from the first, and returns with the result in the first parameter.

## Parameters

### `unnamedParam1` [in, out]

Pointer to the first FLOATOBJ operand. When the function returns, **pf* will be reset to the value (**pf* - **pf1*).

### `unnamedParam2` [in]

Pointer to the second FLOATOBJ operand.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)