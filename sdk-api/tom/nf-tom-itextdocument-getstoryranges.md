# ITextDocument::GetStoryRanges

## Description

Gets the story collection object used to enumerate the stories in a document.

## Parameters

### `ppStories`

Type: **[ITextStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges)****

The [ITextStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges) pointer.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented; only one story in this document. |

## Remarks

Invoke this method only if [ITextDocument::GetStoryCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getstorycount) returns a value greater than 1.

## See also

**Conceptual**

[GetStoryCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getstorycount)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[ITextStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)