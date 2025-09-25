# IInkEdit::get_SelItalic

## Description

Gets or sets a value that specifies whether the font style of the currently selected text in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control is italic (run time only).

This property is read/write.

## Parameters

## Remarks

If a selection spans multiple italicized and un-italicized characters, the **SelItalic** property will be **NULL**.

If there is no text selected in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control, setting this property indicates all new text entered at the current insertion point will be italicized.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)