# GetSystemDefaultLCID function

## Description

Returns the [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) for the system locale.

**Note** Any application that runs only on Windows Vista and later should use [GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename) in preference to this function.

## Return value

Returns the locale identifier for the system default locale, identified by [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default).

## Remarks

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## See also

[ConvertDefaultLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-convertdefaultlocale)

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename)

[GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)