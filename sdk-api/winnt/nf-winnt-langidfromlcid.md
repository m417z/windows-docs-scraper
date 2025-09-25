# LANGIDFROMLCID macro

## Syntax

```cpp
WORD LANGIDFROMLCID(
    LCID lcid
);
```

## Return value

Type: **WORD**

Returns the language identifier.

## Description

Retrieves a [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) from a [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

## Parameters

### `lcid`

Locale identifier. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

## See also

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

[MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[PRIMARYLANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-primarylangid)

[SUBLANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-sublangid)