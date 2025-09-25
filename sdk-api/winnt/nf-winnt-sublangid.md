# SUBLANGID macro

## Syntax

```cpp
WORD SUBLANGID(
    WORD lgid
);
```

## Return value

Type: **WORD**

Returns a sublanguage identifier. This can be a predefined sublanguage identifier or a user-defined sublanguage identifier.

## Description

Extracts a sublanguage identifier from a [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers).

## Parameters

### `lgid`

Language identifier. You can supply predefined values for this parameter, or create an identifier using the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro.

## See also

[EnumSystemLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesa)

[LANGIDFROMLCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-langidfromlcid)

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[PRIMARYLANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-primarylangid)