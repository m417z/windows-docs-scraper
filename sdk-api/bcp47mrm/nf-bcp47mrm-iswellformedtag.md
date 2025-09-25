## Description

Determines whether a [BCP-47](https://tools.ietf.org/html/bcp47) language tag is well-formed.

## Parameters

### `pszTag`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A [BCP-47](https://tools.ietf.org/html/bcp47) language tag.

## Return value

`true` if the language tag is well-formed as defined by [BCP-47](https://tools.ietf.org/html/bcp47), except when the language tag can never be valid according to BCP-47. Otherwise it returns `false`.

## Remarks

If this function returns `true`, an application can safely construct a Windows Runtime [Language](https://docs.microsoft.com/uwp/api/Windows.Globalization.Language) by using this tag. If it returns `false`, attempting to construct a Language for the given tag will throw an exception.

## See also

[BCP-47 language tags](https://tools.ietf.org/html/bcp47)