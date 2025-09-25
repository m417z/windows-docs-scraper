# ITextRange::IsEqual

## Description

Determines whether this range has the same character positions and story as those of a specified range.

## Parameters

### `pRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)***

The [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object that is compared to this range.

### `pValue`

Type: **long***

The comparison result. The pointer can be null. The *pB* parameter receives **tomTrue** if this range points at the same text (has the same start and end character positions and story) as *pRange*; otherwise it returns **tomFalse**.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the ranges have the same character positions and story, the method returns **S_OK**. Otherwise, it returns S_FALSE.

## Remarks

The
**ITextRange::IsEqual** method returns **tomTrue** only if the range points at the same text as *pRange*. See [Finding Rich Text](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) for code that compares two different pieces of text to see if they contain the same plain text and the same character formatting.

## See also

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)