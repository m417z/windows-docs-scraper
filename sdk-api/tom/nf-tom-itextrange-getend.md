# ITextRange::GetEnd

## Description

Gets the end character position of the range.

## Parameters

### `pcpLim`

Type: **long***

The end character position.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *pcpLim* is null, the method fails and it returns E_INVALIDARG.

## Remarks

Although a pointer to a range remains valid when the text is edited, this is not the case for the
character position. A
character position is volatile; that is, it becomes invalid as soon as text is inserted or deleted before the
character position. Be careful about using methods that return
character position values, especially if the values are to be stored for any duration.

This method is similar to the [ITextRange::GetStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getstart) method which gets the start character position of the range.

## See also

**Conceptual**

[GetStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getstart)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[SetEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setend)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)