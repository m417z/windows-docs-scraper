# GetUILanguageInfo function

## Description

Retrieves a variety of information about an installed UI language:

* Is the language installed?
* Is the current user licensed to use the language?
* Is the language fully localized? Partially localized? Part of a Language Installation Pack (LIP)?
* If it is partially localized or part of an LIP:
  + What is its fallback language?
  + If that fallback language is a partially localized language, what is its base?
  + What is the default fallback language?

## Parameters

### `dwFlags` [in]

Flags defining the format of the specified language. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Retrieve the language strings in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | Retrieve the language strings in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

### `pwmszLanguage` [in]

Pointer to languages for which the function is to retrieve information. This parameter indicates an ordered, null-delimited list of language identifiers or language names, depending on the flag setting. For information on the use of this parameter, see the Remarks section.

### `pwszFallbackLanguages` [out, optional]

Pointer to a buffer in which this function retrieves an ordered, null-delimited list of fallback languages, formatted as defined by the setting for *dwFlags*. This list ends with two null characters.

Alternatively if this parameter is set to **NULL** and *pcchLanguagesBuffer* is set to 0, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*. The required size includes the two null characters.

### `pcchFallbackLanguages` [in, out, optional]

Pointer to the size, in characters, for the language buffer indicated by *pwszFallbackLanguages*. On successful return from the function, the parameter contains the size of the retrieved language buffer.

Alternatively if this parameter is set to 0 and *pwszLanguagesBuffer*  is set to **NULL**, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*.

### `pAttributes` [out]

Pointer to flags indicating attributes of the input language list. The function always retrieves the flag characterizing the last language listed.

| Value | Meaning |
| --- | --- |
| **MUI_FULL_LANGUAGE** | The language is fully localized. |
| **MUI_PARTIAL_LANGUAGE** | The language is partially localized. |
| **MUI_LIP_LANGUAGE** | The language is an LIP language. |

In addition, *pdwAttributes* includes one or both of the following flags, as appropriate.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_INSTALLED** | The language is installed on this computer. |
| **MUI_LANGUAGE_LICENSED** | The language is appropriately licensed for the current user. |

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid. For more information, see Remarks.
* ERROR_OBJECT_NAME_NOT_FOUND. The specified object name was not found, or it was not valid, or the first language in the input list is not an installed language. For more information, see Remarks.

If [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns any other error code, the parameters *pcchFallbackLanguages* and *pdwAttributes* are undefined.

## Remarks

MUI_LANGUAGE_NAME is recommended over MUI_LANGUAGE_ID because it allows the function to do a better job of handling LIP languages that do not correspond to predefined locales, but instead correspond to a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). LIP languages that correspond to predefined locales are handled just like non-LIP languages.

If the MUI_LANGUAGE_ID flag is specified, the supplied language strings must

use hexadecimal language identifiers that do not include the leading 0x, and are 4 characters in length.

For example, en-US should be passed as "0409" and en as "0009". The returned language strings will be in the

same format.

When MUI_LANGUAGE_ID is specified, and if there is such a language in the user preferred UI languages list, there can be only one such language in the list. That language can be specified in *pwmszLanguage* as "1400", which corresponds to the hexadecimal value of [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants). No other such language can be specified using MUI_LANGUAGE_ID. Using "1000", which corresponds to the hexadecimal value of [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants), in the string indicated by *pwmszLanguage* will result in an ERROR_INVALID_PARAMETER code.

A partially localized language can have a fallback language that is partially localized, requiring repeated calls to **GetUILanguageInfo** to obtain full information. Consider the case of a partially localized language Lang1 that offers a choice of three fallback languages. The Lang3 fallback language is partially localized, and offers a choice of two fallback languages. The dependencies are as follows, with the default fallback listed first:

* Lang1
  + Lang2
  + Lang3
    - Lang5
    - Lang6
  + Lang4

To get the fallback language(s) of Lang1, the application passes in *pwmszLanguage* as "Lang1\0\0". On return from the function, *pwszFallbackLanguages* is set to "Lang2\0Lang3\0Lang4\0\0". Note that the ordering of this list indicates that Lang2 is the default fallback language.

To get the fallback language(s) of Lang3 in relation to Lang1, the application passes in *pwmszLanguage* as "lang1\0\lang3\0\0". On return from the function, *pwszFallbackLanguages* is set to "Lang5\0Lang6\0\0".

This function returns ERROR_INVALID_PARAMETER for any of the following:

* *pwmszLanguage* is **NULL** or empty.
* Both MUI_LANGUAGE_ID and MUI_LANGUAGE_NAME are set.
* Any flags other than MUI_LANGUAGE_ID or MUI_LANGUAGE_NAME are set.
* *pcchFallbackLanguages* is greater than 0 but *pwszFallbackLanguages* is **NULL**.
* *pwmszLanguage* cannot be parsed as a multi-string buffer of language identifiers or language names, depending on the flag setting.

The ERROR_OBJECT_NAME_NOT_FOUND error code occurs if *pwmszLanguage* can be parsed, but is not valid. The code might also be returned for an invalid locale identifier, or if the first language in the input list is not an installed language, or if a fully localized language has defined a fallback language.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean GetUILanguageInfo(
            System.UInt32 dwFlags,
            System.String pwmszLanguage,
            System.IntPtr pwszFallbackLanguages,
            ref System.UInt32 pcchFallbackLanguages,
            ref System.UInt32 pdwAttributes
            );

```

## See also

[EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa)

[GetFileMUIInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getfilemuiinfo)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)