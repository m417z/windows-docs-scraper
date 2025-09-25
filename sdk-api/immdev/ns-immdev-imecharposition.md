# IMECHARPOSITION structure

## Description

Contains information about the character position in the composition window.

## Members

### `dwSize`

Size of the structure, in bytes.

### `dwCharPos`

Character offset in the composition string, in **TCHAR** values.

### `pt`

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the coordinate of the top left point of requested character in screen coordinates. The top left point is based on the character baseline in any text flow.

### `cLineHeight`

Height of a line that contains the requested character, in pixels.

### `rcDocument`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the editable area for text, in screen coordinates, for the application.

## Remarks

When an application uses IME to draw the composition string, the members of this structure are automatically filled. Applications that draw the composition string themselves, rather than relying on the IME, are responsible for filling all the fields defined in the structure.

## See also

[IMR_QUERYCHARPOSITION](https://learn.microsoft.com/windows/desktop/Intl/imr-querycharposition)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)