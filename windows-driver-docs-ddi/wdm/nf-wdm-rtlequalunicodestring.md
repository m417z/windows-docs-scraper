# RtlEqualUnicodeString function

## Description

The **RtlEqualUnicodeString** routine compares two Unicode strings to determine whether they are equal.

## Parameters

### `String1` [in]

Pointer to the first Unicode string.

### `String2` [in]

Pointer to the second Unicode string.

### `CaseInSensitive` [in]

If **TRUE**, case should be ignored when doing the comparison.

## Return value

**RtlEqualUnicodeString** returns **TRUE** if the two Unicode strings are equal; otherwise, it returns **FALSE**.

## See also

[RtlEqualString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlequalstring)