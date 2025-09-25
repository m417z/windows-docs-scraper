# GetProcessPreferredUILanguages function

## Description

Retrieves the process preferred UI languages. For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

## Parameters

### `dwFlags` [in]

Flags identifying the language format to use for the process preferred UI languages. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Retrieve the language strings in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | Retrieve the language strings in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

### `pulNumLanguages` [out]

Pointer to the number of languages retrieved in *pwszLanguagesBuffer*.

### `pwszLanguagesBuffer` [out, optional]

Optional. Pointer to a double null-terminated multi-string buffer in which the function retrieves an ordered, null-delimited list in preference order, starting with the most preferable.

Alternatively if this parameter is set to **NULL** and *pcchLanguagesBuffer* is set to 0, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*. The required size includes the two null characters.

### `pcchLanguagesBuffer` [in, out]

Pointer to the size, in characters, for the language buffer indicated by *pwszLanguagesBuffer*. On successful return from the function, the parameter contains the size of the retrieved language buffer.

Alternatively if this parameter is set to 0 and *pwszLanguagesBuffer* is set to **NULL**, the function retrieves the required size of the language buffer in *pcchLanguagesBuffer*.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

If the process preferred UI language list is empty or if the languages specified for the process are not valid, the function succeeds and returns an empty multistring in *pwszLanguagesBuffer* and 2 in the *pcchLanguagesBuffer* parameter.

## Remarks

Depending on the flags specified by the application, this function can retrieve a list consisting of the process preferred UI languages. If it encounters a duplicate language, the function only retrieves the first instance of the duplicated language.

When MUI_LANGUAGE_ID is specified, the language strings retrieved will be hexadecimal language identifiers

that do not include the leading 0x, and will be 4 characters in length. For example, en-US will be returned

as "0409" and en as "0009".

**Note** Use of MUI_LANGUAGE_NAME is recommended over MUI_LANGUAGE_ID.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean GetProcessPreferredUILanguages(
            System.UInt32 dwFlags,
            ref System.UInt32 pulNumLanguages,
            System.IntPtr pwszLanguagesBuffer,
            ref System.UInt32 pcchLanguagesBuffer
            );

```

## See also

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetProcessPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setprocesspreferreduilanguages)