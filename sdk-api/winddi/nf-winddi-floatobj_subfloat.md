# FLOATOBJ_SubFloat function

## Description

The **FLOATOBJ_SubFloat** function subtracts the value of type FLOATL from the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj), and returns with the result in the first parameter.

## Parameters

### `unnamedParam1` [in]

Pointer to the FLOATOBJ operand. When the function returns, **pf* will be reset to the value (**pf* - *f*).

### `unnamedParam2` [in]

Specifies the FLOATL operand. This value is converted to a FLOATOBJ for the subtraction.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)