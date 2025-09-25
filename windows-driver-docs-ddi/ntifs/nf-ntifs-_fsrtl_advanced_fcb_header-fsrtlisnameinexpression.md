# FsRtlIsNameInExpression function

## Description

The **FsRtlIsNameInExpression** routine determines whether a Unicode string matches the specified pattern.

## Parameters

### `Expression` [in]

A pointer to the pattern string. Can contain wildcard characters. If *IgnoreCase* is **TRUE**, *Expression* must be uppercase.

### `Name` [in]

A pointer to the string to be compared against the pattern. Cannot contain wildcard characters.

### `IgnoreCase` [in]

Set to **TRUE** for case-insensitive matching, **FALSE** otherwise.

### `UpcaseTable` [in, optional]

Optional pointer to uppercase character table to use for case-insensitive matching. If this value is not supplied, the default system uppercase character table is used.

## Return value

**FsRtlIsNameInExpression** returns **TRUE** if the string matches the pattern, **FALSE** otherwise.

## Remarks

The following wildcard characters can be used in the pattern string.

| Wildcard character | Meaning |
| ------------------ | ------- |
| * (asterisk) | Matches zero or more characters. |
| ? (question mark) | Matches a single character. |
| DOS_DOT | Matches either a period or zero characters beyond the name string. |
| DOS_QM | Matches any single character or, upon encountering a period or end of name string, advances the expression to the end of the set of contiguous DOS_QMs. |
| DOS_STAR | Matches zero or more characters until encountering and matching the final . in the name. |

In low resource conditions, **FsRtlIsNameInExpression** can raise a structured exception with a code of STATUS_NO_MEMORY, which callers should be prepared to handle. For more information, see [Structured Exception Handling](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling).

> [!NOTE]
> If only one of the string parameters has a length of zero, **FsRtlIsNameInExpression** returns **FALSE**. This means that "*" does not match a null string.
>
> If both parameters are null strings, **FsRtlIsNameInExpression** returns **TRUE**.

## See also

[**FsRtlIsDbcsInExpression**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisdbcsinexpression)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)