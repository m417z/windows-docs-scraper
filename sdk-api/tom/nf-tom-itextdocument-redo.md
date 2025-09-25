# ITextDocument::Redo

## Description

Performs a specified number of redo operations.

## Parameters

### `Count`

Type: **long**

The number of redo operations specified.

### `pCount`

Type: **long***

The actual count of redo operations performed. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If the method succeeds it returns **S_OK**. If the method fails, it returns the following COM error code. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | Less than *Count* redo operations were performed. |

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)

[Undo](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-undo)