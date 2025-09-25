# GetThreadUILanguage function

## Description

Returns the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) of the first user interface language for the current thread.

## Return value

Returns the identifier for a language explicitly associated with the thread by [SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage) or [SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages). Alternatively, if no language has been explicitly associated with the current thread, the identifier can indicate a user or system user interface language.

## Remarks

Calling this function is identical to calling [GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages) with *dwFlags* set to MUI_MERGE_SYSTEM_FALLBACK | MUI_MERGE_USER_FALLBACK | MUI_LANGUAGE_ID and using the first language in the retrieved list.

The return value for this function does not provide useful information about a Language Interface Pack (LIP) language if that language corresponds to a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). For such a language, the function returns the hexadecimal value "1400", which corresponds to [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants) if that language is specified in the user preferred UI languages list. If the language is not specified in the user preferred UI languages list, the function returns the value "1000", corresponding to [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.UInt16 GetThreadUILanguage();

```

## See also

[GetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadpreferreduilanguages)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages)

[SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage)