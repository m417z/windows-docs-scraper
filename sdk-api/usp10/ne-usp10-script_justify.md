# SCRIPT_JUSTIFY enumeration

## Description

Defines glyph characteristic information that an application needs to implement justification.

## Constants

### `SCRIPT_JUSTIFY_NONE:0`

Justification cannot be applied at the glyph.

### `SCRIPT_JUSTIFY_ARABIC_BLANK:1`

The glyph represents a blank in an Arabic run.

### `SCRIPT_JUSTIFY_CHARACTER:2`

An inter-character justification point follows the glyph.

### `SCRIPT_JUSTIFY_RESERVED1:3`

Reserved.

### `SCRIPT_JUSTIFY_BLANK:4`

The glyph represents a blank outside an Arabic run.

### `SCRIPT_JUSTIFY_RESERVED2:5`

Reserved.

### `SCRIPT_JUSTIFY_RESERVED3:6`

Reserved.

### `SCRIPT_JUSTIFY_ARABIC_NORMAL:7`

Normal middle-of-word glyph that connects to the right (begin).

### `SCRIPT_JUSTIFY_ARABIC_KASHIDA:8`

Kashida (U+0640) in the middle of the word.

### `SCRIPT_JUSTIFY_ARABIC_ALEF:9`

Final form of an alef-like (U+0627, U+0625, U+0623, U+0622).

### `SCRIPT_JUSTIFY_ARABIC_HA:10`

Final form of Ha (U+0647).

### `SCRIPT_JUSTIFY_ARABIC_RA:11`

Final form of Ra (U+0631).

### `SCRIPT_JUSTIFY_ARABIC_BA:12`

Final form of Ba (U+0628).

### `SCRIPT_JUSTIFY_ARABIC_BARA:13`

Ligature of alike (U+0628,U+0631).

### `SCRIPT_JUSTIFY_ARABIC_SEEN:14`

Highest priority: initial shape of Seen class (U+0633).

### `SCRIPT_JUSTIFY_ARABIC_SEEN_M:15`

Highest priority: medial shape of Seen class (U+0633).

## See also

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Enumeration Types](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-enumeration-types)