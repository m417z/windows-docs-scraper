# IInkEdit::get_SelFontName

## Description

Gets or sets the font name of the selected text within the InkEdit control (run time only).

This property is read/write.

## Parameters

## Remarks

If a selection spans multiple characters with different fonts, the [SelColor](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_selcolor) property will be **NULL**.

If there is no text selected in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control, setting this property determines the font of all new text entered at the current insertion point.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)