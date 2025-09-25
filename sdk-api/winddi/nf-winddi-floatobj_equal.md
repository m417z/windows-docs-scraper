# FLOATOBJ_Equal function

## Description

The **FLOATOBJ_Equal** function determines whether the two [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)s are equal.

## Parameters

### `unnamedParam1` [in]

Pointer to the first FLOATOBJ operand.

### `unnamedParam2` [in]

Pointer to the second FLOATOBJ operand.

## Return value

**FLOATOBJ_Equal**  returns **TRUE** if **pf* and **pf1* are equal; otherwise it returns **FALSE**.

## Remarks

The **FLOATOBJ_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)