# ITextRange::SetEnd

## Description

Sets the end position of the range.

## Parameters

### `cpLim`

Type: **long**

The new end position.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE.

## Remarks

If the new end position is less than the start position, this method also sets the start position to *cp*; that is, the range becomes an insertion point.

If this range is actually the selection, the end position becomes the active end and, if the display is not frozen, it is scrolled into view.

[ITextRange::SetStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setstart) sets the range's start position and [ITextRange::SetRange](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setrange) sets both range ends simultaneously. To convert a nondegenerate range, r, into a degenerate one (insertion point) at the start position, use

`r.End = r.Start`

Similarly, r.Start = r.End converts r into an insertion point at the end position.

To add 1 to the end position, unless it is at the end of the story, use:

`r.End = r.End + 1`

This also makes end position the active end, and it can turn a degenerate range into a nondegenerate one.

## See also

**Conceptual**

[GetEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getend)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[SetRange](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setrange)

[SetStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setstart)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)