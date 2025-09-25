# ITextSelection::EndKey

## Description

Mimics the functionality of the End key.

## Parameters

### `Unit`

Type: **long**

Unit to use. It can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomLine** | Depending on *Extend*, it moves either the insertion point or the active end to the end of the last line in the selection. This is the default. |
| **tomStory** | Depending on *Extend*, it moves either the insertion point or the active end to the end of the last line in the story. |
| **tomColumn** | Depending on *Extend*, it moves either the insertion point or the active end to the end of the last column in the selection. This is available only if the TOM engine supports tables. |
| **tomRow** | Depending on *Extend*, it moves either the insertion point or the active end to the end of the last row in the selection. This is available only if the TOM engine supports tables. |

### `Extend`

Type: **long**

Flag that indicates how to change the selection. If
*Extend* is zero (or **tomMove**), the method collapses the selection to an insertion point. If
*Extend* is 1 (or **tomExtend**), the method moves the active end and leaves the other end alone. The default value is zero.

### `pDelta`

Type: **long***

Pointer to a variable that receives the count of characters that the insertion point or the active end is moved. This parameter can be null.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Unit is neither **tomLine** nor **tomStory**. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

Setting *Extend* to **tomExtend** (or nonzero) corresponds to the Shift key being pressed. Setting *Unit* to **tomLine** corresponds to the Ctrl key not being pressed. Setting *Unit* to **tomStory** to Ctrl being pressed. The *pDelta* parameters receives the number of characters that the insertion point or active end is moved.

The [ITextSelection::HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey) and **ITextSelection::EndKey** methods are used to mimic the standard Home/End key behavior.

The **tomLine** value mimics the Home or End key behavior
*without* the Ctrl key pressed, while **tomStory** mimics the behavior
*with* the Ctrl
key pressed. Similarly, **tomMove** mimics the Home or End key behavior
*without* the Shift key pressed, while **tomExtend** mimics the behavior
*with* the Shift key pressed. So
`EndKey(tomStory)` converts the selection into an insertion point at the end of the associated story, while `EndKey(tomStory, tomExtend)` moves the active end of the selection to the end of the story and leaves the other end where it was.

The
[HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey) and **EndKey** methods are logical methods like the **Move*** methods, rather than directional methods. Thus, they depend on the language that is involved. For example, in Arabic text,
**HomeKey** moves to the right end of a line, whereas in English text, it moves to the left. Thus,
**HomeKey** and **EndKey** are different than the [MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft) and [MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) methods. Also, note that the **EndKey** method is quite different from the
**End** property, which is the `cp` at the end of the selection.
**HomeKey** and **EndKey** also differ from the [StartOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-startof) and [EndOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-endof) methods in that they extend from the active end, whereas
**StartOf** extends from Start and
**EndOf** extends from End.

## See also

**Conceptual**

[EndOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-endof)

[HomeKey](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-homekey)

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

[MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft)

[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright)

**Reference**

[StartOf](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-startof)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)