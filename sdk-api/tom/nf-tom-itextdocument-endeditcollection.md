# ITextDocument::EndEditCollection

## Description

Turns off edit collection (also called *undo grouping*).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | This method is not implemented. |

## Remarks

The screen is unfrozen unless the freeze count is nonzero.

## See also

[BeginEditCollection](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-begineditcollection)

**Conceptual**

[Freeze](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-freeze)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)