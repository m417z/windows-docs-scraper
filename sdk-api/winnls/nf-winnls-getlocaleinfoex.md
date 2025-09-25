# GetLocaleInfoEx function

## Description

Retrieves information about a locale specified by name.

**Note** The application should call this function in preference to [GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa) if designed to run only on Windows Vista and later.

**Note** This function can retrieve data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `LCType` [in]

The locale information to retrieve. For possible values, see the "Constants Used in the LCType Parameter of GetLocaleInfo, GetLocaleInfoEx, and SetLocaleInfo" section in [Locale Information Constants](https://learn.microsoft.com/windows/desktop/Intl/locale-information-constants). Note that only one piece of locale information can be specified per call.

The application can use the binary OR operator to combine [LOCALE_RETURN_NUMBER](https://learn.microsoft.com/windows/desktop/Intl/locale-return-constants) with any other allowed constant. In this case, the function retrieves the value as a number instead of a string. The buffer that receives the value must be at least the length of a DWORD value, which is 2.

**Caution** It is also possible to combine [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) with any other constant. However, use of this constant is strongly discouraged. (Even without using the current user override, the data can differ from computer to computer, and custom locales can change the data. For example, even month or day names are subject to spelling reforms.)

If *LCType* is set to [LOCALE_IOPTIONALCALENDAR](https://learn.microsoft.com/windows/desktop/Intl/locale-ioptionalcalendar), the function retrieves only the first alternate calendar.

**Note** To get all alternate calendars, the application should use [EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa).

Starting with Windows Vista, your applications should not use [LOCALE_ILANGUAGE](https://learn.microsoft.com/windows/desktop/Intl/locale-ilanguage) in the *LCType* parameter to avoid failure or retrieval of unexpected data. Instead, it is recommended for your applications to call **GetLocaleInfoEx**.

### `lpLCData` [out, optional]

Pointer to a buffer in which this function retrieves the requested locale information. This pointer is not used if *cchData* is set to 0.

### `cchData` [in]

Size, in characters, of the data buffer indicated by *lpLCData*. Alternatively, the application can set this parameter to 0. In this case, the function does not use the *lpLCData* parameter and returns the required buffer size, including the terminating null character.

## Return value

Returns the number of characters retrieved in the locale data buffer if successful and *cchData* is a nonzero value. If the function succeeds, *cchData* is nonzero, and [LOCALE_RETURN_NUMBER](https://learn.microsoft.com/windows/desktop/Intl/locale-return-constants) is specified, the return value is the size of the integer retrieved in the data buffer, that is, 2. If the function succeeds and the value of *cchData* is 0, the return value is the required size, in characters including a null character, for the locale data buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function normally retrieves information in text format. If the information is a numeric value and the value of *LCType* is [LOCALE_ILANGUAGE](https://learn.microsoft.com/windows/desktop/Intl/locale-ilanguage) or [LOCALE_IDEFAULTLANGUAGE](https://learn.microsoft.com/windows/desktop/Intl/locale-idefault-constants), this function retrieves strings containing hexadecimal numbers. Otherwise, the retrieved text for numeric information is a decimal number.

There are two exceptions to this rule. First, the application can retrieve numeric values as integers by specifying [LOCALE_RETURN_NUMBER](https://learn.microsoft.com/windows/desktop/Intl/locale-return-constants) in the *LCType* parameter. The second exception is that [LOCALE_FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/Intl/locale-fontsignature) behaves differently from all other locale information constants. The application must provide a data buffer of at least sizeof(LOCALESIGNATURE) bytes. On successful return from the function, the buffer is filled in as a [LOCALESIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-localesignature) structure.

**Note** Even when the *LCType* parameter is specified as LOCALE_FONTSIGNATURE, *cchData* and the function return are still character counts. When an application calls **GetLocaleInfoEx** with *LCType* specified as LOCALE_FONTSIGNATURE, *cchData* can be safely specified as sizeof(LOCALESIGNATURE) / sizeof(WCHAR).

The following examples deal correctly with the buffer size for non-text values:

```cpp
int   ret;
CALID calid;
DWORD value;

ret = GetLocaleInfoEx(LOCALE_NAME_USER_DEFAULT,
                      LOCALE_ICALENDARTYPE | LOCALE_RETURN_NUMBER,
                      (LPWSTR)&value,
                      sizeof(value) / sizeof(WCHAR) );
calid = value;

LOCALESIGNATURE LocSig;

ret = GetLocaleInfoEx(LOCALE_NAME_USER_DEFAULT,
                      LOCALE_FONTSIGNATURE,
                      (LPWSTR)&LocSig,
                      sizeof(LocSig) / sizeof(WCHAR) );

```

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

#### Examples

Examples showing the use of this function can be found in [NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample) and [NLS: Internationalized Domain Name (IDN) Mitigation Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--internationalized-domain-name--idn--mitigation-sample).

## See also

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[GetSystemDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename)

[GetUserDefaultLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Retrieving and Setting Locale Information](https://learn.microsoft.com/windows/desktop/Intl/retrieving-and-setting-locale-information)

[SetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setlocaleinfoa)