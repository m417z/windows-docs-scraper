# ConvertDefaultLocale function

## Description

Converts a default locale value to an actual [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

**Note** This function is only provided for converting partial locale identifiers. Your applications should use locale names instead of identifiers. The [LCIDToLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcidtolocalename) function can be used to convert a locale identifier to a valid locale name. Your application can also use [GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename) to retrieve the current user locale name; [GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename) to retrieve the current system locale name; and [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) with [LOCALE_SNAME](https://learn.microsoft.com/windows/desktop/Intl/locale-sname) to retrieve the locale name for any input locale, including the default constants.

## Parameters

### `Locale` [in]

Default locale identifier value to convert. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

## Return value

Returns the appropriate locale identifier if successful.

This function returns the value of the *Locale* parameter if it does not succeed. The function fails when the *Locale* value is not one of the default values listed above.

## Remarks

A call to **ConvertDefaultLocale** specifying LOCALE_SYSTEM_DEFAULT is equivalent to a call to [GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid). A call to **ConvertDefaultLocale** specifying LOCALE_USER_DEFAULT is equivalent to a call to [GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid).

## See also

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid)

[GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename)

[GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid)

[GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename)

[LCIDToLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcidtolocalename)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)