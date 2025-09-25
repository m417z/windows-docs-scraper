# ITextRange::MoveStartWhile

## Description

Moves the start position of the range either *Count* characters, or just past all contiguous characters that are found in the set of characters specified by *Cset*, whichever is less.

## Parameters

### `Cset`

Type: **VARIANT***

The character set to use in the match. This could be an explicit string of characters or a character-set index. For more information, see [Character Match Sets](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model).

### `Count`

Type: **long**

Maximum number of characters to move past. The default value is **tomForward**, which searches to the end of the story. If *Count* is greater than zero, the search is forward—toward the end of the story—and if *Count* is less than zero, search is backward—toward the beginning. If *Count* is zero, the start position is unchanged.

### `pDelta`

Type: **long***

The actual count of characters that the start position is moved. This parameter can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Cset is not valid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If the new start follows the old end, the new end is set equal to the new start.

The motion described by **ITextRange::MoveStartWhile** is logical rather than geometric. That is, motion is toward the end or toward the start of a story. Depending on the language, moving to the end of the story could be moving left or moving right.

For more information, see [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) and [ITextRange::Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

[MoveWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movewhile)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)