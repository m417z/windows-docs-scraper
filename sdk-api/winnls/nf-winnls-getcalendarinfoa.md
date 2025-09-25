# GetCalendarInfoA function

## Description

Retrieves information about a calendar for a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [GetCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoex) function to **GetCalendarInfo** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that runs only on Windows Vista and later should use [GetCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which to retrieve calendar information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `Calendar` [in]

[Calendar identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers).

### `CalType` [in]

Type of information to retrieve. For more information, see [Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information).

**Note** **GetCalendarInfo** returns only one string if this parameter specifies CAL_IYEAROFFSETRANGE or CAL_SERASTRING. In both cases the current era is returned.

CAL_USE_CP_ACP is relevant only for the ANSI version of this function.

For CAL_NOUSEROVERRIDE, the function ignores any value set by [SetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setcalendarinfoa) and uses the database settings for the current system default locale. This type is relevant only in the combination CAL_NOUSEROVERRIDE | CAL_ITWODIGITYEARMAX. CAL_ITWODIGITYEARMAX is the only value that can be set by **SetCalendarInfo**.

### `lpCalData` [out, optional]

Pointer to a buffer in which this function retrieves the requested data as a string. If CAL_RETURN_NUMBER is specified in *CalType*, this parameter must retrieve **NULL**.

### `cchData` [in]

Size, in characters, of the *lpCalData* buffer. The application can set this parameter to 0 to return the required size for the calendar data buffer. In this case, the *lpCalData* parameter is not used. If CAL_RETURN_NUMBER is specified for *CalType*, the value of *cchData* must be 0.

### `lpValue` [out, optional]

Pointer to a variable that receives the requested data as a number. If CAL_RETURN_NUMBER is specified in *CalType*, then *lpValue* must not be **NULL**. If CAL_RETURN_NUMBER is not specified in *CalType*, then *lpValue* must be **NULL**.

## Return value

Returns the number of characters retrieved in the *lpCalData* buffer, with *cchData* set to a nonzero value, if successful. If the function succeeds, *cchData* is set to 0, and CAL_RETURN_NUMBER is not specified, the return value is the size of the buffer required to hold the calendar information. If the function succeeds, *cchData* is set 0, and CAL_RETURN_NUMBER is specified, the return value is the size of the value retrieved in *lpValue*, that is, 2 for the Unicode version of the function or 4 for the ANSI version.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

> [!NOTE]
> The winnls.h header defines GetCalendarInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information)

[GetCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setcalendarinfoa)