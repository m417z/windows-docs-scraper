# FsRtlIsDbcsInExpression function

## Description

The **FsRtlIsDbcsInExpression** routine determines whether an ANSI or double-byte character set (DBCS) string matches the specified pattern.

## Parameters

### `Expression` [in]

A pointer to the pattern string. Can contain wildcard characters.

### `Name` [in]

A pointer to the string to be compared against the pattern. Cannot contain wildcard characters.

## Return value

**FsRtlIsDbcsInExpression** returns **TRUE** if the string matches the pattern, **FALSE** otherwise.

## Remarks

The following wildcard characters can be used in the pattern string.

| Wildcard Character | Meaning |
| --- | --- |
| * (asterisk) | Matches zero or more characters. |
| ? (question mark) | Matches a single character. |
| ANSI_DOS_DOT | Matches either a period or zero characters beyond the name string. |
| ANSI_DOS_QM | Matches any single character or, upon encountering a period or end of name string, advances the expression to the end of the set of contiguous ANSI_DOS_QMs. |
| ANSI_DOS_STAR | Matches zero or more characters until encountering and matching the final . in the name. |

Pattern matching is case sensitive. To perform a case-insensitive match, the caller must use a routine such as [RtlUpperString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlupperstring) to convert the pattern and input strings to uppercase before calling **FsRtlIsDbcsInExpression**.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[FsRtlIsNameInExpression](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisnameinexpression)

[RtlUpperString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlupperstring)