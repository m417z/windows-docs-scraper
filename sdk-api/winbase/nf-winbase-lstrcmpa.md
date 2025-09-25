# lstrcmpA function

## Description

Compares two character strings. The comparison is case-sensitive.

To perform a comparison that is not case-sensitive, use the [lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia) function.

## Parameters

### `lpString1` [in]

Type: **LPCTSTR**

The first null-terminated string to be compared.

### `lpString2` [in]

Type: **LPCTSTR**

The second null-terminated string to be compared.

## Return value

Type: **int**

If the string pointed to by
*lpString1* is less than the string pointed to by
*lpString2*, the return value is negative. If the string pointed to by
*lpString1* is greater than the string pointed to by
*lpString2*, the return value is positive. If the strings are equal, the return value is zero.

## Remarks

The **lstrcmp** function compares two strings by checking the first characters against each other, the second characters against each other, and so on until it finds an inequality or reaches the ends of the strings.

 Note that the *lpString1* and *lpString2* parameters must be null-terminated, otherwise the string comparison can be incorrect.

The function calls [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex), using the current thread locale, and subtracts 2 from the result, to maintain the C run-time conventions for comparing strings.

The language (user locale) selected by the user at setup time, or through Control Panel, determines which string is greater (or whether the strings are the same). If no language (user locale) is selected, the system performs the comparison by using default values.

With a double-byte character set (DBCS) version of the system, this function can compare two DBCS strings.

The **lstrcmp** function uses a word sort, rather than a string sort. A word sort treats hyphens and apostrophes differently than it treats other symbols that are not alphanumeric, in order to ensure that words such as "coop" and "co-op" stay together within a sorted list. For a detailed discussion of word sorts and string sorts, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications).

### Security Remarks

See [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features) for security considerations regarding choice of comparison functions.

> [!NOTE]
> The winbase.h header defines lstrcmp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex)

[CompareStringOrdinal](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringordinal)

**Conceptual**

**Other Resources**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[lstrcat](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcata)

[lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia)

[lstrcpy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcpya)

[lstrlen](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrlena)