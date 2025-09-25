# ITextDocument::New

## Description

Opens a new document.

## Return value

Type: **HRESULT**

If the **ITextDocument::New** method succeeds, it returns **S_OK**.

## Remarks

If another document is open, this method saves any current changes and closes the current document before opening a new one.

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[Open](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-open)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)