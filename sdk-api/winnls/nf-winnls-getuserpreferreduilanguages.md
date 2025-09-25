# GetUserPreferredUILanguages function

## Description

Retrieves information about the display language setting. For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

## Parameters

### `dwFlags` [in]

Flags identifying language format and filtering. The following flags specify the language format to use for the display language list. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Retrieve the language strings in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) |
| **MUI_LANGUAGE_NAME** | Retrieve the language strings in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

### `pulNumLanguages` [out]

Pointer to the number of languages retrieved in *pwszLanguagesBuffer*.

### `pwszLanguagesBuffer` [out, optional]

Optional. Pointer to a buffer in which this function retrieves an ordered, null-delimited display language list, in the format specified by *dwflags*. This list ends with two null characters.

Alternatively if this parameter is set to **NULL** and *pcchLanguagesBuffer* is set to 0, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*. The required size includes the two null characters.

### `pcchLanguagesBuffer` [in, out]

Pointer to the size, in characters, for the language buffer indicated by *pwszLanguagesBuffer*. On successful return from the function, the parameter contains the size of the retrieved language buffer.

Alternatively if this parameter is set to 0 and *pwszLanguagesBuffer* is set to **NULL**, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.

If the function fails for any other reason, the values of *pulNumLanguages* and *pcchLanguagesBuffer* are undefined.

## Remarks

When MUI_LANGUAGE_ID is specified, the language strings retrieved will be hexadecimal language identifiers that do not include the leading 0x, and will be 4 characters in length. For example, en-US will be returned as "0409" and en as "0009".

The display language cannot include more than one Language Interface Pack (LIP) language that corresponds to a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). If the list includes more than one of these languages, and if the application specifies MUI_LANGUAGE_ID in the call to the function, the language buffer contains "1400" for that language. This string corresponds to the hexadecimal value of [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

The language list retrieved by this function has the following characteristics:

- Each language represents a valid NLS locale.
- Each language is installed on the operating system.
- The list contains one entry for each language, with no duplicate entries.
- If the list is empty or does not meet these validation criteria, the system preferred UI languages list is used instead.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean GetUserPreferredUILanguages(
            System.UInt32 dwFlags,
            ref System.UInt32 pulNumLanguages,
            System.IntPtr pwszLanguagesBuffer,
            ref System.UInt32 pcchLanguagesBuffer
            );

```

## See also

[GetSystemPreferredUILanguages function](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-getsystempreferreduilanguages), [GetThreadPreferredUILanguages function](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-getthreadpreferreduilanguages), [GetThreadUILanguage function](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-getthreaduilanguage), [SetThreadPreferredUILanguages function](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-setthreadpreferreduilanguages), [Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface), [Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)