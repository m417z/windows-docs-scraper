# ITextRange::MoveEndUntil

## Description

Moves the range's end to the character position of the first character found that is in the set of characters specified by *Cset*, provided that the character is found within *Count* characters of the range's end.

## Parameters

### `Cset`

Type: **VARIANT***

The character set to use in the match. This could be an explicit string of characters or a character-set index. For more information, see [Character Match Sets](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model).

### `Count`

Type: **long**

Maximum number of characters to move past. The default value is **tomForward**, which searches to the end of the story. If *Count* is greater than zero, the search moves forward (toward the end of the story). If *Count* is less than zero, the search moves backward (toward the beginning of the story). If *Count* is zero, the end position is unchanged.

### `pDelta`

Type: **long***

The actual number of characters that the range end is moved, plus 1 for a match if *Count* is greater than zero, and –1 for a match if *Count* is less than zero. The value can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Cset is invalid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If no character from the set specified by *Cset* is found within *Count* positions of the range's end, the range is left unchanged. If the new end precedes the old start, the new start is set equal to the new end.

The motion described by **ITextRange::MoveEndUntil** is logical rather than geometric. That is, motion is toward the end or toward the start of a story. Depending on the language, moving to the end of the story could be moving left or moving right.

For more information, see [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) and [ITextRange::Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

[MoveUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveuntil)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)