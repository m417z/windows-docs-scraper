# ITextRange::Select

## Description

Sets the start and end positions, and story values of the active selection, to those of this range.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE.

## Remarks

The active end of the new selection is at the end position.

The caret for an ambiguous character position is displayed at the beginning of the line.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)