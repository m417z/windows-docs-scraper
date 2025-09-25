# ITextRange::Move

## Description

Moves the insertion point forward or backward a specified number of units. If the range is nondegenerate, the range is collapsed to an insertion point at either end, depending on *Count*, and then is moved.

## Parameters

### `Unit`

Type: **long**

Unit to use. The default value is **tomCharacter**. For information on other values, see the discussion in [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `Count`

Type: **long**

Number of *Unit*s to move past. The default value is 1. If *Count* is greater than zero, motion is forward—toward the end of the story—and if *Count* is less than zero, motion is backward—toward the beginning. If *Count* is zero, the range is unchanged.

### `pDelta`

Type: **long***

The actual number of *Unit*s the insertion point moves past. The pointer can be **NULL**. For more information, see the Remarks section.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds in moving the insertion point, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | *Unit* is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If the range is degenerate (an insertion point), this method tries to move the insertion point *Count* *Unit*s.

If the range is nondegenerate and *Count* is greater than zero, this method collapses the range at the end character position, moves the resulting insertion point forward to a *Unit* boundary (if it is not already at one), and then tries to move *Count* - 1 *Unit*s forward. If the range is nondegenerate and *Count* is less than zero, this method collapses the range at the start character position, moves the resulting insertion point backward to a *Unit* boundary (if it isn't already at one), and then tries to move |*Count*| - 1 *Unit*s backward. Thus, in both cases, collapsing a nondegenerate range to an insertion point, whether moving to the start or end of the *Unit* following the collapse, counts as a *Unit*.

The **ITextRange::Move** method returns *pDelta* = number of *Unit*s actually moved. This method never moves the insertion point beyond the story of this range. If *Count**Unit*s would move the insertion point before the beginning of the story, it is moved to the story beginning and *pDelta* is set accordingly. Similarly, if *Count*
*Unit*s would move it beyond the end of the story, it is moved to the story end.

The **ITextRange::Move** method works similarly to the UI-oriented [MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft) and [MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) methods, except that the direction of motion is logical rather than geometrical. That is, with **ITextRange::Move** the direction is either toward the end or toward the start of the story. Depending on the language, moving toward the end of the story could be moving to the left or to the right. To get a feel for *Count*, press Ctrl+Right Arrow in a Microsoft Word document for a variety of selections. In left-to-right text, this keystroke behaves the same as `Move(tomWord, 1)`, and `MoveRight(tomWord, 1)`. *Count* corresponds to the number of times you press Ctrl+Right Arrow.

For example, if you press Ctrl+Right Arrow for the selections shown in both of the following figures, you end up with an insertion point at character position 8, since this command collapses the selections at their end character positions (7 and 8, respectively) and moves to the next **tomWord** boundary.

![Character positions for text string](https://learn.microsoft.com/windows/win32/api/tom/images/textpos3.png)
![Character positions for text string](https://learn.microsoft.com/windows/win32/api/tom/images/textpos3.png)
The first selection does not include the blank space at character position 7, so Ctrl+Right Arrow moves past the space to the **tomWord** boundary at character position 8. The end character position is already at a **tomWord** boundary for the second selection, so Ctrl+Right Arrow just collapses the selection at that boundary. Similarly, Ctrl+Left Arrow, which for this text acts like `Move(tomWord, -1)`, and `MoveLeft(tomWord, 1)` collapses the first selection at character position 5, which is already at a **tomWord** boundary, so no more motion occurs. But Ctrl+Left Arrow collapses the second selection at character position 4 and then moves to zero, since that's the next **tomWord** boundary in the direction of motion.

The return argument, *pDelta*, is set equal to the number of *Unit*s that the insertion point is moved including one *Unit* for collapsing a nondegenerate range and moving it to a *Unit* boundary. So, if no motion and no collapse occur, as when the range is an insertion point at the end of the story, *pDelta* is set equal to zero. This approach is useful for controlling program loops that process a whole story.

In both of the cases mentioned above, calling `Move(tomWord, 1)` sets *pDelta* equal to 1 because the ranges were collapsed. Similarly, calling `Move(tomWord, -1)` sets *pDelta* equal to -1 for both cases. Collapsing, with or without moving part of a *Unit* to a *Unit* boundary, counts as a *Unit* moved.

The direction of motion refers to the logical character ordering in the plain-text backing store. This approach avoids the problems of geometrical ordering, such as left versus right and up versus down, in international software. Such geometrical methods are still needed in the edit engine, of course, since keyboards have arrow keys to invoke them. If the range is really an [ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection) object, then methods like [MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft) and [MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright) can be used.

If *Unit* specifies characters (**tomCharacter**), the Text Object Model (TOM) uses the Unicode character set. To convert between Unicode and multibyte character sets the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) and [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) functions provide easy ways to convert between Unicode and multibyte character sets on import and export, respectively. For more information, see [Open](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-open). In this connection, the use of a carriage return/line feed (CR/LF) to separate paragraphs is as problematic as double-byte character set (DBCS). The [ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection) UI methods back up over a CR/LF as if it were a single character, but the **ITextRange::Move** methods count CR/LFs as two characters. It's clearly better to use a single character as a paragraph separator, which in TOM is represented by a character return, although the Unicode paragraph separator character, 0x2029, is accepted. In general, TOM engines should support CR/LF, carriage return (CR), line feed (LF), vertical tab, form feed, and 0x2029. Microsoft Rich Edit 2.0 also supports CR/CR/LF for backward compatibility.

See also the [ITextRange::MoveStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestart) and [ITextRange::MoveEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveend) methods, which move the range Start or End position *Count*
*Unit*s, respectively.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[MoveEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveend)

[MoveLeft](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveleft)

[MoveRight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-moveright)

[MoveStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestart)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[Open](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-open)

**Other Resources**

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)

[WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte)