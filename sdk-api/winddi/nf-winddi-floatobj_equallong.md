# FLOATOBJ_EqualLong function

## Description

The **FLOATOBJ_EqualLong** function determines whether the [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) and the value of type LONG are equal.

## Parameters

### `unnamedParam1` [in]

Pointer to the FLOATOBJ.

### `unnamedParam2` [in]

Specifies the LONG value. This value is converted to a FLOATOBJ for the comparison.

## Return value

**FLOATOBJ_EqualLong**  returns **TRUE** if **pf* and the FLOATOBJ-equivalent value of *l* are equal; otherwise it returns **FALSE**.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)