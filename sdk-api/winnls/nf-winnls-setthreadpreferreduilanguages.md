# SetThreadPreferredUILanguages function

## Description

Sets the thread preferred UI languages for the current thread. For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

**Note** This function is also used by the operating system to identify languages that are safe to use on the Windows console.

## Parameters

### `dwFlags` [in]

Flags identifying format and filtering for the languages to set.

The following *format flags* specify the language format to use for the thread preferred UI languages. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

We recommend that you use MUI_LANGUAGE_NAME instead of MUI_LANGUAGE_ID.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | The input parameter language strings are in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | The input parameter language strings are in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

The following *filtering flags* specify filtering for the language list. The flags are mutually exclusive. By default, neither MUI_COMPLEX_SCRIPT_FILTER nor MUI_CONSOLE_FILTER is set. For more information about the filtering flags, see the Remarks section.

| Value | Meaning |
| --- | --- |
| **MUI_COMPLEX_SCRIPT_FILTER** | [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) should replace with the appropriate fallback all languages having [complex scripts](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary). When this flag is specified, **NULL** must be passed for all other parameters. |
| **MUI_CONSOLE_FILTER** | [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) should replace with the appropriate fallback all languages that cannot display properly in a console window with the current operating system settings. When this flag is specified, **NULL** must be passed for all other parameters. |
| **MUI_RESET_FILTERS** | Reset the filtering for the language list by removing any other filter settings. When this flag is specified, **NULL** must be passed for all other parameters. After setting this flag, the application can call [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) to retrieve the complete unfiltered list. |

### `pwszLanguagesBuffer` [in, optional]

Pointer to a double null-terminated multi-string buffer that contains an ordered, null-delimited list, in the format specified by *dwFlags*.

To clear the thread preferred UI languages list, an application sets this parameter to a null string or an empty double null-terminated string.
If an application clears a language list, it should specify either a format flag or 0 for the *dwFlags* parameter.

When the application specifies one of the filtering flags, it must set this parameter to **NULL**. In this case, the function succeeds, but does not reset the thread preferred languages.

### `pulNumLanguages` [out, optional]

Pointer to the number of languages that the function has set in the thread preferred UI languages list. When the application specifies one of the filtering flags, the function must set this parameter to **NULL**.

## Return value

Returns **TRUE** if the function succeeds or **FALSE** otherwise.

## Remarks

When the application loads resources after a call to this function, the thread-specific preferences take priority over the languages preferred by the user.

This function can set up to five preferred languages for the thread, in order of preference. If the language buffer contains more than five valid languages, the function sets the first five valid languages and ignores the rest.

If the application calls this function with the MUI_LANGUAGE_ID flag set, the strings in the language list must use hexadecimal language

identifiers that do not include the leading 0x, and are 4 characters in length. For example, en-US should be

passed as "0409" and en as "0009".

When MUI_LANGUAGE_ID is specified, the hexadecimal values in the language list must each represent an actual language identifier. In particular, the following locale identifier values cannot be used to correspond to the language identifier:

* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)
* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

Calling this function with an empty language list and setting the MUI_CONSOLE_FILTER flag has the same effect as calling [SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage) with the language identifier set to 0. The language is set appropriately for use in a console window.

After this function returns, the application can call [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) to verify and examine the resulting language list. When MUI_CONSOLE_FILTER or MUI_COMPLEX_FILTER has been set by **SetThreadPreferredUILanguages**, the [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) function replaces with the fallback the languages the console cannot display using the current operating system language setting. The fallback for a language is determined based on the value of [LOCALE_SCONSOLEFALLBACKNAME](https://learn.microsoft.com/windows/desktop/Intl/locale-sconsolefallbackname) for the language.

Setting the MUI_COMPLEX_SCRIPT_FILTER flag in the call to **SetThreadPreferredUILanguages** causes [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) to remove languages that the console cannot display with languages that can only be rendered using [Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe), and insert the fallback language as the ultimate fallback. Examples of such languages are Arabic or the various Indic languages.

Setting the MUI_CONSOLE_FILTER flag in the call to **SetThreadPreferredUILanguages** causes [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) to remove languages the console cannot display with the current system setting and insert the fallback language as the ultimate fallback, because the console is limited to displaying characters from a single [code page](https://learn.microsoft.com/windows/desktop/Intl/code-pages). For example, if the user language is Japanese (Japan), but the current console code page is the code page for Russian (Russia), the console displays Japanese-language text mostly as a series of character-not-found symbols. [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) chooses a language from the fallback list that will be legible in the console.

**Note** Resource-loading functions, such as [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa), [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea), and [FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea), also make calls to [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages).

To change the code page, the application uses the **setlocale** function, or equivalent.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean SetThreadPreferredUILanguages(
            System.UInt32 dwFlags,
            System.String pwszLanguagesBuffer,
            ref System.UInt32 pulNumLanguages
            );

```

## See also

[GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage)