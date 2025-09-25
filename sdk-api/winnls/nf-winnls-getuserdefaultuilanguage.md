# GetUserDefaultUILanguage function

## Description

Returns the language identifier for the user UI language for the current user. If the current user has not set a language, **GetUserDefaultUILanguage** returns the preferred language set for the system. If there is no preferred language set for the system, then the system default UI language (also known as "install language") is returned. For more information about the user UI language, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

## Return value

Returns the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the user UI language for the current user.

## Remarks

This function returns only a language identifier. An application can retrieve the language name using the [GetUserPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserpreferreduilanguages) function.

If the user UI language is part of a Language Interface Pack (LIP) and corresponds to a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales), this function returns [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

**Windows Me, Windows 2000, Windows XP, Windows Server 2003:** The **GetUserDefaultUILanguage** function retrieves the language identifier for the current user language. If MUI is not installed on the operating system, the function retrieves the default computer user interface language.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.UInt16 GetUserDefaultUILanguage();

```

## See also

[EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa)

[GetSystemDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultuilanguage)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)