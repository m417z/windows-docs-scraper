# ITextDocument::Undo

## Description

Performs a specified number of undo operations.

## Parameters

### `Count`

Type: **long**

The specified number of undo operations. If the value of this parameter is **tomFalse**, undo processing is suspended. If this parameter is **tomTrue**, undo processing is restored.

### `pCount`

Type: **long***

The actual count of undo operations performed. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If all of the
*Count* undo operations were performed, it returns **S_OK**. If the method fails, it returns **S_FALSE**, indicating that less than
*Count* undo operations were performed. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[Redo](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-redo)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)