# GetUserDefaultLangID function

## Description

Returns the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) of the Region Format setting for the current user.

## Return value

Returns the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the current user as set under **Control Panel** > **Clock, Language, and Region** > **Change date, time, or number formats** > **Formats** tab > **Format** dropdown.

For more information on language identifiers, see [Language Identifier Constants and Strings](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings).

## Remarks

The return value is not necessarily the same as that returned by [GetSystemDefaultLangID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlangid), even for a single-user computer.

## See also

[GetSystemDefaultLangID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlangid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)