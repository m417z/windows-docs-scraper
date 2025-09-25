# DWRITE_LINE_BREAKPOINT structure

## Description

Line breakpoint characteristics of a character.

## Members

### `breakConditionBefore`

Type: **UINT8**

Indicates a breaking condition before the character.

### `breakConditionAfter`

Type: **UINT8**

Indicates a breaking condition after the character.

### `isWhitespace`

Type: **UINT8**

Indicates that the character is some form of whitespace, which may be meaningful for justification.

### `isSoftHyphen`

Type: **UINT8**

Indicates that the character is a soft hyphen, often used to indicate hyphenation points inside words.

### `padding`

Type: **UINT8**

Reserved for future use.