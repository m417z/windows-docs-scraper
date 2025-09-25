# ITextHost::TxGetViewInset

## Description

Requests the dimensions of the white space inset around the text in the text host window.

## Parameters

### `prc`

Type: **LPRECT**

The inset size, in client coordinates. The top, bottom, left, and right members of the
[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure indicate how far in each direction the drawing should be inset.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is **S_OK**.

## Remarks

The view inset is the amount of space on each side between the client rectangle and the view rectangle. The view rectangle (also called the Formatting rectangle) is the rectangle in which the text should be formatted .

The view insets are passed in a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure, but this is not really a rectangle. It should be treated as four independent values to subtract on each side of the client rectangle to figure the view rectangle.

The view insets are passed in HIMETRIC (each HIMETRIC unit corresponds to 0.01 millimeter) so that they do not depend on the client rectangle and the rendering device context.

View insets can be negative on either side of the client rectangle, leading to a bigger view rectangle than the client rectangle. The text should then be clipped to the client rectangle. If the view rectangle is wider than the client rectangle, then the host may add a horizontal scroll bar to the control.

Single line–text services objects ignore the right boundary of the view rectangle when formatting text.

The view inset is available from the host at all times, active or inactive.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)