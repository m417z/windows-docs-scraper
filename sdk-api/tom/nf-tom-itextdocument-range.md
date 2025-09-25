# ITextDocument::Range

## Description

Retrieves a text range object for a specified range of content in the active story of the document.

## Parameters

### `cpActive`

Type: **long**

The start position of new range. The default value is zero, which represents the start of the document.

### `cpAnchor`

Type: **long**

The end position of new range. The default value is zero.

### `ppRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)****

Address of a pointer to a variable of type [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) that receives a pointer to the specified text range.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)