# ITextRange::EndOf

## Description

Moves this range's ends to the end of the last overlapping *Unit* in the range.

## Parameters

### `Unit`

Type: **long**

Unit to use. Default value: *tomWord*. For a list of the other *Unit* values, see the discussion under [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `Extend`

Type: **long**

Indicator of how the shifting of the range ends is to proceed. It can be one of the following.

|  |  |
| --- | --- |
| 0 or *tomMove* | Collapses a nondegenerate range to the End of the original range by moving the insertion point. This is the default. |
| 1 (or *tomExtend*) | Moves End to the end of the overlapping *Unit*. Does not move Start. |

### `pDelta`

Type: **long***

The count of characters that End is moved past. The value of the pointer can be null. On return, the value of
*pDelta* is the number of characters the insertion point or End is moved
*plus* 1 if a collapse occurs to the entry End. If the range includes the final CR (carriage return) (at the end of the story) and
*Extend* = tomMove, then
*pDelta* is set to
–1, to indicate that the collapse occurred
*before* the end of the range (because an insertion point cannot exist beyond the final CR).

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Unit is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

For comparison, the [ITextRange::StartOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-startof) method moves the range ends to the beginning of the first overlapping *Unit* in the range. Note, the **ITextRange::StartOf** and **ITextRange::EndOf** methods differ from the [HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey) and [EndKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-endkey) methods in that the latter extend from the active end, whereas **ITextRange::StartOf** extends from Start and **ITextRange::EndOf** extends from End. If the range is an insertion point on a boundary between *Unit*s, **ITextRange::EndOf** does not change End. In particular, calling **ITextRange::EndOf** (*tomCharacter*, *, *) does not change End except for an insertion point at the beginning of a story.

## See also

**Conceptual**

[EndKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-endkey)

[HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[StartOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-startof)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)