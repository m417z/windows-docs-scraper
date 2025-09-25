# RtlPrefixUnicodeString function

## Description

The **RtlPrefixUnicodeString** routine compares two Unicode strings to determine whether one string is a prefix of the other.

## Parameters

### `String1` [in]

Pointer to the first string, which might be a prefix of the buffered Unicode string at *String2*.

### `String2` [in]

Pointer to the second string.

### `CaseInSensitive` [in]

If **TRUE**, case should be ignored when doing the comparison.

## Return value

**RtlPrefixUnicodeString** returns **TRUE** if *String1* is a prefix of *String2*.

## See also

[RtlCompareUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcompareunicodestring)