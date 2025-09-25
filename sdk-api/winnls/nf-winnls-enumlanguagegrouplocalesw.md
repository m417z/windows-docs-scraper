# EnumLanguageGroupLocalesW function

## Description

Enumerates the locales in a specified language group.

**Note** For custom locales, your application should call [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex) in preference to **EnumLanguageGroupLocales**.

## Parameters

### `lpLangGroupLocaleEnumProc` [in]

Pointer to an application-defined callback function. For more information, see [EnumLanguageGroupLocalesProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-langgrouplocale_enumproca).

### `LanguageGroup` [in]

Identifier of the language group for which to enumerate locales. This parameter can have one of the following values:

* LGRPID_ARABIC
* LGRPID_ARMENIAN
* LGRPID_BALTIC
* LGRPID_CENTRAL_EUROPE
* LGRPID_CYRILLIC
* LGRPID_GEORGIAN
* LGRPID_GREEK
* LGRPID_HEBREW
* LGRPID_INDIC
* LGRPID_JAPANESE
* LGRPID_KOREAN
* LGRPID_SIMPLIFIED_CHINESE
* LGRPID_TRADITIONAL_CHINESE
* LGRPID_THAI
* LGRPID_TURKIC
* LGRPID_TURKISH
* LGRPID_VIETNAMESE
* LGRPID_WESTERN_EUROPE

### `dwFlags` [in]

Reserved; must be 0.

### `lParam` [in]

An application-defined value to pass to the callback function. This value can be used for error checking. It can also be used to ensure thread safety in the callback function.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates locales in the specified language group by passing locale identifiers, one at a time, to the application-defined callback function. This process continues until **EnumLanguageGroupLocales** finds the last locale identifier or the callback function returns **FALSE**.

> [!NOTE]
> The winnls.h header defines EnumLanguageGroupLocales as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumLanguageGroupLocalesProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-langgrouplocale_enumproca)

[EnumSystemLanguageGroups](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlanguagegroupsa)

[EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex)

[IsValidLanguageGroup](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isvalidlanguagegroup)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)