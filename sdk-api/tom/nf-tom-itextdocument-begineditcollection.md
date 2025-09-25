# ITextDocument::BeginEditCollection

## Description

Turns on edit collection (also called *undo grouping*).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | Undo is not enabled. |
| **E_NOTIMPL** | This method is not implemented. |

## Remarks

A single
**Undo** command undoes all changes made while edit collection is turned on.

## See also

**Conceptual**

[EndEditCollection](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-endeditcollection)

[Freeze](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-freeze)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)