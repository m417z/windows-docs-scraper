# GetUserDefaultLCID function

## Description

Returns the [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) for the user default locale.

**Caution** If the user default locale is a custom locale, an application cannot accurately tag data with the value or exchange it. In this case, the application should use [GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename) in preference to **GetUserDefaultLCID**.

**Note** Applications that are intended to run only on Windows Vista and later should use [GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename).

## Return value

Returns the locale identifier for the user default locale, represented as [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default). If the user default locale is a custom locale, this function always returns [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants), regardless of the custom locale that is selected. For example, whether the user locale is Hawaiian (US), haw-US, or Fijiian (Fiji), fj-FJ, the function returns the same value.

## Remarks

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## See also

[ConvertDefaultLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-convertdefaultlocale)

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid)

[GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)