# GetStringScripts function

## Description

Provides a list of scripts used in the specified Unicode string.

## Parameters

### `dwFlags` [in]

Flags specifying options for script retrieval.

| Value | Meaning |
| --- | --- |
| **GSS_ALLOW_INHERITED_COMMON** | Retrieve "Qaii" (INHERITED) and "Zyyy" (COMMON) script information. This flag does not affect the processing of unassigned characters. These characters in the input string always cause a "Zzzz" (UNASSIGNED script) to appear in the script string. |

**Note** By default, **GetStringScripts** ignores any inherited or common characters in the input string indicated by *lpString*. If GSS_ALLOW_INHERITED_COMMON is not set, neither "Qaii" nor "Zyyy" appears in the script string, even if the input string contains such characters. If GSS_ALLOW_INHERITED_COMMON is set, and if the input string contains inherited and/or common characters, "Qaii" and/or "Zyyy", respectively, appear in the script string. See the Remarks section.

### `lpString` [in]

Pointer to the Unicode string to analyze.

### `cchString` [in]

Size, in characters, of the Unicode string indicated by *lpString*. The application sets this parameter to -1 if the Unicode string is null-terminated. If the application sets this parameter to 0, the function retrieves a null Unicode string (L"\0") in *lpScripts* and returns 1.

### `lpScripts` [out, optional]

Pointer to a buffer in which this function retrieves a null-terminated string representing a list of scripts, using the 4-character notation used in [ISO 15924](http://www.unicode.org/iso15924/iso15924-codes.html). Each script name consists of four Latin characters, and the names are retrieved in alphabetical order. Each name, including the last, is followed by a semicolon.

Alternatively, this parameter contains **NULL** if *cchScripts* is set to 0. In this case, the function returns the required size for the script buffer.

### `cchScripts` [in]

Size, in characters, of the script buffer indicated by *lpScripts*.

Alternatively, the application can set this parameter to 0. In this case, the function retrieves **NULL** in *lpScripts* and returns the required size for the script buffer.

## Return value

Returns the number of characters retrieved in the output buffer, including a terminating null character, if successful and *cchScripts* is set to a nonzero value. The function returns 1 to indicate that no script has been found, for example, when the input string only contains COMMON or INHERITED characters and GSS_ALLOW_INHERITED_COMMON is not set. Given that each found script adds five characters (four characters + delimiter), a simple mathematical operation provides the script count as (return_code - 1) / 5.

If the function succeeds and the value of *cchScripts* is 0, the function returns the required size, in characters including a terminating null character, for the script buffer. The script count is as described above.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function is useful as part of a strategy to mitigate security issues related to [internationalized domain names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

The script determination is based on the script values published by the Unicode Consortium in \<http://www.unicode.org/Public/4.1.0/ucd/Scripts.txt>, except that the unassigned characters have the value "Zzzz" (UNASSIGNED) instead of "Zyyy" (COMMON).

Here are some examples of the behavior of this function:

| Input string | | *dwFlags* | *lpScripts* | Scripts |
| --- | --- | --- | --- | --- |
| Microsoft.com | | 0 | Latn; | Latin |
| Microsoft.com | | GSS_ALLOW_INHERITED_COMMON | Latn;Zyyy; | Latin + Common |
| Niño | 004E 0069 0241 006F | GSS_ALLOW_INHERITED_COMMON | Latn; | Latin |
| Uses LATIN SMALL LETTER N WITH TILDE |
| Niño | 004E 0069 006E 0303 006F | GSS_ALLOW_INHERITED_COMMON | Latn;Qaii; | Latin + Inherited |
| Uses COMBINING TILDE |
| Spооf | 0053 0070 043e 043e 0066 | 0 | Latn;Cyrl; | Latin + Cyrillic |
| Uses CYRILLIC SMALL LETTER O |
|  | U+f000 | 0 | Zzzz; | Unassigned |
|  | U+f000 | GSS_ALLOW_INHERITED_COMMON | Zzzz; | Unassigned |

## See also

[DownlevelGetStringScripts](https://learn.microsoft.com/windows/desktop/Intl/downlevelgetstringscripts)

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[VerifyScripts](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-verifyscripts)