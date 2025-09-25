# ITextRange::Delete

## Description

Mimics the DELETE and BACKSPACE keys, with and without the CTRL key depressed.

## Parameters

### `Unit`

Type: **long**

Unit to use.
*Unit* can be *tomCharacter* (the default value) or *tomWord*.

### `Count`

Type: **long**

Number of
*Unit*s to delete. If
*Count*= zero, it deletes the text in the range only. If
*Count* is greater than zero, **ITextRange::Delete** acts as if the DELETE key was pressed
*Count* times. If
*Count* is less than zero, it acts as if the BACKSPACE key was pressed
*Count* times. The default value is 1. For more information, see the Remarks.

### `pDelta`

Type: **long***

The count of units deleted. It can be null. The
*pDelta* parameter is set equal to the number of
*Unit*s deleted. Deleting the text in a nondegenerate range counts as one
*Unit*.

## Return value

Type: **HRESULT**

This method returns an
**HRESULT** value. If successful, it returns **S_OK**. Otherwise it returns one of the following values. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is write-protected. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If
*Count* = zero, this method deletes the text in the range, that is, it deletes nothing if the range is only an insertion point.

If
*Count* is not zero, and the range is an insertion point (that is, degenerate), |
*Count*| (absolute value of
*Count*)
*Unit*s are deleted in the logical direction given by the sign of
*Count*, where a positive value is the direction toward the end of the story, and a negative value is toward the start of the story.

If
*Count* is not zero, and the range is nondegenerate (contains text), the text in the range is deleted (regardless of the values of
*Unit*  and
*Count*), thereby creating an insertion point. Then, |
*Count*| - 1
*Unit*s are deleted in the logical direction given by the sign of
*Count*.

The text in the range can also be deleted by assigning a null string to the range (executing statement r = where r is the range). However, **ITextRange::Delete** does not require allocating a **BSTR**.

Deleting the end-of-paragraph mark (CR) results in the special behavior of the Microsoft Word UI. Four cases are of particular interest:

* If you delete just the CR but the paragraph includes text, then the CR is deleted, and the following paragraph gets the same paragraph formatting as current one.
* If you delete the CR as well as some, but not all, of the characters in the following paragraph, the characters left over from the current paragraph get the paragraph formatting of the following paragraph.
* If you select to the end of a paragraph, but not the whole paragraph, the CR is not deleted.
* If you delete the whole paragraph (from the beginning through the CR), you delete the CR as well (unless it is the final CR in the file).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)