# ITextHost::TxInvalidateRect

## Description

Specifies a rectangle for the text host to add to the update region of the text host window.

## Parameters

### `prc` [in]

Type: **LPCRECT**

The invalid rectangle.

### `fMode` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the background within the update region is to be erased when the update region is processed. If this parameter is **TRUE**, the background is erased when the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function is called. If this parameter is **FALSE**, the background remains unchanged.

## Remarks

This function may be called while inactive; however, the host implementation is free to invalidate an area greater than the requested
[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect).

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)