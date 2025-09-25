# ITextRange::SetStart

## Description

Sets the character position for the start of this range.

## Parameters

### `cpFirst` [in]

Type: **long**

The new character position for the start of the range.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE.

## Remarks

Note that if *cpFirst* is greater than the range's end position, this method sets the end position equal to *cpFirst*, making the range an insertion point. If this range is the selection, the start position becomes the active end and is scrolled into view if the display isn't frozen.

[ITextRange::SetEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setend) sets the range's end position, and [ITextRange::SetRange](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setrange) sets both range ends simultaneously. The following example shows how to convert a nondegenerate range into a degenerate one (insertion point).

`range.End = range.Start`

Similarly, `range.Start = range.End` converts the range into an insertion point at the end position.

The following example adds 1 to the end position, if it is not at the end of the story.

`range.End = range.End + 1`

This also makes the end position the active end of the range, and it can turn a degenerate range into a nondegenerate one.

## See also

**Conceptual**

[GetStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getstart)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[SetEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setend)

[SetRange](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setrange)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)