# ITextRange::GetIndex

## Description

Retrieves the story index of the *Unit* parameter at the specified range Start character position. The first *Unit* in a story has an index value of 1. The index of a *Unit* is the same for all character positions from that immediately preceding the *Unit* up to the last character in the *Unit*.

## Parameters

### `Unit`

Type: **long**

Unit that is indexed. For a list of possible *Unit* values, see the discussion under [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `pIndex`

Type: **long***

The index value. The value is zero if *Unit* does not exist.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pIndex* is null. |
| **E_NOTIMPL** | Unit does not exist. |

## Remarks

The **ITextRange::GetIndex** method retrieves the story index of a word, line, sentence, paragraph, and so forth, at the range Start. *Unit* specifies which kind of entity to index, such as words (**tomWord**), lines (**tomLine**), sentences (**tomSentence**), or paragraphs (**tomParagraph**). For example, **ITextRange::GetIndex** sets *pIndex* equal to the line number of the first line in the range. For a range at the end of the story, **ITextRange::GetIndex**, returns the number of *Unit*s in the story. Thus, you can get the number of words, lines, objects, and so forth, in a story.

The index value returned by the **ITextRange::GetIndex** method is not valid if the text is subsequently edited. Thus, users should be careful about using methods that return index values, especially if the values are to be stored for any duration. This is in contrast to a pointer to a range, which does remain valid when the text is edited.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)