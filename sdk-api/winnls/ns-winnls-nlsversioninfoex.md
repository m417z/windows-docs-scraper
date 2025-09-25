# NLSVERSIONINFOEX structure

## Description

Contains version information about an NLS capability.

## Members

### `dwNLSVersionInfoSize`

Size, in bytes, of the structure.

### `dwNLSVersion`

Version. This value is used to track changes and additions to the set of code points that have the indicated capability for a particular locale. The value is locale-specific, and increments when the capability changes. For example, using the COMPARE_STRING capability defined by the [SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function) enumeration, the version changes if sorting weights are assigned to code points that previously had no weights defined for the locale.

### `dwDefinedVersion`

Defined version. This value is used to track changes in the repertoire of Unicode code points. The value increments when the Unicode repertoire is extended, for example, if more characters are defined.

**Starting with Windows 8:** Deprecated. Use **dwNLSVersion** instead.

### `dwEffectiveId`

Identifier of the sort order used for the input locale for the represented version. For example, for a custom locale en-Mine that uses 0409 for a sort order identifier, this member contains "0409". If this member specifies a "real" sort, **guidCustomVersion** is set to an empty GUID.

**Starting with Windows 8:** Deprecated. Use **guidCustomVersion** instead.

### `guidCustomVersion`

Unique GUID for the behavior of a custom sort used by the locale for the represented version.

## Remarks

The **dwNLSVersion** and **dwDefinedVersion** members are completely independent. Although each member is defined for a single DWORD, actually each is composed of a major version and a minor version. See [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications) for more information.

## See also

[GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[IsNLSDefinedString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isnlsdefinedstring)

[National Language Support Structures](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-structures)