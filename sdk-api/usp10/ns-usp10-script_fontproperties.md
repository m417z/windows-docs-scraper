# SCRIPT_FONTPROPERTIES structure

## Description

Contains information about the properties of the current font.

## Members

### `cBytes`

Size, in bytes, of the structure.

### `wgBlank`

Glyph used to indicate a blank.

### `wgDefault`

Glyph used to indicate Unicode characters not present in the font.

### `wgInvalid`

Glyph used to indicate invalid character combinations.

### `wgKashida`

Glyph used to indicate the shortest continuous kashida, with 1 indicating that the font contains no kashida.

### `iKashidaWidth`

Width of the shortest continuous kashida glyph in the font, indicated by the **wgKashida** member.

## See also

[ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)