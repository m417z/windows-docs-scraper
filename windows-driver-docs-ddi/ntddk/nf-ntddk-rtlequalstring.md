# RtlEqualString function

## Description

The **RtlEqualString** routine compares two counted strings to determine whether they are equal.

## Parameters

### `String1` [in]

Pointer to the first string.

### `String2` [in]

Pointer to the second string.

### `CaseInSensitive` [in]

If **TRUE**, case should be ignored when doing the comparison.

## Return value

**RtlEqualString** returns **TRUE** if the two strings are equal, otherwise it returns **FALSE**.

## See also

[RtlEqualUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalunicodestring)