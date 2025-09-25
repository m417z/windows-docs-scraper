# ITextRange::SetRange

## Description

Adjusts the range endpoints to the specified values.

## Parameters

### `cpAnchor`

Type: **long**

The character position for the anchor end of the range.

### `cpActive`

Type: **long**

The character position for the active end of the range.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method sets the range's start position to `min(cpActive, cpAnchor)`, and the end position to `max(cpActive, cpAnchor)`. If the range is a nondegenerate selection, *cpAnchor* is the active end, and *cpAnchor* is the anchor end. If the range is a degenerate selection, the selection is displayed at the start of the line, rather than at the end of the previous line.

This method removes any other subranges this range may have. To preserve the current subranges, use [ITextRange2::SetActiveSubrange](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-setactivesubrange).

If the text range is a selection, you can set the attributes of the selection by using the [ITextSelection::SetFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-setflags) method.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)