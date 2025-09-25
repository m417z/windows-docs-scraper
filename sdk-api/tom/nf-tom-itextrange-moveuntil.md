# ITextRange::MoveUntil

## Description

Searches up to *Count* characters for the first character in the set of characters specified by *Cset*. If a character is found, the range is collapsed to that point. The start of the search and the direction are also specified by *Count*.

## Parameters

### `Cset`

Type: **VARIANT***

The character set used in the match. This could be an explicit string of characters or a character-set index. For more information, see [Character Match Sets](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model).

### `Count`

Type: **long**

Maximum number of characters to move past. The default value is **tomForward**, which searches to the end of the story. If *Count* is less than zero, the search is backward starting at the start position. If *Count* is greater than zero, the search is forward starting at the end.

### `pDelta`

Type: **long***

The number of characters the insertion point is moved, plus 1 for a match if *Count* is greater than zero, and –1 for a match if *Count* less than zero. The pointer can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *Cset* is not valid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If no character is matched, the range is unchanged.

The motion described by **ITextRange::MoveUntil** is logical rather than geometric. That is, motion is toward the end or toward the start of a story. Depending on the language, moving to the end of the story could be moving left or moving right.

For more information, see the discussion in [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) and the Remarks section of [ITextRange::Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move).

The [ITextRange::MoveStartUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestartuntil) and [ITextRange::MoveEndUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveenduntil) methods move the start and end, respectively, until it finds the first character that is also in the set specified by the *Cset* parameter.

The **ITextRange::MoveUntil** method is similar to [ITextRange::MoveWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movewhile), but there are two differences. First, **MoveUntil** moves an insertion point *until* it finds the first character that belongs to the character set specified by *Cset*. Second, in **MoveUntil** the character matched counts as an additional character in the value returned in *pDelta*. This lets you know that the character at one end of the range or the other belongs to the *Cset* even though the insertion point stays at one of the range ends.

For example, suppose the range, r, is an insertion point. To see if the character at r (that is, given by r.[GetChar](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getchar)()) is in *Cset*, call

```
r.MoveUntil(Cset, 1)
```

If the character is in *Cset*, the return value is 1 and the insertion point does not move. Similarly, to see if the character preceding r is in *Cset*, call

```
r.MoveUntil(Cset, -1)
```

If the character is in *Cset*, the return value is –1.

The following Microsoft Visual Basic for Applications (VBA) subroutine prints all numbers in the story identified by the range, r.

```
Sub PrintNumbers (r As ITextRange)
   r.SetRange 0, 0    // r = insertion point at start of story
   While r.MoveUntil(C1_DIGIT)  // Move r to 1st digit in next number
      r.MoveEndWhile C1_DIGIT  // Select number (span of digits)
      Print r    // Print it
   Wend
End Sub
```

## See also

**Conceptual**

[GetChar](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getchar)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

[MoveEndUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveenduntil)

[MoveStartUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestartuntil)

[MoveWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movewhile)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)