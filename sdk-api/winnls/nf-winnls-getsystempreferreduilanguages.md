# GetSystemPreferredUILanguages function

## Description

Retrieves the system preferred UI languages. For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

## Parameters

### `dwFlags` [in]

Flags identifying language format and filtering. The following flags specify the format to use for the system preferred UI languages. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Retrieve the language strings in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | Retrieve the language strings in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

The following flag specifies whether the function is to validate the list of languages (default) or retrieve the system preferred UI languages list exactly as it is stored in the registry.

| Value | Meaning |
| --- | --- |
| **MUI_MACHINE_LANGUAGE_SETTINGS** | Retrieve the stored system preferred UI languages list, checking only to ensure that each language name corresponds to a valid NLS locale. If this flag is not set, the function retrieves the system preferred UI languages in *pwszLanguagesBuffer*, as long as the list is non-empty and meets the validation criteria. Otherwise, the function retrieves the system default user interface language in the language buffer. |

### `pulNumLanguages` [out]

Pointer to the number of languages retrieved in *pwszLanguagesBuffer*.

### `pwszLanguagesBuffer` [out, optional]

Optional. Pointer to a buffer in which this function retrieves an ordered, null-delimited system preferred UI languages list, in the format specified by *dwFlags*. This list ends with two null characters.

Alternatively if this parameter is set to **NULL** and *pcchLanguagesBuffer* is set to 0, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*. The required size includes the two null characters

### `pcchLanguagesBuffer` [in, out]

Pointer to the size, in characters, for the language buffer indicated by *pwszLanguagesBuffer*. On successful return from the function, the parameter contains the size of the retrieved language buffer.

Alternatively if this parameter is set to 0 and *pwszLanguagesBuffer* is set to **NULL**, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.

If the function fails for any other reason, the parameters *pulNumLanguages* and *pcchLanguagesBuffer* are undefined.

## Remarks

When MUI_LANGUAGE_ID is specified, the language strings retrieved will be hexadecimal language identifiers

that do not include the leading 0x, and will be 4 characters in length. For example, en-US will be returned

as "0409" and en as "0009".

The system preferred UI languages cannot include more than one Language Interface Pack (LIP) language that corresponds to a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). If the list includes more than one of these languages, and if the application specifies MUI_LANGUAGE_ID in the call to the function, the language buffer contains "1400" for that language. This string corresponds to the hexadecimal value of [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

If the MUI_MACHINE_LANGUAGE_SETTINGS flag is set, this function checks each language in the list that represents a valid NLS locale. The retrieved list can contain the following items:

* Languages not installed on the system
* Duplicate language entries
* An empty string

If the MUI_MACHINE_LANGUAGE_SETTINGS flag is set and the system preferred UI languages list is empty, the function retrieves an empty string in the language buffer (two null characters, because it is a multistring buffer), 0 for the number of languages, and 2 for the buffer size.

If the MUI_MACHINE_LANGUAGE_SETTINGS flag is not set, the retrieved language list has the following characteristics:

* Each language represents a valid NLS locale.
* Each language is installed on the operating system.
* The list contains one entry for each language, with no duplicate entries.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean GetSystemPreferredUILanguages(
            System.UInt32 dwFlags,
            ref System.UInt32 pulNumLanguages,
            System.IntPtr pwszLanguagesBuffer,
            ref System.UInt32 pcchLanguagesBuffer
            );

```

## See also

[GetSystemDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultuilanguage)

[GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages)

[GetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreaduilanguage)

[GetUserPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserpreferreduilanguages)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages)