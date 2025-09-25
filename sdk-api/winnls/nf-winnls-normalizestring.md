# NormalizeString function

## Description

Normalizes characters of a text string according to Unicode 4.0 TR#15. For more information, see [Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings).

## Parameters

### `NormForm` [in]

Normalization form to use. [NORM_FORM](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-norm_form) specifies the standard Unicode normalization forms.

### `lpSrcString` [in]

Pointer to the non-normalized source string.

### `cwSrcLength` [in]

Length, in characters, of the buffer containing the source string. The application can set this parameter to -1 if the function should assume the string to be null-terminated and calculate the length automatically.

### `lpDstString` [out, optional]

Pointer to a buffer in which the function retrieves the destination string. Alternatively, this parameter contains **NULL** if *cwDstLength* is set to 0.

**Note** The function does not null-terminate the string if the input string length is explicitly specified without a terminating null character. To null-terminate the output string, the application should specify -1 or explicitly count the terminating null character for the input string.

### `cwDstLength` [in]

Length, in characters, of the buffer containing the destination string. Alternatively, the application can set this parameter to 0 to request the function to return the required size for the destination buffer.

## Return value

Returns the length of the normalized string in the destination buffer. If *cwDstLength* is set to 0, the function returns the estimated buffer length required to do the actual conversion.

If the string in the input buffer is null-terminated or if *cwSrcLength* is -1, the string written to the destination buffer is null-terminated and the returned string length includes the terminating null character.

The function returns a value that is less than or equal to 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_NO_UNICODE_TRANSLATION. Invalid Unicode was found in a string. The return value is the negative of the index of the location of the error in the input string.
* ERROR_SUCCESS. The action completed successfully but yielded no results.

## Remarks

Some Unicode characters have multiple equivalent binary representations consisting of sets of combining and/or composite Unicode characters. The Unicode standard defines a process called normalization that returns one binary representation when given any of the equivalent binary representations of a character. Normalization can be performed with several algorithms, called normalization forms, that obey different rules, as described in [Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings). The Win32 and the .NET Framework currently support normalization forms C, D, KC, and KD, as defined in [Unicode Standard Annex #15: Unicode Normalization Forms](https://www.unicode.org/reports/tr15). Normalized strings are typically evaluated with an ordinal comparison.

The following code demonstrates the use of the buffer length estimate:

```cpp
const int maxIterations = 10;
LPWSTR strResult = NULL;
HANDLE hHeap = GetProcessHeap();

int iSizeEstimated = NormalizeString(form, strInput, -1, NULL, 0);
for (int i = 0; i < maxIterations; i++)
{
    if (strResult)
        HeapFree(hHeap, 0, strResult);
    strResult = (LPWSTR)HeapAlloc(hHeap, 0, iSizeEstimated * sizeof (WCHAR));
    iSizeEstimated = NormalizeString(form, strInput, -1, strResult, iSizeEstimated);

    if (iSizeEstimated > 0)
        break; // success

    if (iSizeEstimated <= 0)
    {
        DWORD dwError = GetLastError();
        if (dwError != ERROR_INSUFFICIENT_BUFFER) break; // Real error, not buffer error

        // New guess is negative of the return value.
        iSizeEstimated = -iSizeEstimated;
    }
}

```

**Windows XP, Windows Server 2003**:

No longer supported.

The required header file and DLL are part of the Microsoft Internationalized Domain Name (IDN) Mitigation APIs, which are no longer available for download.

#### Examples

An example showing the use of this function can be found in [NLS: Unicode Normalization Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--unicode-normalization-sample).

## See also

[IsNormalizedString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isnormalizedstring)

[NORM_FORM](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-norm_form)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)