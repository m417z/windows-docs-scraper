# ITextSelection::MoveDown

## Description

Mimics the functionality of the Down Arrow and Page Down keys.

## Parameters

### `Unit`

Type: **long**

Unit to use in the operation. It can be one of the following.

| Value | Corresponding key combination | Meaning |
| --- | --- | --- |
| **tomLine** | Down Arrow | Moves down one line. This is the default. |
| **tomParagraph** | Ctrl+Down Arrow | Moves down one paragraph. |
| **tomScreen** | Page Down | Moves down one screen. |
| **tomWindow** | Ctrl+Page Down | Moves to last character in window. |

### `Count`

Type: **long**

Number of Units to move past. The default value is 1.

### `Extend`

Type: **long**

Flag that indicates how to change the selection. If
*Extend* is zero (or **tomMove**), the method collapses the selection to an insertion point and then moves. If
*Extend* is 1 (or **tomExtend**), the method moves the active end and leaves the other end alone. The default value is zero. A nonzero
*Extend* value corresponds to the Shift key being pressed in addition to the key combination described in
*Unit*.

### `pDelta`

Type: **long***

Pointer to a variable that receives the actual count of units the insertion point or active end is moved down. Collapsing the selection counts as one unit. This parameter can be null.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Unit is not valid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

The [ITextSelection::MoveUp](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveup) and **ITextSelection::MoveDown** methods are similar to the [ITextSelection::MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft) and [ITextSelection::MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) methods, except that they reflect the behavior of the Up Arrow, Down Arrow, Page Up, and Page Down keys on the cursor-keypad.

## See also

**Conceptual**

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

[MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft)

[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright)

[MoveUp](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveup)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)