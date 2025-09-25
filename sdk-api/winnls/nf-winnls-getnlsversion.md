# GetNLSVersion function

## Description

Retrieves information about the current version of a specified NLS capability for a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex) function to **GetNLSVersion** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. This recommendation applies especially to custom locales, for which **GetNLSVersionEx** retrieves enough information to determine if sort behavior has changed. Any application that runs only on Windows Vista and later should use [GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex) or at least pass the [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure when calling **GetNLSVersion** to obtain additional sorting versioning data.

## Parameters

### `Function` [in]

The NLS capability to query. This value must be COMPARE_STRING. See the [SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function) enumeration.

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create an identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `lpVersionInformation` [in, out]

Pointer to an [NLSVERSIONINFO](https://learn.microsoft.com/windows/win32/api/winnls/ns-winnls-nlsversioninfo-r1) structure. The application must initialize the **dwNLSVersionInfoSize** member to `sizeof(NLSVERSIONINFO)`.

**Note** On Windows Vista and later, the function can alternatively provide version information in an [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure.

## Return value

Returns **TRUE** if and only if the application has supplied valid values in *lpVersionInformation*, or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function allows an application such as Active Directory to determine if an NLS change affects the locale identifier used for a particular index table. If it does not, there is no need to re-index the table. For more information, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications).

## See also

[GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[NLSVERSIONINFO](https://learn.microsoft.com/windows/win32/api/winnls/ns-winnls-nlsversioninfo-r1)

[NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function)