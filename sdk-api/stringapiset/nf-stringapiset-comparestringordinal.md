# CompareStringOrdinal function

## Description

Compares two [Unicode](https://learn.microsoft.com/windows/desktop/Intl/unicode) strings to test binary equivalence.

## Parameters

### `lpString1` [in]

Pointer to the first string to compare.

### `cchCount1` [in]

Length of the string indicated by *lpString1*. The application supplies -1 if the string is null-terminated. In this case, the function determines the length automatically.

### `lpString2` [in]

Pointer to the second string to compare.

### `cchCount2` [in]

Length of the string indicated by *lpString2*. The application supplies -1 if the string is null-terminated. In this case, the function determines the length automatically.

### `bIgnoreCase` [in]

**TRUE** if the function is to perform a case-insensitive comparison, using the operating system uppercase table information. The application sets this parameter to **FALSE** if the function is to compare the strings exactly as they are passed in. Note that 1 is the only numeric value that can be used to specify a true value for this boolean parameter that does not result an invalid parameter error. Boolean values for this parameter work as expected.

## Return value

Returns one of the following values if successful. To maintain the C runtime convention of comparing strings, the value 2 can be subtracted from a nonzero return value. Then, the meaning of <0, ==0, and >0 is consistent with the C runtime.

* CSTR_LESS_THAN. The value indicated by *lpString1* is less than the value indicated by *lpString2*.
* CSTR_EQUAL. The value indicated by *lpString1* equals the value indicated by *lpString2*.
* CSTR_GREATER_THAN. The value indicated by *lpString1* is greater than the value indicated by *lpString2*.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function tests for binary equality, not linguistic equality. For information about the use of the function for ordinal sorting, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications).

Applications that are concerned with linguistic equality should use [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw), [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex), [lstrcmp](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpa), or [lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia). For more information about linguistic sorting, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

**Starting with Windows 8:** **CompareStringOrdinal** is declared in Stringapiset.h. Before Windows 8, it was declared in Winnls.h.

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)