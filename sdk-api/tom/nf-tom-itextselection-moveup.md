# ITextSelection::MoveUp

## Description

Mimics the functionality of the Up Arrow and Page Up keys.

## Parameters

### `Unit`

Type: **long**

Unit to use in the operation. It can be one of the following.

| Value | Corresponding key combination | Meaning |
| --- | --- | --- |
| **tomLine** | Up Arrow | Moves up one line. This is the default. |
| **tomParagraph** | Ctrl+Up Arrow | Moves up one paragraph. |
| **tomScreen** | Page Up | Moves up one screen. |
| **tomWindow** | Ctrl+Page Up | Moves to first character in window. |

### `Count`

Type: **long**

Number of *Units* to move past. The default value is 1.

### `Extend`

Type: **long**

Flag that indicates how to change the selection. If
*Extend* is zero (or **tomMove**), the method collapses the selection to an insertion point and then moves. If *Extend* is 1 (or **tomExtend**), the method moves the active end and leaves the other end alone. The default value is zero. A nonzero *Extend* value corresponds to the Shift key being pressed in addition to the key combination described in
*Unit*.

### `pDelta`

Type: **long***

The actual count of units the insertion point or active end is moved down. This parameter can be null. Collapsing the selection counts as one unit.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Unit is not valid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

The **MoveUp** and [MoveDown](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-movedown) methods are similar to the [MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft) and [MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) methods, except that they reflect the behavior of the Up Arrow, Down Arrow, Page Up, and Page Down keys on the cursor-keypad.

## See also

**Conceptual**

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

[MoveDown](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-movedown)

[MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft)

[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)