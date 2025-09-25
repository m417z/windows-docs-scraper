# DWRITE_WORD_WRAPPING enumeration

## Description

Specifies the word wrapping to be used in a particular multiline paragraph.

**Note** **DWRITE_WORD_WRAPPING_EMERGENCY_BREAK**, **DWRITE_WORD_WRAPPING_WHOLE _WORD**, and **DWRITE_WORD_WRAPPING_CHARACTER** are available in Windows 8.1 and later, only.

## Constants

### `DWRITE_WORD_WRAPPING_WRAP:0`

Indicates that words are broken across lines to avoid text overflowing the layout box.

### `DWRITE_WORD_WRAPPING_NO_WRAP:1`

Indicates that words are kept within the same line even when it overflows the layout box. This option is often used with scrolling to reveal overflow text.

### `DWRITE_WORD_WRAPPING_EMERGENCY_BREAK:2`

**Note** Windows 8.1 and later only.

Words are broken across lines to avoid text overflowing the layout box.
Emergency wrapping occurs if the word is larger than the maximum width.

### `DWRITE_WORD_WRAPPING_WHOLE_WORD:3`

**Note** Windows 8.1 and later only.

When emergency wrapping, only wrap whole words, never breaking words when the layout width is too small for even a single word.

### `DWRITE_WORD_WRAPPING_CHARACTER:4`

**Note** Windows 8.1 and later only.

Wrap between any valid character clusters.