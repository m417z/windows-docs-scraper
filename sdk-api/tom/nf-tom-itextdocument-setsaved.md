# ITextDocument::SetSaved

## Description

Sets the document
**Saved** property.

## Parameters

### `Value` [in]

Type: **long**

New value of the
**Saved** property. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **tomTrue** | No changes to the file since the last time it was saved. |
| **tomFalse** | There are changes to the file. |

## Return value

Type: **HRESULT**

The return value is **S_OK**.

## See also

**Conceptual**

[GetSaved](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getsaved)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)