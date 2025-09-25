# ITextDocument::GetSelection

## Description

Gets the active selection.

## Parameters

### `ppSel`

Type: **[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)****

The active selection.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | Indicates no active selection. |
| **E_INVALIDARG** | Invalid argument. |

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)