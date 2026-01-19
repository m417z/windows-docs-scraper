# DWRITE_LINE_BREAKPOINT structure

## Description

Line breakpoint characteristics of a character.

## Members

### `breakConditionBefore`

Type: **UINT8 : 2**

Indicates a breaking condition before the character, equivalent to [DWRITE_BREAK_CONDITION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_break_condition).

### `breakConditionAfter`

Type: **UINT8 : 2**

Indicates a breaking condition after the character, equivalent to [DWRITE_BREAK_CONDITION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_break_condition).

### `isWhitespace`

Type: **UINT8 : 1**

Indicates that the character is some form of whitespace, which may be meaningful for justification.

### `isSoftHyphen`

Type: **UINT8 : 1**

Indicates that the character is a soft hyphen, often used to indicate hyphenation points inside words.

### `padding`

Type: **UINT8 : 2**

Reserved for future use.

## See also

[DWRITE_BREAK_CONDITION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_break_condition)