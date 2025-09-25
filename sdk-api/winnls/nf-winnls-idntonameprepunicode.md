# IdnToNameprepUnicode function

## Description

Converts an internationalized domain name (IDN) or another internationalized label to the NamePrep form specified by Network Working Group [RFC 3491](http://www.faqs.org/rfcs/rfc3491.html), but does not perform the additional conversion to Punycode. For more information and links to related draft standards, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

## Parameters

### `dwFlags` [in]

Flags specifying conversion options. For detailed definitions, see the *dwFlags* parameter of [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii).

### `lpUnicodeCharStr` [in]

Pointer to a Unicode string representing an IDN or another internationalized label.

### `cchUnicodeChar` [in]

Count of Unicode characters in the input Unicode string indicated by *lpUnicodeCharStr*.

### `lpNameprepCharStr` [out, optional]

Pointer to a buffer that receives a version of the input Unicode string converted through NamePrep processing. Alternatively, the function can retrieve **NULL** for this parameter, if *cchNameprepChar* is set to 0. In this case, the function returns the size required for this buffer.

### `cchNameprepChar` [in]

Size, in characters, of the buffer indicated by *lpNameprepCharStr*. The application can set the size to 0 to retrieve **NULL** in *lpNameprepCharStr* and have the function return the required buffer size.

## Return value

Returns the number of characters retrieved in *lpNameprepCharStr* if successful. The retrieved string is null-terminated only if the input Unicode string is null-terminated.

If the function succeeds and the value of *cchNameprepChar* is 0, the function returns the required size, in characters including a terminating null character if it was part of the input buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_NAME. An invalid name was supplied to the function. Note that this error code catches all syntax errors.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_NO_UNICODE_TRANSLATION. Invalid Unicode was found in a string.

## Remarks

See Remarks for [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii).

#### Examples

[NLS: Internationalized Domain Name (IDN) Conversion Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--internationalized-domain-name--idn--conversion-sample) demonstrates the use of this function.

## See also

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns)

[IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii)

[IdnToUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntounicode)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)