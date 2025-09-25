# FLOATOBJ_LessThan function

## Description

The **FLOATOBJ_LessThan** function determines whether the first [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) is less than the second FLOATOBJ.

## Parameters

### `unnamedParam1` [in]

Pointer to the first FLOATOBJ.

### `unnamedParam2` [in]

Pointer to the second FLOATOBJ.

## Return value

**FLOATOBJ_LessThan** returns **TRUE** if **pf* is less than **pf1*; otherwise it returns **FALSE**.

## Remarks

The FLOATOBJ**_***Xxx* services allow graphics drivers to emulate floating-point arithmetic. An NT-based operating system does not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)