# GetSystemDefaultUILanguage function

## Description

Retrieves the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the system default UI language of the operating system (also known as the "install language" on Windows Vista and later). For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

> [!Important]
> Use of this function is not recommended. Instead, we recommend using the [User language settings](https://learn.microsoft.com/windows/win32/intl/setting-application-language-preferences) for the following reasons.
>
> - "Install language" is only set during the Out of Box Experience (OOBE) and then never changes. If the system language is changed, this function returns an incorrect value.
> - WCOS SKUs always return an incorrect value.
> - This function uses deprecated LANGIDs.

## Return value

Returns the language identifier for the system default UI language of the operating system. For more information, see the Remarks section.

## Remarks

This function never returns a language identifier for a Language Interface Pack (LIP). It also never returns a language identifier corresponding to the locale identifier [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants) or [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

Note that this function does not necessarily return the identifier for the first language in the system preferred UI languages list. Therefore the return might not match the first element retrieved by [GetSystemPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystempreferreduilanguages).

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.UInt16 GetSystemDefaultUILanguage();

```

## See also

[EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa), [GetSystemPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystempreferreduilanguages), [GetUserDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultuilanguage), [Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface), [Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)