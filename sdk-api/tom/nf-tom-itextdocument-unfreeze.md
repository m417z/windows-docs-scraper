# ITextDocument::Unfreeze

## Description

Decrements the freeze count.

## Parameters

### `pCount`

Type: **long***

The updated freeze count.

## Return value

Type: **HRESULT**

If the
freeze count is zero, the method returns **S_OK**. If the method fails, it returns **S_FALSE**, indicating that the
freeze count is nonzero. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

If the freeze count goes to zero, screen updating is enabled. This method cannot decrement the count below zero, and no error occurs if it is executed with a zero freeze count.

Note, if edit collection is active, screen updating is suppressed, even if the freeze count is zero.

## See also

[BeginEditCollection](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-begineditcollection)

**Conceptual**

[Freeze](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-freeze)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)