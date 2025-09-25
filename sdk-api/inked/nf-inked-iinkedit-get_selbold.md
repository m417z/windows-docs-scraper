# IInkEdit::get_SelBold

## Description

Gets or sets a value that specifies whether the font style of the currently selected text in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control is bold.

This property is read/write.

## Parameters

## Remarks

If a selection spans multiple characters with different bold styles, the **SelBold** property will be **NULL**.

If there is no text selected in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control, setting this property determines whether all new text entered at the current insertion point is bold.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)