# RtlCompareUnicodeString function

## Description

The **RtlCompareUnicodeString** routine compares two Unicode strings.

## Parameters

### `String1` [in]

Pointer to the first string.

### `String2` [in]

Pointer to the second string.

### `CaseInSensitive` [in]

If **TRUE**, case should be ignored when doing the comparison.

## Return value

**RtlCompareUnicodeString** returns a signed value that gives the results of the comparison:

| Return code | Description |
| --- | --- |
| **Zero** | *String1* equals *String2*. |
| **< Zero** | *String1* is less than *String2*. |
| **> Zero** | *String1* is greater than *String2*. |

## See also

[RtlCompareString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlcomparestring)

[RtlEqualString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlequalstring)