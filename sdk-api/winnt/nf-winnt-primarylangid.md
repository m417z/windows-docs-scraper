# PRIMARYLANGID macro

## Syntax

```cpp
WORD PRIMARYLANGID(
    WORD lgid
);
```

## Return value

Type: **WORD**

Returns the primary language identifier. It can be one of the predefined primary language identifiers or a user-defined primary language identifier. For more information, see [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid).

## Description

Extracts a primary language identifier from a [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers).

## Parameters

### `lgid`

Language identifier. This value is a combination of a primary language identifier and a sublanguage identifier and is usually created by using the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro.

## See also

[EnumSystemLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesa)

[LANGIDFROMLCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-langidfromlcid)

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[SUBLANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-sublangid)