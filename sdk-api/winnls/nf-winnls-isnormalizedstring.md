# IsNormalizedString function

## Description

Verifies that a string is normalized according to Unicode 4.0 TR#15. For more information, see [Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings).

## Parameters

### `NormForm` [in]

Normalization form to use. [NORM_FORM](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-norm_form) specifies the standard Unicode normalization forms.

### `lpString` [in]

Pointer to the string to test.

### `cwLength` [in]

Length, in characters, of the input string, including a null terminating character. If this value is -1, the function assumes the string to be null-terminated and calculates the length automatically.

## Return value

Returns **TRUE** if the input string is already normalized to the appropriate form, or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_NO_UNICODE_TRANSLATION. Invalid Unicode was found in string.
* ERROR_SUCCESS. The action completed successfully but yielded no results.

If you need to reliably determine **FALSE** from an error condition, then it must call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror)(ERROR_SUCCESS).

## Remarks

**Windows XP, Windows Server 2003**:

No longer supported.

The required header file and DLL are part of the Microsoft Internationalized Domain Name (IDN) Mitigation APIs, which are no longer available for download.

#### Examples

An example showing the use of this function can be found in [NLS: Unicode Normalization Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--unicode-normalization-sample).

## See also

[NORM_FORM](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-norm_form)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[NormalizeString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-normalizestring)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)