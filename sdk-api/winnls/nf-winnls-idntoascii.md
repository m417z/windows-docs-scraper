## Description

Converts an internationalized domain name (IDN) or another internationalized label to a Unicode (wide character) representation of the ASCII string that represents the name in the Punycode transfer encoding syntax.

**Caution** This function implements the [RFC 3490: Internationalizing Domain Names in Applications (IDNA)](http://www.faqs.org/rfcs/rfc3490.html) standard algorithm for converting an IDN to Punycode. The standard introduces some security issues. One issue is that glyphs representing certain characters from different scripts might appear similar or even identical. For example, in many fonts, Cyrillic lowercase A ("а") is indistinguishable from Latin lowercase A ("a"). There is no way to tell visually that "example.com" and "exаmple.com" are two different domain names, one with a Latin lowercase A in the name, the other with a Cyrillic lowercase A. For more information about IDN-related security concerns, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

## Parameters

### `dwFlags` [in]

Flags specifying conversion options. The following table lists the possible values.

| Value | Meaning |
| --- | --- |
| **IDN_ALLOW_UNASSIGNED** | **Note** An application can set this value if it is just using a query string for normal lookup, as in a compare operation. However, the application should not set this value for a stored string, which is a string being prepared for storage.<br><br>Allow unassigned code points to be included in the input string. The default is to not allow unassigned code points, and fail with an extended error code of ERROR_INVALID_NAME.<br><br>This flag allows the function to process characters that are not currently legal in IDNs, but might be legal in later versions of the IDNA standard. If your application encodes unassigned code points as Punycode, the resulting domain names should be illegal. Security can be compromised if a later version of IDNA makes these names legal or if an application filters out the illegal characters to try to create a legal domain name. For more information, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns). |
| **IDN_USE_STD3_ASCII_RULES** | Filter out ASCII characters that are not allowed in STD3 names. The only ASCII characters allowed in the input Unicode string are letters, digits, and the hyphen-minus. The string cannot begin or end with the hyphen-minus. The function fails if the input Unicode string contains ASCII characters, such as "[", "]", or "/", that cannot occur in domain names.<br><br>**Note** Some local networks can allow some of these characters in computer names.<br><br>The function fails if the input Unicode string contains control characters (U+0001 through U+0020) or the "delete" character (U+007F). In either case, this flag has no effect on the non-ASCII characters that are allowed in the Unicode string. |
| **IDN_EMAIL_ADDRESS** | **Starting with Windows 8:** Enable EAI algorithmic fallback for the local parts of email addresses (such as *\<local>*@microsoft.com). The default is for this function to fail when an email address has an invalid address or syntax.<br><br>An application can set this flag to enable Email Address Internationalization (EAI) to return a discoverable fallback address, if possible. For more information, see the IETF [Email Address Internationalization (eai) Charter](https://datatracker.ietf.org/wg/eai/charter/). |
| **IDN_RAW_PUNYCODE** | **Starting with Windows 8:** Disable the validation and mapping of Punycode. |

### `lpUnicodeCharStr` [in]

Pointer to a Unicode string representing an IDN or another internationalized label.

### `cchUnicodeChar` [in]

Count of characters in the input Unicode string indicated by *lpUnicodeCharStr*.

### `lpASCIICharStr` [out, optional]

Pointer to a buffer that receives a Unicode string consisting only of characters in the ASCII character set. On return from this function, the buffer contains the ASCII string equivalent of the string provided in *lpUnicodeCharStr* under Punycode. Alternatively, the function can retrieve **NULL** for this parameter, if *cchASCIIChar* is set to 0. In this case, the function returns the size required for this buffer.

### `cchASCIIChar` [in]

Size of the buffer indicated by *lpASCIICharStr*. The application can set the parameter to 0 to retrieve **NULL** in *lpASCIICharStr*.

## Return value

Returns the number of characters retrieved in *lpASCIICharStr* if successful. The retrieved string is null-terminated only if the input Unicode string is null-terminated.

If the function succeeds and the value of *cchASCIIChar* is 0, the function returns the required size, in characters including a terminating null character if it was part of the input buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_NAME. An invalid name was supplied to the function. Note that this error code catches all syntax errors.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_NO_UNICODE_TRANSLATION. Invalid Unicode was found in a string.

## Remarks

The function does not null-terminate an output string if the input string length is explicitly specified without a terminating null character. To null-terminate an output string for this function, the application should supply -1 for the *cchUnicodeChar* parameter or explicitly count the terminating null character for the input string.

Note that the function always fails if the input string contains control characters (U+0001 through U+0020) or the "delete" character (U+007F). Since the character U+0000 can appear only as a terminating null character, the function always fails if U+0000 appears anywhere else in the input string.

**Windows XP, Windows Server 2003**:

No longer supported.

The required header file and DLL are part of the Microsoft Internationalized Domain Name (IDN) Mitigation APIs, which are no longer available for download.

## See also

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns)

[IdnToNameprepUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntonameprepunicode)

[IdnToUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntounicode)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)