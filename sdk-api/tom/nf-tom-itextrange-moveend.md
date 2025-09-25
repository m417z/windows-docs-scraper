# ITextRange::MoveEnd

## Description

Moves the end position of the range.

## Parameters

### `Unit`

Type: **long**

The units by which to move the end of the range. The default value is **tomCharacter**. For a list of the other unit values, see [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `Count`

Type: **long**

The number of units to move past. The default value is 1. If *Count* is greater than zero, motion is forward—toward the end of the story—and if *Count* is less than zero, motion is backward—toward the beginning. If *Count* is zero, the end position is unchanged.

### `pDelta`

Type: **long***

The actual number of units that the end position of the range is moved past. The value can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Unit is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If the new end position precedes the old start position, the new start position is set equal to the new end position; that is, it becomes a degenerate range or an insertion point.

The motion described by **ITextRange::MoveEnd** is logical rather than geometric. That is, motion is toward the end or toward the start of a story. Depending on the language, moving to the end of the story could be moving left or moving right.

For more information, see [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) and [ITextRange::Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)