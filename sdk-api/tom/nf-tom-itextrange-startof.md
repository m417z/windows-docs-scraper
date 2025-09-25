# ITextRange::StartOf

## Description

Moves the range ends to the start of the first overlapping *Unit* in the range.

## Parameters

### `Unit`

Type: **long**

Unit to use in the move operation. For a list of *Unit* values, see the discussion under [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `Extend`

Type: **long**

How to move the ends of the range. It can be one of the following values.

|  |  |
| --- | --- |
| 0 (or **tomMove**) | Collapses a nondegenerate range to the start position by moving the insertion point. This is the default. |
| 1 (or **tomExtend**) | Moves the start position to the beginning of the overlapping *Unit*. Does not move the end position. |

### `pDelta`

Type: **long***

Pointer to a variable that receives the number of characters that the start position is moved. It can be null. On return, *pDelta* is the signed number of characters that the insertion point or start position is moved. This value is always less than or equal to zero, because the motion is always toward the beginning of the story.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Unit is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If the range is an insertion point on a boundary between *Unit*s, **ITextRange::StartOf** does not change the start position.

The **ITextRange::StartOf** and [ITextRange::EndOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-endof) methods differ from the [HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey) and [EndKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-endkey) methods in that the latter extend from the active end, whereas **ITextRange::StartOf** extends from the start position and **ITextRange::EndOf** extends from the end position.

## See also

**Conceptual**

[EndKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-endkey)

[EndOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-endof)

[HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)