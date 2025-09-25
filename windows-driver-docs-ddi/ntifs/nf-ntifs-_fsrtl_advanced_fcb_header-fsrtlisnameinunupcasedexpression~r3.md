# FsRtlIsNameInUnUpcasedExpression function

## Description

The **FsRtlIsNameInUnUpcasedExpression** routine determines whether a Unicode string matches the specified pattern. Unlike the [FsRtlIsNameInExpression routine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisnameinexpression), *FsRtlIsNameInUnUpcasedExpression* does not expect the Expression to be in upper case if *IgnoreCase* is TRUE.

## Parameters

### `Expression`

A pointer to the pattern string. Can contain wildcard characters. If IgnoreCase is TRUE, Expression must be lowercase.

### `Name`

A pointer to the string to be compared against the pattern. Cannot contain wildcard characters.

### `IgnoreCase`

Set to **TRUE** for case-insensitive matching, **FALSE** otherwise.

### `UpcaseTable`

Optional pointer to uppercase character table to use for case-insensitive matching. If this value is not supplied, the default system uppercase character table is used.

## Return value

Returns TRUE if the string matches the pattern, FALSE otherwise.

## Remarks

The following wildcard characters can be used in the pattern string:

Wildcard character|Meaning
|-|-|
|* (asterisk)|Matches zero or more characters.|
|? (question mark)|Matches a single character.|
|DOS_DOT|Matches either a period or zero characters beyond the name string.|
|DOS_QM|Matches any single character or, upon encountering a period or end of name string, advances the expression to the end of the set of contiguous DOS_QMs.|
|DOS_STAR|Matches zero or more characters until encountering and matching the final period in the name.|

**Note**

If only one of the string parameters has a length of zero, FsRtlIsNameInUnUpcasedExpression returns FALSE. This means that "*" does not match a null string.
If both parameters are null strings, FsRtlIsNameInUnUpcasedExpression returns TRUE.

## See also

- [FsRtlIsNameInExpression](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisnameinexpression)