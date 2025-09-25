# FsRtlAreNamesEqual function

## Description

The **FsRtlAreNamesEqual** routine determines whether two Unicode strings are equal.

## Parameters

### `ConstantNameA` [in]

A pointer to first string. Cannot contain wildcard characters.

### `ConstantNameB` [in]

A pointer to second string. Cannot contain wildcard characters.

### `IgnoreCase` [in]

Set to **TRUE** for case-insensitive matching, **FALSE** otherwise.

### `UpcaseTable` [in, optional]

Optional pointer to uppercase character table to use for case-insensitive matching. If this value is not supplied, the default system uppercase character table is used.

## Return value

**FsRtlAreNamesEqual** returns **TRUE** if the two Unicode strings match, **FALSE** otherwise.

## Remarks

The table pointed to by *UpcaseTable* is an array of uppercase Unicode characters, indexed by the Unicode character to be converted to uppercase. The array must contain entries for all characters that are legal in file names.

Case-insensitive matching is performed by converting both strings to uppercase before they are compared. Thus the value of *UpcaseTable*, if supplied, is used only if *IgnoreCase* is **TRUE**.

If a pool allocation failure occurs, **FsRtlAreNamesEqual** raises a STATUS_NO_MEMORY exception.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlEqualUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)