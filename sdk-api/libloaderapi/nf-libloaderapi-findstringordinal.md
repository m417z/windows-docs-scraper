# FindStringOrdinal function

## Description

Locates a Unicode string (wide characters) in another Unicode string for a non-linguistic comparison.

## Parameters

### `dwFindStringOrdinalFlags` [in]

Flags specifying details of the find operation. These flags are mutually exclusive, with FIND_FROMSTART being the default. The application can specify just one of the find flags.

| Value | Meaning |
| --- | --- |
| **FIND_FROMSTART** | Search the string, starting with the first character of the string. |
| **FIND_FROMEND** | Search the string in the reverse direction, starting with the last character of the string. |
| **FIND_STARTSWITH** | Test to find out if the value specified by *lpStringValue* is the first value in the source string indicated by *lpStringSource*. |
| **FIND_ENDSWITH** | Test to find out if the value specified by *lpStringValue* is the last value in the source string indicated by *lpStringSource*. |

### `lpStringSource` [in]

Pointer to the source string, in which the function searches for the string specified by *lpStringValue*.

### `cchSource` [in]

Size, in characters excluding the terminating null character, of the string indicated by *lpStringSource*. The application must normally specify a positive number, or 0. The application can specify -1 if the source string is null-terminated and the function should calculate the size automatically.

### `lpStringValue` [in]

Pointer to the search string for which the function searches in the source string.

### `cchValue` [in]

Size, in characters excluding the terminating null character, of the string indicated by *lpStringValue*. The application must normally specify a positive number, or 0. The application can specify -1 if the string is null-terminated and the function should calculate the size automatically.

### `bIgnoreCase` [in]

**TRUE** if the function is to perform a case-insensitive comparison, and **FALSE** otherwise. The comparison is not a linguistic operation and is not appropriate for all locales and languages. Its behavior is similar to that for English.

## Return value

Returns a 0-based index into the source string indicated by *lpStringSource* if successful. If the function succeeds, the found string is the same size as the value of *lpStringValue*. A return value of 0 indicates that the function found a match at the beginning of the source string.

The function returns -1 if it does not succeed or if it does not find the search string. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_SUCCESS. The action completed successfully but yielded no results.

## Remarks

Since **FindStringOrdinal** provides a binary comparison, it does not return linguistically appropriate results. The ordinal comparison might be mistaken for English sorting behavior. However, it does not find matches when characters vary by linguistically insignificant amounts. See [Sorting](https://learn.microsoft.com/windows/desktop/Intl/sorting) for information about choosing an appropriate sorting function.

In contrast to NLS functions that return 0 for failure, this function returns -1 if it fails. On success, it returns a 0-based index. Use of this index helps the function avoid off-by-one errors and one-character buffer overruns.

This function is one of the few NLS functions that calls [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) even when it succeeds. It makes this call to clear the last error in a thread when it fails to match the search string. This clears the value returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Starting with Windows 8:** **FindStringOrdinal** is declared in Libloaderapi.h. Before Windows 8, it was declared in Winnls.h.

## See also

[FindNLSString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstring)

[FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)