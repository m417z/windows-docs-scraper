# ITextDocument::Freeze

## Description

Increments the freeze count.

## Parameters

### `pCount`

Type: **long***

The updated freeze count.

## Return value

Type: **HRESULT**

If the **ITextDocument::Freeze** count is nonzero, it returns **S_OK**. If the **ITextDocument::Freeze** count is zero, it returns **FALSE**.

## Remarks

If the freeze count is nonzero, screen updating is disabled. This allows a sequence of editing operations to be performed without the performance loss and flicker of screen updating. To decrement the freeze count, call the [ITextDocument::Unfreeze](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-unfreeze) method.

## See also

[BeginEditCollection](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-begineditcollection)

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)

[Unfreeze](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-unfreeze)