# IsValidNLSVersion function

## Description

Determines if the NLS version is valid for a given NLS function.

## Parameters

### `function` [in]

The NLS capability to query. This value must be COMPARE_STRING. See the [SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function) enumeration.

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `lpVersionInformation` [in]

Pointer to an [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure. The application must initialize the **dwNLSVersionInfoSize** member to  `sizeof(NLSVERSIONINFOEX)`.

## Return value

Returns a nonzero value if the NLS version is valid, or zero if the version is invalid.

## Remarks

Initialize the [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure by calling [GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex). See the Remarks for **GetNLSVersionEx** for a discussion on how the members of **NLSVERSIONINFOEX** can be used to determine if a sort version has changed and you need to reindex data.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex)