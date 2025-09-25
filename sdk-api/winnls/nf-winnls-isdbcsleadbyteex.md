# IsDBCSLeadByteEx function

## Description

Determines if a specified character is potentially a lead byte. A lead byte is the first byte of a two-byte character in a [double-byte character set](https://learn.microsoft.com/windows/desktop/Intl/double-byte-character-sets) (DBCS) for the code page.

## Parameters

### `CodePage` [in]

Identifier of the code page used to check lead byte ranges. This parameter can be one of the code page identifiers defined in [Unicode and Character Set Constants](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-constants) or one of the following predefined values. This function validates lead byte values only in code pages 932, 936, 949, 950, and 1361.

| Value | Meaning |
| --- | --- |
| **CP_ACP** | Use system default Windows ANSI code page. |
| **CP_MACCP** | Use the system default Macintosh code page. |
| **CP_OEMCP** | Use system default OEM code page. |
| **CP_THREAD_ACP** | Use the Windows ANSI code page for the current thread. |

### `TestChar` [in]

The character to test.

## Return value

Returns a nonzero value if the byte is a lead byte. The function returns 0 if the byte is not a lead byte or if the character is a single-byte character. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** This function does not validate the presence or validity of a trail byte. Therefore, [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) might not recognize a sequence that the application using [IsDBCSLeadByte](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isdbcsleadbyte) reports as a lead byte. The application can easily become unsynchronized with the results of **MultiByteToWideChar**, potentially leading to unexpected errors or buffer size mismatches.

In general, instead of attempting low-level manipulation of code page data, applications should use [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) to convert the data to UTF-16 and work with it in that encoding.

Lead byte values are specific to each distinct DBCS. Some byte values can appear in a single code page as both the lead and trail byte of a DBCS character. Thus, **IsDBCSLeadByteEx** can only indicate a potential lead byte value.

To make sense of a DBCS string, an application normally starts at the beginning of the string and scans forward, keeping track when it encounters a lead byte, and treating the next byte as the trailing part of the same character. To back up, the application should use [CharPrevExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charprevexa) instead of attempting to develop its own algorithm.

## See also

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)

[WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte)