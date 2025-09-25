# IsDBCSLeadByte function

## Description

Determines if a specified character is a lead byte for the system default Windows ANSI code page
(**CP_ACP**). A lead byte is the first byte of a two-byte character in a
[double-byte character set](https://learn.microsoft.com/windows/desktop/Intl/double-byte-character-sets) (DBCS) for the code
page.

**Note** To use a different code page, your application should use the
[IsDBCSLeadByteEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isdbcsleadbyteex) function.

## Parameters

### `TestChar` [in]

The character to test.

## Return value

Returns a nonzero value if the test character is potentially a lead byte. The function returns 0 if the test
character is not a lead byte or if it is a single-byte character. To get extended error information, the
application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** This function does not validate the presence or validity of a trail byte. Therefore,
[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) might not recognize a
sequence that the application using **IsDBCSLeadByte**
reports as a lead byte. The application can easily become unsynchronized with the results of
**MultiByteToWideChar**, potentially leading to
unexpected errors or buffer size mismatches.

In general, instead of attempting low-level manipulation of code page data, applications should use
[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) to convert the
data to UTF-16 and work with it in that encoding.

Lead byte values are specific to each distinct DBCS. Some byte values can appear in a single code page as both
the lead and trail byte of a DBCS character.

To make sense of a DBCS string, an application normally starts at the beginning of a string and scans forward,
keeping track when it encounters a lead byte, and treating the next byte as the trailing part of the same
character. If the application must back up, it should use
[CharPrev](https://learn.microsoft.com/windows/desktop/menurc/v) instead of attempting to develop its own
algorithm.

## See also

[IsDBCSLeadByteEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isdbcsleadbyteex)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)