## Description

Shaping output properties per input character.

## Members

### `isShapedAlone`

Type: **UINT16**

Indicates that the character is shaped independently from the others (usually set for the space character).

### `reserved1`

Reserved for use by shaping engine.

### `canBreakShapingAfter`

Glyph shaping can be safely cut after this point without affecting shaping before or after it. Otherwise, splitting a call to [GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs) would cause a reflow of glyph advances and shapes.

### `reserved`

Reserved for use by the shaping engine.

Type: **UINT16**

Reserved for future use.