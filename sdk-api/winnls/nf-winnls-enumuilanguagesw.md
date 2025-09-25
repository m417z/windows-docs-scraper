# EnumUILanguagesW function

## Description

Enumerates the user interface languages that are available on the operating system and calls the callback function with every language in the list.

## Parameters

### `lpUILanguageEnumProc` [in]

Pointer to an application-defined [EnumUILanguagesProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-uilanguage_enumproca) callback function. **EnumUILanguages** calls this function repeatedly to enumerate the languages in the list.

### `dwFlags` [in]

Flags identifying language format and filtering. The following flags specify the format of the language to pass to the callback function. The format flags are mutually exclusive, and MUI_LANGUAGE_ID is the default.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Pass the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) in the language string to the callback function. |
| **MUI_LANGUAGE_NAME** | Pass the [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) in the language string to the callback function. |

The following flags specify the filtering for the function to use in enumerating the languages. The filtering flags are mutually exclusive, and the default is MUI_LICENSED_LANGUAGES.

| Value | Meaning |
| --- | --- |
| **MUI_ALL_INSTALLED_LANGUAGES** | Enumerate all installed languages available to the operating system. |
| **MUI_LICENSED_LANGUAGES** | Enumerate all installed languages that are available and licensed for use. |
| **MUI_GROUP_POLICY** | Enumerate all installed languages that are available and licensed, and that are allowed by <br><br>the group policy. |

**Windows Vista and later:** The application can set *dwFlags* to 0, or to one or more of the specified flags. A setting of 0 causes the parameter value to default to MUI_LANGUAGE_ID | MUI_LICENSED_LANGUAGES.

**Windows 2000, Windows XP, Windows Server 2003:** The application must set *dwFlags* to 0.

### `lParam` [in]

Application-defined value.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates the user interface languages that are available and, depending on the flag specified, licensed for use on the operating system. It passes language identifiers or language names, one at a time, to the [EnumUILanguagesProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-uilanguage_enumproca) callback function. The **EnumUILanguages** function continues to pass language identifiers or names to the callback function until the last language is found or the callback function returns **FALSE**.

For applications that run only on Windows Vista and later, MUI_LANGUAGE_NAME is recommended over MUI_LANGUAGE_ID. MUI_LANGUAGE_NAME allows differentiation between languages that are associated with a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales).

If the MUI_LANGUAGE_ID flag is specified in the call to this function, the strings passed to the callback

function will be hexadecimal language identifiers that do not include the leading 0x, and will be 4

characters in length. For example, en-US will be passed as "0409" and en as "0009". The value "1000" is passed to the callback function for any language associated with a supplemental locale. This value corresponds to the hexadecimal value of [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants). It does not distinguish among supplemental locales, even if the selected language is in the user preferred UI languages list or the system preferred UI languages list.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean EnumUILanguages(
            EnumUILanguagesProc lpUILanguageEnumProc,
            System.UInt32 dwFlags,
            System.IntPtr lParam
            );

```

> [!NOTE]
> The winnls.h header defines EnumUILanguages as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumUILanguagesProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-uilanguage_enumproca)

[GetSystemDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultuilanguage)

[GetUserDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultuilanguage)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)