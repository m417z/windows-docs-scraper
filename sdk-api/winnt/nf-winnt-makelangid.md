# MAKELANGID macro

## Syntax

```cpp
WORD MAKELANGID(
    USHORT p,
    USHORT s
);
```

## Return value

Type: **WORD**

Returns the language identifier.

> [!IMPORTANT]
> Language identifier constants are deprecated and their use is discouraged. Use of locale names instead of locale identifiers is always preferable. See the documentation for [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex).

## Description

Creates a [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) from a primary language identifier and a sublanguage identifier.

## Parameters

### `p`

Primary language identifier. This identifier can be a predefined value or a value for a user-defined primary language. For a user-defined language, the identifier is a value in the range 0x0200 to 0x03FF. All other values are reserved for operating system use. For more information, see [Language Identifier Constants and Strings](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings).

### `s`

Sublanguage identifier. This parameter can be a predefined sublanguage identifier or a user-defined sublanguage. For a user-defined sublanguage, the identifier is a value in the range 0x20 to 0x3F. All other values are reserved for operating system use. For more information, see [Language Identifier Constants and Strings](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings).

## Remarks

The following table shows combinations of *usPrimaryLanguage* and *usSubLanguage* that have special meaning.

| Primary language identifier | Sublanguage identifier | Meaning |
| --- | --- | --- |
| LANG_NEUTRAL | SUBLANG_NEUTRAL | Language neutral |
| LANG_NEUTRAL | SUBLANG_DEFAULT | User default language |
| LANG_NEUTRAL | SUBLANG_SYS_DEFAULT | System default language |
| LANG_NEUTRAL | SUBLANG_CUSTOM_DEFAULT | **Windows Vista and later:** Default custom locale |
| LANG_NEUTRAL | SUBLANG_CUSTOM_UNSPECIFIED | **Windows Vista and later:** Unspecified custom locale |
| LANG_NEUTRAL | SUBLANG_UI_CUSTOM_DEFAULT | **Windows Vista and later:** Default custom Multilingual User Interface locale |

## See also

[EnumSystemLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[PRIMARYLANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-primarylangid)

[SUBLANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-sublangid)

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)