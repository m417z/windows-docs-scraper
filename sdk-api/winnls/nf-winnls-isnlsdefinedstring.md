# IsNLSDefinedString function

## Description

Determines if each character in a string has a defined result for a specified NLS capability.

## Parameters

### `Function` [in]

NLS capability to query. This value must be COMPARE_STRING. See the [SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function) enumeration.

### `dwFlags` [in]

Flags defining the function. Must be 0.

### `lpVersionInformation` [in]

Pointer to an [NLSVERSIONINFO](https://learn.microsoft.com/windows/win32/api/winnls/ns-winnls-nlsversioninfo-r1) structure containing version information. Typically, the information is obtained by calling [GetNLSVersion](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversion). The application sets this parameter to **NULL** if the function is to use the current version.

### `lpString` [in]

Pointer to the UTF-16 string to examine.

### `cchStr` [in]

Number of UTF-16 characters in the string indicated by *lpString*. This count can include a terminating null character. If the terminating null character is included in the character count, it does not affect the checking behavior because the terminating null character is always defined.

The application should supply -1 to indicate that the string is null-terminated. In this case, the function itself calculates the string length.

## Return value

Returns **TRUE** if successful, only if the input string is valid, or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function differentiates between defined and undefined strings, so that an application such as Active Directory can reject strings with undefined code points. Use of the function can minimize the necessity for the application to re-index its database. For more information, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications).

For example, if *Function* is set to COMPARE_STRING, **IsNLSDefinedString** checks for undefined code points, [surrogate pairs](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters) that represent undefined Unicode characters, or ill-formed surrogate pairs. If the function returns **TRUE** for a particular string, the results, as retrieved by [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) or [LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa) with LCMAP_SORTKEY set, are guaranteed to be identical as long as the corresponding NLS version does not change.

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[GetNLSVersion](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversion)

[LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa)

[NLSVERSIONINFO](https://learn.microsoft.com/windows/win32/api/winnls/ns-winnls-nlsversioninfo-r1)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function)