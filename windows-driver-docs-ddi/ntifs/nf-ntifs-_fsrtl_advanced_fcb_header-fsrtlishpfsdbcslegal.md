# FsRtlIsHpfsDbcsLegal function

## Description

The **FsRtlIsHpfsDbcsLegal** routine determines whether the specified ANSI or double-byte character set (DBCS) string is a legal HPFS file name.

## Parameters

### `DbcsName` [in]

A pointer to the string to be tested.

### `WildCardsPermissible` [in]

Set to TRUE if wildcard characters are to be considered legal, FALSE otherwise.

### `PathNamePermissible` [in]

Set to TRUE if **DbcsName** can be a full pathname containing backslash characters, FALSE if it can only be a file name.

### `LeadingBackslashPermissible` [in]

Set to TRUE if a single leading backslash is permissible in the file or pathname, FALSE otherwise.

## Return value

The **FsRtlIsHpfsDbcsLegal** routine returns TRUE if the string is a legal HPFS file name, FALSE otherwise.

## Remarks

The **FsRtlIsHpfsDbcsLegal** routine determines whether the specified file name conforms to the HPFS-specific rules for legal file names. This routine will check the file name or, if **PathNamePermissible** is specified as TRUE, whether the whole pathname is a legal HPFS name.

HPFS file names must obey the following rules:

* The following characters are illegal in HPFS file names: 0x0000 - 0x001F, " (quotation marks), / (slash), : (colon), < (less-than sign), > (greater-than sign), ? (question mark), | (vertical bar or pipe), * (asterisk)

* An HPFS file name cannot end in a period or a space. For example, the files "foo " and "foo." are illegal, while ".foo", " foo" and "foo.bar.foo" are legal.

* An HPFS file name can contain no more than 255 bytes.

* HPFS file names are case-preserving, but not case insensitive. Lowercase file names are not automatically converted to uppercase. However, case is ignored in file name comparisons.

## See also

[**ANSI_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)