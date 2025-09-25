# IInkEdit::put_ScrollBars

## Description

Gets or sets the type of scroll bars, if any, to display in the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control.

This property is read/write.

## Parameters

## Remarks

For an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control with setting rtfHorizontal, rtfVertical, or rtfBoth, you must set the [MultiLine](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_multiline) property to **TRUE**.

At run time, the Windows operating environment automatically implements a standard keyboard interface to allow navigation in [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) controls with the arrow keys (UP ARROW, DOWN ARROW, LEFT ARROW, and RIGHT ARROW), the HOME and END keys, and so on.

Scroll bars are displayed only if the contents of the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control extend beyond the control's borders. If **ScrollBars** is set to **FALSE**, the control won't have scroll bars, regardless of its contents.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)