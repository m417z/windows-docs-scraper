# ITextHost2::TxShowDropCaret

## Description

Shows or hides the caret during the drop portion of a drag-and-drop operation (Direct2D only).

## Parameters

### `fShow`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Show or hide flag. **TRUE** shows the drop caret, and **FALSE** hides it.

### `hdc`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The HDC.

### `prc`

Type: **[LPCRECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The drop caret rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextHost2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost2)