# IInkEdit::get_SelColor

## Description

Gets or sets the text color of the current text selection or insertion point (run time only).

This property is read/write.

## Parameters

## Remarks

If a selection spans multiple characters with different colors, the **SelColor** property will be **NULL**.

If there is no text selected in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control, setting this property determines the color of all new text entered at the current insertion point.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)