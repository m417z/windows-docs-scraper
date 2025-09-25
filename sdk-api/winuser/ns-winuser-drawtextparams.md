# DRAWTEXTPARAMS structure

## Description

The **DRAWTEXTPARAMS** structure contains extended formatting options for the [DrawTextEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtextexa) function.

## Members

### `cbSize`

The structure size, in bytes.

### `iTabLength`

The size of each tab stop, in units equal to the average character width.

### `iLeftMargin`

The left margin, in units equal to the average character width.

### `iRightMargin`

The right margin, in units equal to the average character width.

### `uiLengthDrawn`

Receives the number of characters processed by [DrawTextEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtextexa), including white-space characters. The number can be the [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) or the index of the first line that falls below the drawing area. Note that **DrawTextEx** always processes the entire string if the DT_NOCLIP formatting flag is specified.

## See also

[DrawTextEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtextexa)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)