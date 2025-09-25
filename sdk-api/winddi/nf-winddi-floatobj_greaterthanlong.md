# FLOATOBJ_GreaterThanLong function

## Description

The **FLOATOBJ_GreaterThanLong** function determines whether the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) is greater than the value of type LONG.

## Parameters

### `unnamedParam1` [in]

Pointer to the FLOATOBJ.

### `unnamedParam2` [in]

Specifies the LONG value. This value is converted to a FLOATOBJ for the comparison.

## Return value

**FLOATOBJ_GreaterThanLong** returns **TRUE** if **pf* is greater than the FLOATOBJ-equivalent of *l*; otherwise it returns **FALSE**.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)