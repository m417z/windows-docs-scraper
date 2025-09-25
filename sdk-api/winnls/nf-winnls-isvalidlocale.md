# IsValidLocale function

## Description

[**IsValidLocale** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IsValidLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isvalidlocalename) to determine the validity of a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales).]

Determines if the specified locale is installed or supported on the operating system. For more information, see [Locales and Languages](https://learn.microsoft.com/windows/desktop/Intl/locales-and-languages).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) of the locale to validate. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
  **Windows Server 2003, Windows XP and Windows 2000:** This locale identifier is not supported.
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
  **Windows Server 2003, Windows XP and Windows 2000:** This locale identifier is not supported.
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
  **Windows Server 2003, Windows XP and Windows 2000:** This locale identifier is not supported.
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

Flag specifying the validity test to apply to the locale identifier. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **LCID_INSTALLED** | Determine if the locale identifier is both supported and installed. |
| **LCID_SUPPORTED** | Determine if the locale identifier is supported. |
| 0x39 | Do not use. Instead, use LCID_INSTALLED.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003, Windows XP and Windows 2000:** Setting *dwFlags* to 0x39 is a special case that can behave like LCID_INSTALLED for some locales on some versions of Windows. |

## Return value

Returns a nonzero value if the locale identifier passes the specified validity test. The function returns 0 if it does not succeed.

## Remarks

If the LCID_INSTALLED flag is specified and this function returns a nonzero value, the locale identifier is both supported and installed on the operating system. Having an identifier installed implies that the full level of language support is available for the indicated locale. Full support includes code page translation tables, keyboard layouts, fonts, and sorting and locale data.

If LCID_SUPPORTED is specified and this function returns 0, the locale identifier is supported in the release, but not necessarily installed on the operating system.

This function can handle data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## See also

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[IsValidLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isvalidlocalename)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)