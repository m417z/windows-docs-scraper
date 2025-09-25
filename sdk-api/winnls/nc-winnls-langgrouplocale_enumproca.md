# LANGGROUPLOCALE_ENUMPROCA callback function

## Description

An application-defined callback function that processes enumerated language group locale information provided by the [EnumLanguageGroupLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumlanguagegrouplocalesa) function. The LANGGROUPLOCALE_ENUMPROC type defines a pointer to this callback function. **EnumLanguageGroupLocalesProc** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

### `unnamedParam4`

#### - LanguageGroup [in]

Identifier of the language group. This parameter can have one of the following values:

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

#### - Locale [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

#### - lParam [in]

Application-defined value passed to the [EnumLanguageGroupLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumlanguagegrouplocalesa) function. This parameter can be used for error checking.

#### - lpLocaleString [in]

Pointer to a buffer containing a null-terminated locale identifier string.

## Return value

Returns **TRUE** to continue enumeration or **FALSE** otherwise.

## Remarks

An **EnumLanguageGroupLocalesProc** function can carry out any desired task. The application registers this function by passing its address to the [EnumLanguageGroupLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumlanguagegrouplocalesa) function.

> [!NOTE]
> The winnls.h header defines LANGGROUPLOCALE_ENUMPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumLanguageGroupLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumlanguagegrouplocalesa)

[EnumSystemLanguageGroups](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlanguagegroupsa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)