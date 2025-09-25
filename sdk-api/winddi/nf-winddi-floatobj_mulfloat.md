# FLOATOBJ_MulFloat function

## Description

The **FLOATOBJ_MulFloat** function multiplies the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) by the value of type FLOATL, and returns with the result in the first parameter.

## Parameters

### `unnamedParam1` [in, out]

Pointer to the FLOATOBJ operand. When the function returns, **pf* will be reset to the value (**pf*  * *f*).

### `unnamedParam2` [in]

Specifies the FLOATL operand. This value is converted to a FLOATOBJ for the multiplication.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)