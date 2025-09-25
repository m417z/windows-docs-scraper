# IInkEdit::put_SelStart

## Description

Gets or sets the starting point of the text that is selected in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control (run time only).

This property is read/write.

## Parameters

## Remarks

Setting **SelStart** greater than the text length sets the property to the existing text length; changing **SelStart** changes the selection to an insertion point and sets [SelLength](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_sellength) to 0.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)