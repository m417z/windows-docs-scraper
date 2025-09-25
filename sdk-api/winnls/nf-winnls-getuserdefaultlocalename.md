# GetUserDefaultLocaleName function

## Description

Retrieves the user default [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names).

**Note** The application should call this function in preference to [GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid) if designed to run only on Windows Vista and later.

## Parameters

### `lpLocaleName` [out]

Pointer to a buffer in which this function retrieves the locale name.

### `cchLocaleName` [in]

Size, in characters, of the buffer indicated by *lpLocaleName*. The maximum possible length of a locale name, including a terminating null character, is [LOCALE_NAME_MAX_LENGTH](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants). This is the recommended size to supply in this parameter.

## Return value

Returns the size of the buffer containing the locale name, including the terminating null character, if successful.

**Note** On single-user systems, the return value is the same as that returned by [GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename).

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.

## Remarks

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## See also

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename)

[GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)