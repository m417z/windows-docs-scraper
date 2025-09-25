# ITextDocument2::GetStoryRanges2

## Description

Gets an object for enumerating the stories in a document.

## Parameters

### `ppStories` [out, retval]

Type: **[ITextStoryRanges2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges2)****

The object for enumerating stories.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method only if the [ITextDocument::GetStoryCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getstorycount) method returns a value that is greater than one.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)