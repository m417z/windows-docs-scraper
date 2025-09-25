# ITextRange::MoveStart

## Description

Moves the start position of the range the specified number of units in the specified direction.

## Parameters

### `Unit`

Type: **long**

Unit used in the move. The default value is **tomCharacter**. For a list of the other *Unit* values, see the discussion under [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `Count`

Type: **long**

Number of units to move. The default value is 1. If *Count* is greater than zero, motion is forward—toward the end of the story—and if *Count* is less than zero, motion is backward—toward the beginning. If *Count* is zero, the start position is unchanged.

### `pDelta`

Type: **long***

The actual number of units that the end is moved. The value can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Unit is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If the new start follows the old end, the new end is set equal to the new start.

The motion described by **ITextRange::MoveStart** is logical rather than geometric. That is, motion is toward the end or toward the start of a story. Depending on the language, moving to the end of the story could be moving left or moving right.

For more information, see [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) and [ITextRange::Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

[MoveEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveend)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)