# ITextRange::GetStart

## Description

Gets the start character position of the range.

## Parameters

### `pcpFirst`

Type: **long***

The start character position.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *pcpFirst* is null, the method fails and it returns E_INVALIDARG.

## See also

**Conceptual**

[GetEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getend)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[SetStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setstart)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)