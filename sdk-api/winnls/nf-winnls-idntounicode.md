# IdnToUnicode function

## Description

Converts the Punycode form of an internationalized domain name (IDN) or another internationalized label to the normal [Unicode](https://learn.microsoft.com/windows/desktop/Intl/unicode) UTF-16 encoding syntax.

**Caution** This function implements the [RFC 3490: Internationalizing Domain Names in Applications (IDNA)](http://www.faqs.org/rfcs/rfc3490.html) standard algorithms for the Punycode encoding of Unicode. The standard introduces some security issues. One issue is that glyphs representing certain characters from different scripts might appear similar or even identical. For example, in many fonts, Cyrillic lowercase A ("а") is indistinguishable from Latin lowercase A ("a"). There is no way to tell visually that "example.com" and "exаmple.com" are two different domain names, one with a Latin lowercase A in the name, the other with a Cyrillic lowercase A. For more information about IDN-related security concerns, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

## Parameters

### `dwFlags` [in]

Flags specifying conversion options. For detailed definitions, see the *dwFlags* parameter of [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii).

### `lpASCIICharStr` [in]

Pointer to a string representing the Punycode encoding of an IDN or another internationalized label. This string must consist only of ASCII characters, and can include Punycode-encoded Unicode. The function decodes Punycode values to their UTF-16 values.

### `cchASCIIChar` [in]

Count of characters in the input string indicated by *lpASCIICharStr*.

### `lpUnicodeCharStr` [out, optional]

Pointer to a buffer that receives a normal Unicode UTF-16 encoding equivalent to the Punycode value of the input string. Alternatively, the function can retrieve **NULL** for this parameter, if *cchUnicodeChar* set to 0. In this case, the function returns the size required for this buffer.

### `cchUnicodeChar` [in]

Size, in characters, of the buffer indicated by *lpUnicodeCharStr*. The application can set the size to 0 to retrieve **NULL** in *lpUnicodeCharStr* and have the function return the required buffer size.

## Return value

Returns the number of characters retrieved in *lpUnicodeCharStr* if successful. The retrieved string is null-terminated only if the input string is null-terminated.

If the function succeeds and the value of *cchUnicodeChar* is 0, the function returns the required size, in characters including a terminating null character if it was part of the input buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_NAME. An invalid name was supplied to the function. Note that this error code catches all syntax errors.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_NO_UNICODE_TRANSLATION. Invalid Unicode was found in a string.

## Remarks

See Remarks for [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii).

## See also

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns)

[IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii)

[IdnToNameprepUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntonameprepunicode)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)