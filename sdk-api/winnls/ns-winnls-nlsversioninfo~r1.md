# NLSVERSIONINFO structure

## Description

Deprecated. Contains version information about an NLS capability.

Starting with Windows 8, your app should use [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) instead of **NLSVERSIONINFO**.

## Members

### `dwNLSVersionInfoSize`

Size, in bytes, of the structure.

### `dwNLSVersion`

NLS version. This value is used to track changes and additions to the set of code points that have the indicated capability for a particular locale. The value is locale-specific, and increments when the capability changes. For example, using the COMPARE_STRING capability defined by the [SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function) enumeration, the version changes if sorting weights are assigned to code points that previously had no weights defined for the locale.

### `dwDefinedVersion`

Defined version. This value is used to track changes in the repertoire of Unicode code points. The value increments when the Unicode repertoire is extended, for example, if more characters are defined.

## Remarks

Starting with Windows 8, **NLSVERSIONINFO** is deprecated. In fact, it is identical to [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex), which your app should use instead.

See Remarks for [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex).

## See also

[GetNLSVersion](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversion)

[GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[IsNLSDefinedString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isnlsdefinedstring)

[NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex)

[National Language Support Structures](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-structures)