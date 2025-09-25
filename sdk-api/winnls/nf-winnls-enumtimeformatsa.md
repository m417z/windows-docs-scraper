# EnumTimeFormatsA function

## Description

Enumerates the time formats that are available for a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [EnumTimeFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumtimeformatsex) function to **EnumTimeFormats** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that runs only on Windows Vista and later should use [EnumTimeFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumtimeformatsex).

## Parameters

### `lpTimeFmtEnumProc` [in]

Pointer to an application-defined callback function. For more information, see [EnumTimeFormatsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317832(v=vs.85)).

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which to retrieve time format information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

The time format. This parameter can specify a combination of any of the following values.

| Flag | Meaning |
| --- | --- |
| **0** | Use the current user's long time format. |
| **TIME_NOSECONDS** | **Windows 7 and later**: Use the current user's short time format.<br><br>**Note** This value will not work with the ANSI version of this function, **EnumTimeFormatsA**. |
| **LOCAL_USE_CP_ACP** | Specified with the ANSI version of this function, **EnumTimeFormatsA** (not recommended), to use the system default Windows ANSI code page (ACP) instead of the locale code page. |

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

The function enumerates the time formats by passing a pointer to a buffer containing a time format to an application-defined callback function. The first value in the enumeration is always the user default (override) value. The function continues enumeration until the last time format is found or the callback function returns **FALSE**.

This function can enumerate data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

When the ANSI version of this function is used with a Unicode-only locale identifier, the call can succeed because the system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark ("?").
Note that any new values for *dwFlags* introduced in the future will not work with the ANSI version.

> [!NOTE]
> The winnls.h header defines EnumTimeFormats as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumTimeFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumtimeformatsex)

[EnumTimeFormatsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317832(v=vs.85))

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)