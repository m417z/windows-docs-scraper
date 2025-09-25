# GetSystemDefaultLocaleName function

## Description

Retrieves the system default [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names).

**Note** It is recommended that applications call [GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename) in preference over this function. This is due to the user locale generally being more useful and accurate for the user than the system locale.

**Note** The application should call this function in preference to [GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid) if designed to run only on Windows Vista and later.

## Parameters

### `lpLocaleName` [out]

Pointer to a buffer in which this function retrieves the locale name.

### `cchLocaleName` [in]

Size, in characters, of the output buffer indicated by *lpLocaleName*. The maximum possible character length of a locale name (including a terminating null character) is the value of [LOCALE_NAME_MAX_LENGTH](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants). This is the recommended size.

## Return value

Returns a value greater than 0 that indicates the length of the locale name, including the terminating null character, if successful.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.

## Remarks

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

#### Examples

An example showing the use of this function can be found in [NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample).

## See also

[DownlevelLCIDToLocaleName](https://learn.microsoft.com/windows/desktop/Intl/downlevellcidtolocalename)

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename)

[Mapping Locale Data](https://learn.microsoft.com/windows/desktop/Intl/mapping-locale-data)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)