# FsRtlDoesNameContainWildCards function

## Description

The **FsRtlDoesNameContainWildCards** routine determines whether a Unicode string contains wildcard characters.

## Parameters

### `Name` [in]

A pointer to the string to be checked.

## Return value

**FsRtlDoesNameContainWildCards** returns **TRUE** if one or more wildcard characters were found, **FALSE** otherwise.

## Remarks

The following are wildcard characters: *, ?, ANSI_DOS_STAR, ANSI_DOS_DOT, and ANSI_DOS_QM.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)