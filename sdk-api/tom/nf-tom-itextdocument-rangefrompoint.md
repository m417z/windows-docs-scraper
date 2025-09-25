# ITextDocument::RangeFromPoint

## Description

Retrieves a range for the content at or nearest to the specified point on the screen.

## Parameters

### `x`

Type: **long**

The horizontal coordinate of the specified point, in screen coordinates.

### `y`

Type: **long**

The vertical coordinate of the specified point, in screen coordinates.

### `ppRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)****

The text range that corresponds to the specified point.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

**Conceptual**

[Expand](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-expand)

[GetPoint](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getpoint)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[MoveStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestart)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)