# MAKELCID macro

## Syntax

```cpp
DWORD MAKELCID(
    WORD lgid,
    WORD srtid
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the locale identifier.

## Description

Creates a [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) from a [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) and a [sort order identifier](https://learn.microsoft.com/windows/desktop/Intl/sort-order-identifiers).

## Parameters

### `lgid`

[Language identifier](https://learn.microsoft.com/windows/win32/intl/language-identifiers). This identifier is a combination of a primary language identifier and a sublanguage identifier and is usually created by using the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro.

### `srtid`

[Sort order identifier](https://learn.microsoft.com/windows/win32/intl/sort-order-identifiers).

## See also

[LANGIDFROMLCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-langidfromlcid)

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[Language Identifier Constants and Strings](https://learn.microsoft.com/windows/win32/intl/language-identifier-constants-and-strings)

[SORTIDFROMLCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-sortidfromlcid)