# SetProcessPreferredUILanguages function

## Description

Sets the process preferred UI languages for the application process. For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

## Parameters

### `dwFlags` [in]

Flags identifying the language format to use for the process preferred UI languages. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

We recommend that you use MUI_LANGUAGE_NAME instead of MUI_LANGUAGE_ID.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | The input parameter language strings are in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | The input parameter language strings are in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

### `pwszLanguagesBuffer` [in, optional]

Pointer to a double null-terminated multi-string buffer that contains an ordered, null-delimited list in decreasing order of preference. If there are more than five languages in the buffer, the function only sets the first five valid languages.

Alternatively, this parameter can contain **NULL** if no language list is required. In this case, the function clears the preferred UI languages for the process.

### `pulNumLanguages` [out, optional]

Pointer to the number of languages that has been set in the process language list from the input buffer, up to a maximum of five.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return the following error code:

* ERROR_INVALID_PARAMETER. An invalid parameter is specified.

If the process preferred UI languages list is empty or if the languages specified for the process are not valid, the function succeeds and sets 0 in the *pulNumLanguages* parameter.

## Remarks

Ideally, applications will call **SetProcessPreferredUILanguages** as soon as possible after launching.

After this function returns, the application can call [GetProcessPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getprocesspreferreduilanguages) to verify and examine the resulting language list.

When MUI_LANGUAGE_ID is specified, the input parameter language strings must use hexadecimal language

identifiers that do not include the leading 0x, and are 4 characters in length. For example, en-US should be

passed as "0409" and en as "0009".

**Note** Use of MUI_LANGUAGE_NAME is recommended over MUI_LANGUAGE_ID.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean SetProcessPreferredUILanguages(
            System.UInt32 dwFlags,
            System.String pwszLanguagesBuffer,
            ref System.UInt32 pulNumLanguages
            );

```

## See also

[GetProcessPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getprocesspreferreduilanguages)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)