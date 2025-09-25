# ITextSelection::MoveLeft

## Description

Generalizes the functionality of the Left Arrow key.

## Parameters

### `Unit`

Type: **long**

Unit to use. It can be one of the following.

| Value | Corresponding key combination | Meaning |
| --- | --- | --- |
| **tomCharacter** | Left Arrow | Move one character position to the left. This is the default. |
| **tomWord** | Ctrl+Left Arrow | Move one word to the left. |

Note: If
*Count* is less than zero, movement is to the right.

### `Count`

Type: **long**

Number of Units to move past. The default value is 1. If
*Count* is less than zero, movement is to the right.

### `Extend`

Type: **long**

Flag that indicates how to change the selection. If
*Extend* is zero (or **tomMove**), the method collapses the selection to an insertion point at the active end and then moves it. If
*Extend* is 1 (or **tomExtend**), the method moves the active end and leaves the other end alone. The default value is zero. A nonzero
*Extend* value corresponds to the Shift key being pressed in addition to the key combination described in
*Unit*.

### `pDelta`

Type: **long***

The actual count of units the insertion point or active end is moved left. This parameter can be null. Collapsing the selection, when
*Extend* is 0, counts as one unit.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Unit is not valid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

The WordBasic move methods like
**CharRight**,
**CharLeft**,
**WordRight**, and
**WordLeft** are hybrids that can do four things that are closely related to the standard arrow-key edit behavior:

* Move the current insertion point if there's no selection.
* Move the active end of the selection if there is a selection.
* Turn an insertion point into a selection and vice versa.
* Return a Boolean stating if movement occurred.

The
*Extend* argument of
**MoveLeft** and
[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) enables you to be consistent with the first three items above, and the
*pDelta* is a generalization of the fourth. For example, given a selection consisting of a single range, you have the following correspondences (for left-to-right characters).

| ITextSelection | WordBasic | Function |
| --- | --- | --- |
| selection.MoveRight tomWord, 1, 1 | WordRight 1,1 | Moves active end one word right. |
| selection.MoveLeft tomCharacter, 1, 1 | CharLeft 1,1 | Moves active end one character left. |

As in WordBasic, if
*Count* is less than zero, the meanings of left and right are interchanged, that is `MoveLeft (Unit, Count, Extend)` is equivalent to `MoveRight (Unit, -Count, Extend)`.

Similar to WordBasic and the Left Arrow key UI behavior, calling `MoveLeft (
Unit, Count)` on a degenerate selection moves the insertion point the specified number of
*Unit*s. On a degenerate range, calling
`MoveLeft(
Unit, Count, 1)` where `Count` is greater than zero causes the range to become nondegenerate with the left end being the active end.

When
*Extend* is **tomExtend** (or is nonzero), **MoveLeft** moves only the active end of the selection, leaving the other end where it is. However, if
*Extend* equals zero and the selection starts as a nondegenerate range, `MoveLeft(Unit, Count)` where `Count` is greater than zero
moves the active end `Count` - 1 units left, and then moves the other end to the active end. In other words, it makes an insertion point at the active end. Collapsing the range counts as one
unit. Thus,
`MoveLeft(tomCharacter)` converts a nondegenerate selection into a degenerate one at the selection's left end. Here,
*Count* has the default value of 1 and
*Extend* has the default value of zero. This example corresponds to pressing the Left Arrow key.
**MoveLeft** and
[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) are related to the [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) move methods, but differ in that they explicitly use the active end (the end moved by pressing the Shift key).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)