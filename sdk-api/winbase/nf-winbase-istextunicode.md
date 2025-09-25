# IsTextUnicode function

## Description

Determines if a buffer is likely to contain a form of Unicode text.

## Parameters

### `lpv` [in]

Pointer to the input buffer to examine.

### `iSize` [in]

Size, in bytes, of the input buffer indicated by *lpv*.

### `lpiResult` [in, out, optional]

On input, pointer to the tests to apply to the input buffer text. On output, this parameter receives the results of the specified tests: 1 if the contents of the buffer pass a test, 0 for failure. Only flags that are set upon input to the function are significant upon output.

If *lpiResult* is **NULL**, the function uses all available tests to determine if the data in the buffer is likely to be Unicode text.

This parameter can be one or more of the following values. Values can be combined with binary "OR".

| Value | Meaning |
| --- | --- |
| **IS_TEXT_UNICODE_ASCII16** | The text is Unicode, and contains only zero-extended ASCII values/characters. |
| **IS_TEXT_UNICODE_REVERSE_ASCII16** | Same as the preceding, except that the Unicode text is byte-reversed. |
| **IS_TEXT_UNICODE_STATISTICS** | The text is probably Unicode, with the determination made by applying statistical analysis. Absolute certainty is not guaranteed. See the Remarks section. |
| **IS_TEXT_UNICODE_REVERSE_STATISTICS** | Same as the preceding, except that the text that is probably Unicode is byte-reversed. |
| **IS_TEXT_UNICODE_CONTROLS** | The text contains Unicode representations of one or more of these nonprinting characters: RETURN, LINEFEED, SPACE, CJK_SPACE, TAB. |
| **IS_TEXT_UNICODE_REVERSE_CONTROLS** | Same as the preceding, except that the Unicode characters are byte-reversed. |
| **IS_TEXT_UNICODE_BUFFER_TOO_SMALL** | There are too few characters in the buffer for meaningful analysis (fewer than two bytes). |
| **IS_TEXT_UNICODE_SIGNATURE** | The text contains the Unicode byte-order mark (BOM) 0xFEFF as its first character. |
| **IS_TEXT_UNICODE_REVERSE_SIGNATURE** | The text contains the Unicode byte-reversed byte-order mark (Reverse BOM) 0xFFFE as its first character. |
| **IS_TEXT_UNICODE_ILLEGAL_CHARS** | The text contains one of these Unicode-illegal characters: embedded Reverse BOM, UNICODE_NUL, CRLF (packed into one word), or 0xFFFF. |
| **IS_TEXT_UNICODE_ODD_LENGTH** | The number of characters in the string is odd. A string of odd length cannot (by definition) be Unicode text. |
| **IS_TEXT_UNICODE_NULL_BYTES** | The text contains null bytes, which indicate non-ASCII text. |
| **IS_TEXT_UNICODE_UNICODE_MASK** | The value is a combination of IS_TEXT_UNICODE_ASCII16, IS_TEXT_UNICODE_STATISTICS, IS_TEXT_UNICODE_CONTROLS, IS_TEXT_UNICODE_SIGNATURE. |
| **IS_TEXT_UNICODE_REVERSE_MASK** | The value is a combination of IS_TEXT_UNICODE_REVERSE_ASCII16, IS_TEXT_UNICODE_REVERSE_STATISTICS, IS_TEXT_UNICODE_REVERSE_CONTROLS, IS_TEXT_UNICODE_REVERSE_SIGNATURE. |
| **IS_TEXT_UNICODE_NOT_UNICODE_MASK** | The value is a combination of IS_TEXT_UNICODE_ILLEGAL_CHARS, IS_TEXT_UNICODE_ODD_LENGTH, and two currently unused bit flags. |
| **IS_TEXT_UNICODE_NOT_ASCII_MASK** | The value is a combination of IS_TEXT_UNICODE_NULL_BYTES and three currently unused bit flags. |

## Return value

Returns a nonzero value if the data in the buffer passes the specified tests. The function returns 0 if the data in the buffer does not pass the specified tests.

## Remarks

This function uses various statistical and deterministic methods to make its determination, under the control of flags passed in the *lpiResult* parameter. When the function returns, the results of such tests are reported using the same parameter.

The IS_TEXT_UNICODE_STATISTICS and IS_TEXT_UNICODE_REVERSE_STATISTICS tests use statistical analysis. These tests are not foolproof. The statistical tests assume certain amounts of variation between low and high bytes in a string, and some ASCII strings can slip through. For example, if *lpv* indicates the ASCII string 0x41, 0x0A, 0x0D, 0x1D (A\n\r^Z), the string passes the IS_TEXT_UNICODE_STATISTICS test, although failure would be preferable.

## See also

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)