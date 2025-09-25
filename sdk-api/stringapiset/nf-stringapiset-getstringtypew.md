# GetStringTypeW function

## Description

> [!NOTE]
> This API may have incomplete/outdated information for certain Unicode characters, particularly those in the supplementary range. For more accurate and comprehensive Unicode character type information, consider using equivalent ICU APIs such as [u_charType](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#a53f7567680cb6d92489d6e7750c90284), [u_islower](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#a65980f5668ed1df7f183a090f62b0e61), [u_isspace](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#a48dd198b451e691cf81eb41831474ddc), and [u_ispunct](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#add0409f1e6cbbc84dda50c45cc3e7302). For guidance on using ICU APIs on Windows, see [Getting Started with ICU on Windows](https://learn.microsoft.com/windows/win32/intl/international-components-for-unicode--icu-#getting-started).

Retrieves character type information for the characters in the specified Unicode source string. For each character in the string, the function sets one or more bits in the corresponding 16-bit element of the output array. Each bit identifies a given character type, for example, letter, digit, or neither.

**Caution** Using the **GetStringTypeW** function incorrectly can compromise the security of your application. To avoid a buffer overflow, the application must set the output buffer size correctly. For more security information, see [Security Considerations: Windows User Interface](https://learn.microsoft.com/windows/desktop/AppUIStart/sec-ui).

## Parameters

### `dwInfoType` [in]

Flags specifying the character type information to retrieve. This parameter can have the following values. The character types are divided into different levels as described in the Remarks section.

| Flag | Meaning |
| --- | --- |
| **CT_CTYPE1** | Retrieve character type information. |
| **CT_CTYPE2** | Retrieve bidirectional layout information. |
| **CT_CTYPE3** | Retrieve text processing information. |

### `lpSrcStr` [in]

Pointer to the Unicode string for which to retrieve the character types. The string is assumed to be null-terminated if *cchSrc* is set to any negative value.

### `cchSrc` [in]

Size, in characters, of the string indicated by *lpSrcStr*. If the size includes a terminating null character, the function retrieves character type information for that character. If the application sets the size to any negative integer, the source string is assumed to be null-terminated and the function calculates the size automatically with an additional character for the null termination.

### `lpCharType` [out]

Pointer to an array of 16-bit values. The length of this array must be large enough to receive one 16-bit value for each character in the source string. If *cchSrc* is not a negative number, *lpCharType* should be an array of words with *cchSrc* elements. If *cchSrc* is set to a negative number, *lpCharType* is an array of words with *lpSrcStr* + 1 elements. When the function returns, this array contains one word corresponding to each character in the source string.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

For an overview of the use of the string functions, see [Strings](https://learn.microsoft.com/windows/desktop/menurc/strings).

The values of the *lpSrcStr* and *lpCharType* parameters must not be the same. If they are the same, the function fails with ERROR_INVALID_PARAMETER.

The *Locale* parameter used by the corresponding [GetStringTypeA](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getstringtypea) function is not used by this function. Because of the parameter difference, an application cannot automatically invoke the proper ANSI or Unicode version of a **GetStringType*** function through the use of the #define UNICODE switch. An application can circumvent this limitation by using [GetStringTypeEx](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-getstringtypeexw), which is the recommended function.

**Supported Character Types**

The character type bits are divided into several levels. The information for one level can be retrieved by a single call to this function. Each level is limited to 16 bits of information so that the other mapping functions, which are limited to 16 bits of representation per character, can also return character type information.

Ctype 1

These types support ANSI C and POSIX (LC_CTYPE) character typing functions. A bitwise-OR of these values is retrieved in the array in the output buffer when *dwInfoType* is set to CT_CTYPE1. For DBCS locales, the type attributes apply to both narrow characters and wide characters. The Japanese hiragana and katakana characters, and the kanji ideograph characters all have the C1_ALPHA attribute.

| Name | Value | Meaning |
| --- | --- | --- |
| C1_UPPER | 0x0001 | Uppercase |
| C1_LOWER | 0x0002 | Lowercase |
| C1_DIGIT | 0x0004 | Decimal digits |
| C1_SPACE | 0x0008 | Space characters |
| C1_PUNCT | 0x0010 | Punctuation |
| C1_CNTRL | 0x0020 | Control characters |
| C1_BLANK | 0x0040 | Blank characters |
| C1_XDIGIT | 0x0080 | Hexadecimal digits |
| C1_ALPHA | 0x0100 | Any linguistic character: alphabetical, syllabary, or ideographic |
| C1_DEFINED | 0x0200 | A defined character, but not one of the other C1_* types |

The following character types are either constant or computable from basic types and do not need to be supported by this function.

| Type | Description |
| --- | --- |
| Alphanumeric | Alphabetical characters and digits (C1_ALPHA and C1_DIGIT) |
| Printable | Graphic characters and blanks (all C1_* types except C1_CNTRL) |

Ctype 2

These types support proper layout of Unicode text. For DBCS locales, the character type applies to both narrow and wide characters. The direction attributes are assigned so that the bidirectional layout algorithm standardized by Unicode produces accurate results. These types are mutually exclusive. For more information about the use of these attributes, see [The Unicode Standard](https://www.unicode.org/standard/standard.html).

| Name | Value | Meaning |
| --- | --- | --- |
| Strong |  |  |
| C2_LEFTTORIGHT | 0x0001 | Left to right |
| C2_RIGHTTOLEFT | 0x0002 | Right to left |
| Weak |  |  |
| C2_EUROPENUMBER | 0x0003 | European number, European digit |
| C2_EUROPESEPARATOR | 0x0004 | European numeric separator |
| C2_EUROPETERMINATOR | 0x0005 | European numeric terminator |
| C2_ARABICNUMBER | 0x0006 | Arabic number |
| C2_COMMONSEPARATOR | 0x0007 | Common numeric separator |
| Neutral |  |  |
| C2_BLOCKSEPARATOR | 0x0008 | Block separator |
| C2_SEGMENTSEPARATOR | 0x0009 | Segment separator |
| C2_WHITESPACE | 0x000A | White space |
| C2_OTHERNEUTRAL | 0x000B | Other neutrals |
| Not applicable |  |  |
| C2_NOTAPPLICABLE | 0x0000 | No implicit directionality (for example, control codes) |

Ctype 3

These types are intended to be placeholders for extensions to the POSIX types required for general text processing or for the standard C library functions. A bitwise-OR of these values is retrieved when *dwInfoType* is set to CT_CTYPE3. For DBCS locales, the Ctype 3 attributes apply to both narrow characters and wide characters. The Japanese hiragana and katakana characters, and the kanji ideograph characters all have the C3_ALPHA attribute.

| Name | Value | Meaning |
| --- | --- | --- |
| C3_NONSPACING | 0x0001 | Nonspacing mark |
| C3_DIACRITIC | 0x0002 | Diacritic nonspacing mark |
| C3_VOWELMARK | 0x0004 | Vowel nonspacing mark |
| C3_SYMBOL | 0x0008 | Symbol |
| C3_KATAKANA | 0x0010 | Katakana character |
| C3_HIRAGANA | 0x0020 | Hiragana character |
| C3_HALFWIDTH | 0x0040 | Half-width (narrow) character |
| C3_FULLWIDTH | 0x0080 | Full-width (wide) character |
| C3_IDEOGRAPH | 0x0100 | Ideographic character |
| C3_KASHIDA | 0x0200 | Arabic kashida character |
| C3_LEXICAL | 0x0400 | Punctuation which is counted as part of the word (kashida, hyphen, feminine/masculine ordinal indicators, equal sign, and so forth) |
| C3_ALPHA | 0x8000 | All linguistic characters (alphabetical, syllabary, and ideographic) |
| C3_HIGHSURROGATE | 0x0800 | **Windows Vista:** High surrogate code unit |
| C3_LOWSURROGATE | 0x1000 | **Windows Vista:** Low surrogate code unit |
| Not applicable |  |  |
| C3_NOTAPPLICABLE | 0x0000 | Not applicable |

C3_HIGHSURROGATE and C3_LOWSURROGATE are listed only for completeness, and should never be provided to this function. They are relevant only for Unicode.

**Starting with Windows 8:** **GetStringTypeW** is declared in Stringapiset.h. Before Windows 8, it was declared in Winnls.h.

## See also

[GetStringTypeA](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getstringtypea)

[GetStringTypeEx](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-getstringtypeexw)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)