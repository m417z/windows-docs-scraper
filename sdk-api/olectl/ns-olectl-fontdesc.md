# FONTDESC structure

## Description

Contains parameters used to create a font object through the [OleCreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatefontindirect) function.

## Members

### `cbSizeofstruct`

The size of the structure, in bytes.

### `lpstrName`

Pointer to an [OLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr) that specifies the caller-owned string specifying the font name.

cySize

### `cySize`

Initial point size of the font. Use the **int64** member of the [CY](https://learn.microsoft.com/windows/win32/api/wtypes/ns-wtypes-cy-r1) structure and scale your font size (in points) by 10000.

### `sWeight`

Initial weight of the font. If the weight is below 550 (the average of FW_NORMAL, 400, and FW_BOLD, 700), then the **Bold** property is also initialized to **FALSE**. If the weight is above 550, the **Bold** property is set to **TRUE**.

### `sCharset`

Initial character set of the font.

### `fItalic`

Initial italic state of the font.

### `fUnderline`

Initial underline state of the font.

### `fStrikethrough`

Initial strikethrough state of the font.

## See also

[OleCreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatefontindirect)