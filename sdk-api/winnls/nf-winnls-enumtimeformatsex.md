# EnumTimeFormatsEx function

## Description

Enumerates the time formats that are available for a locale specified by name.

**Note** The application should call this function in preference to [EnumTimeFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumtimeformatsa) if designed to run only on Windows Vista and later.

**Note** This function can enumerate data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpTimeFmtEnumProcEx` [in]

Pointer to an application-defined callback function. For more information, see [EnumTimeFormatsProcEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317833(v=vs.85)).

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

The time format. Set to 0 to use the current user's long time format, or TIME_NOSECONDS (starting with Windows 7) to use the short time format.

### `lParam` [in]

An application-provided parameter to be passed to the callback function. This is especially useful for multi-threaded applications.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates the time formats by passing time format string pointers, one at a time, to the specified application-defined callback function, along with an application-defined constant that is useful for multi-threaded applications. The first value in the enumeration is always the user default (override) value. The function continues enumeration until the last time format is found or the callback function returns **FALSE**.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[EnumTimeFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumtimeformatsa)

[EnumTimeFormatsProcEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317833(v=vs.85))

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)