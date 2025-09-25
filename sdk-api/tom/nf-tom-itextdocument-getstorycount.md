# ITextDocument::GetStoryCount

## Description

Gets the count of stories in this document.

## Parameters

### `pCount`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The number of stories in the document.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

Rich edit controls have only one story and do not implement the [ITextDocument::GetStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getstoryranges) method. To avoid getting an error when there is only one story, use **ITextDocument::GetStoryCount** to check the story count. If the story count is greater than one, then call
**ITextDocument::GetStoryRanges**.

## See also

**Conceptual**

[GetStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getstoryranges)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)