# ITextRange::InRange

## Description

Determines whether this range is within or at the same text as a specified range.

## Parameters

### `pRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)***

Text that is compared to the current range.

### `pValue`

Type: **long***

The comparison result. The pointer can be null. The method returns *pB* is **tomTrue** only if the range is in or at the same text as *pRange*.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE.

## Remarks

For range2 to be contained in range1, both ranges must be in the same story, and the limits of
range2 must satisfy
either of the following statements.

* The start and end character positions of range1 are the same as range2. That is, both ranges are degenerate and have identical insertion points.
* Range2 is a nondegenerate range with start and end character positions at or within those of range1.

The following example shows how to walk one range with another.

```
    range2 = range1.Duplicate
    range2.End = range2.Start       ' Collapse range2 to its start position
    While range2.InRange(range1)    ' Iterate so long as range2 remains within range1
         ...   ' This code would change the range2 character positions
    Wend
```

When the [ITextRange::FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext), [ITextRange::MoveWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movewhile), and [ITextRange::MoveUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveuntil) method families are used, you can use one range to walk another by specifying the appropriate limit count of characters (for an example, see the Remarks in
**ITextRange::Find**).

[ITextRange::IsEqual](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-isequal) is a special case of **ITextRange::InRange** that returns *pB* **tomTrue** if the *pRange* has the same start and end character positions and belongs to the same story.

## See also

**Conceptual**

[FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[MoveUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveuntil)

[MoveWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movewhile)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)