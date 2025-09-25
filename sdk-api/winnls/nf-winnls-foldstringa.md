# FoldStringA function

## Description

Maps one Unicode string to another, performing the specified transformation. For an overview of the use of the string functions, see [Strings](https://learn.microsoft.com/windows/desktop/menurc/strings).

**Caution** Using **FoldString** incorrectly can compromise the security of your application. Strings that are not mapped correctly can produce invalid input. Test strings to make sure they are valid before using them and provide error handlers. For more information, see [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features).

## Parameters

### `dwMapFlags` [in]

Flags specifying the type of transformation to use during string mapping. This parameter can be a combination of the following values.

| Flag | Meaning |
| --- | --- |
| **MAP_COMPOSITE** | Map accented characters to decomposed characters, that is, characters in which a base character and one or more nonspacing characters each have distinct code point values. For example, Ä is represented by A + ¨: LATIN CAPITAL LETTER A (U+0041) + COMBINING DIAERESIS (U+0308). This flag is equivalent to normalization form D in Windows Vista. Note that this flag cannot be used with MB_PRECOMPOSED. |
| **MAP_EXPAND_LIGATURES** | Expand all ligature characters so that they are represented by their two-character equivalent. For example, the ligature "æ" (U+00e6) expands to the two characters "a" (U+0061) + "e" (U+0065). This value cannot be combined with MAP_PRECOMPOSED or MAP_COMPOSITE. |
| **MAP_FOLDCZONE** | Fold compatibility zone characters into standard Unicode equivalents. This flag is equivalent to normalization form KD in Windows Vista, if the MAP_COMPOSITE flag is also set. If the composite flag is not set (default), this flag is equivalent to normalization form KC in Windows Vista. |
| **MAP_FOLDDIGITS** | Map all digits to Unicode characters 0 through 9. |
| **MAP_PRECOMPOSED** | Map accented characters to precomposed characters, in which the accent and base character are combined into a single character value. This flag is equivalent to normalization form C in Windows Vista. This value cannot be combined with MAP_COMPOSITE. |

### `lpSrcStr` [in]

Pointer to a source string that the function maps.

### `cchSrc` [in]

Size, in characters, of the source string indicated by *lpSrcStr*, excluding the terminating null character. The application can set the parameter to any negative value to specify that the source string is null-terminated. In this case, the function calculates the string length automatically, and null-terminates the mapped string indicated by *lpDestStr*.

### `lpDestStr` [out, optional]

Pointer to a buffer in which this function retrieves the mapped string.

### `cchDest` [in]

Size, in characters, of the destination string indicated by *lpDestStr*. If space for a terminating null character is included in *cchSrc*, *cchDest* must also include space for a terminating null character.

The application can set *cchDest* to 0. In this case, the function does not use the *lpDestStr* parameter and returns the required buffer size for the mapped string. If the MAP_FOLDDIGITS flag is specified, the return value is the maximum size required, even if the actual number of characters needed is smaller than the maximum size. If the maximum size is not passed, the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

Returns the number of characters in the translated string, including a terminating null character, if successful. If the function succeeds and the value of *cchDest* is 0, the return value is the size of the buffer required to hold the translated string, including a terminating null character.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_DATA. The data was invalid.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_MOD_NOT_FOUND. The module was not found.
* ERROR_OUTOFMEMORY. Not enough storage was available to complete this operation.
* ERROR_PROC_NOT_FOUND. The required procedure was not found.

## Remarks

The values of the *lpSrcStr* and *lpDestStr* parameters must not be the same. If they are the same, the function fails with ERROR_INVALID_PARAMETER.

The compatibility zone in Unicode consists of characters in the range 0xF900 through 0xFFEF that are assigned to characters from other encoding standards for characters but are actually variants of characters already in Unicode. The compatibility zone is used to support round-trip mapping to these standards. Applications can use the MAP_FOLDCZONE flag to avoid supporting the duplication of characters in the compatibility zone.

**Starting with Windows Vista:** This function supports Unicode normalization. All Unicode compatibility characters are mapped.

**Starting with Windows Vista:** The transformations indicated by the MAP_FOLDCZONE, MAP_PRECOMPOSED, and MAP_COMPOSITE flags use Unicode normalization forms KC, C, and D (through the [NormalizeString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-normalizestring) function) to do the mappings.

**Starting with Windows 8:** The ANSI version of the function is declared in Winnls.h and the Unicode version is declared in Stringapiset.h. Before Windows 8, both versions were declared in Winnls.h.

## See also

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[NormalizeString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-normalizestring)

[Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features)

[Sorting](https://learn.microsoft.com/windows/desktop/Intl/sorting)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)