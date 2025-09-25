# MAKESORTLCID macro

## Syntax

```cpp
DWORD MAKESORTLCID(
    WORD lgid,
    WORD srtid,
    WORD ver
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the LCID.

## Description

Constructs a [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) (LCID) from a [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers), a [sort order identifier](https://learn.microsoft.com/windows/desktop/Intl/sort-order-identifiers), and the sort version.

## Parameters

### `lgid`

Language identifier. This parameter is a combination of a primary language identifier and a sublanguage identifier and is usually created by using the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro.

### `srtid`

Sort order identifier.

### `ver`

Reserved; must be 0.

## Remarks

[LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant) represents a special locale-independent locale identifier. It is designed for system-level functions that require consistent results regardless of the locale that the user has chosen, for example, sorting in the file system. Typically, an application does not use LOCALE_INVARIANT because it expects the results of an action to depend on the rules governing each individual locale.

[LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant) is composed of a language identifier consisting of LANG_INVARIANT for the primary language and SUBLANG_NEUTRAL for the sublanguage. SORT_DEFAULT is used for the sort order identifier.

## See also

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)