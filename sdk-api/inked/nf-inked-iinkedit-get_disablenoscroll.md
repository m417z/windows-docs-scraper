# IInkEdit::get_DisableNoScroll

## Description

Gets or sets a value that determines whether scroll bars in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control are disabled.

This property is read/write.

## Parameters

## Remarks

The **DisableNoScroll** property is ignored when the [ScrollBars](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_scrollbars) property is set to **rtfNone**. However, when **ScrollBars** is set to **rtfHorizontal**, **rtfVertical**, or **rtfBoth**, individual scroll bars are disabled when there are too few lines of text to scroll vertically or too few characters of text to scroll horizontally in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control.

This property is read-only at run time.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)