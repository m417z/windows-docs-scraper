# TTVALIDATIONTESTSPARAMSEX structure

## Description

The **TTVALIDATIONTESTSPARAMSEX** structure contains parameters for testing a Microsoft OpenType font.

## Members

### `ulStructSize`

Size, in bytes, of this structure. The client should set this value to **sizeof**(TTVALIDATIONTESTSPARAMSEX).

### `lTestFromSize`

First character point size to test. This value is the smallest font size (lower bound) of the font sizes to test.

### `lTestToSize`

Last character point size to test. This value is the largest font size (upper bound) to test.

### `ulCharSet`

Flag specifying the character set of the font to validate. This flag can have one of the following values.

| Value | Description |
| --- | --- |
| CHARSET_UNICODE | Unicode character set, requiring 16-bit character encoding. |
| CHARSET_SYMBOL | Symbol character set, requiring 16-bit character encoding. |

### `usReserved1`

Currently not used.

### `usCharCodeCount`

If zero, test over all glyphs.

### `pulCharCodeSet`

Pointer to array of UCS-4 characters.

## See also

[TTRunValidationTestsEx](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttrunvalidationtestsex)

[TTVALIDATIONTESTSPARAMS](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttvalidationtestsparams)