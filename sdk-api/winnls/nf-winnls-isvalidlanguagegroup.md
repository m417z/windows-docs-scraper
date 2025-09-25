# IsValidLanguageGroup function

## Description

Determines if a language group is installed or supported on the operating system. For more information, see [NLS Terminology](https://learn.microsoft.com/windows/desktop/Intl/nls-terminology).

## Parameters

### `LanguageGroup` [in]

Identifier of language group to validate. This parameter can have one of the following values:

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

Flag specifying the validity test to apply to the language group identifier. This parameter can be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **LGRPID_INSTALLED** | Determine if language group identifier is both supported and installed. |
| **LGRPID_SUPPORTED** | Determine if language group identifier is supported. |

## Return value

Returns **TRUE** if the language group identifier passes the specified validity test, or **FALSE** otherwise.

## Remarks

If the LGRPID_INSTALLED flag is specified and this function returns **TRUE**, the language group identifier is both supported and installed on the operating system.

If the LGRPID_SUPPORTED flag is specified and this function returns **TRUE**, the language group identifier is supported in the release, but not necessarily installed on the operating system.

## See also

[EnumLanguageGroupLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumlanguagegrouplocalesa)

[EnumSystemLanguageGroups](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlanguagegroupsa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)