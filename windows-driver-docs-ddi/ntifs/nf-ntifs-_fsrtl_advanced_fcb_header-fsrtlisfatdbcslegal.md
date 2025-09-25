# FsRtlIsFatDbcsLegal function

## Description

The **FsRtlIsFatDbcsLegal** routine determines whether the specified ANSI or double-byte character set (DBCS) string is a legal FAT file name.

## Parameters

### `DbcsName` [in]

A pointer to the string to be tested.

### `WildCardsPermissible` [in]

Set to **TRUE** if wildcard characters are to be considered legal, **FALSE** otherwise.

### `PathNamePermissible` [in]

Set to **TRUE** if *DbcsName* can be a full pathname containing backslash characters, **FALSE** if it can only be file name.

### `LeadingBackslashPermissible` [in]

Set to **TRUE** if a single leading backslash is permissible in the file or pathname, **FALSE** otherwise.

## Return value

The **FsRtlIsFatDbcsLegal** routine returns **TRUE** if the string is a legal FAT file name, **FALSE** otherwise.

## Remarks

The **FsRtlIsFatDbcsLegal** routine determines whether the specified file name conforms to the FAT-specific rules for legal file names. This routine will check the file name or, if *PathNamePermissible* is specified as **TRUE**, whether the whole pathname is a legal FAT name.

FAT file names must obey the following rules:

* The following characters are illegal in FAT file names: `0x00-0x1F`, `"` (straight quotation marks), `/` (slash), `:` (colon), `|` (vertical bar or pipe), `+` (plus), `,` (comma), `;` (semicolon), `=` (equal sign), `[ ]` (brackets)
* A FAT file name is either of the form `N.E` or just `N`, where `N` is a string of one to eight bytes and `E` is a string of one to three bytes conformant to rule one. In addition, neither `N` nor `E` may contain a `.` (period) or end with a space character. For example, the files `.foo`, `foo.`, and `foo .b` are illegal, while `foo. b` and ` bar` are legal.
* FAT file names are case insensitive. Lowercase names are automatically converted to uppercase.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)