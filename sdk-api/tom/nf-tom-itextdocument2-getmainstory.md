# ITextDocument2::GetMainStory

## Description

Gets the main story.

## Parameters

### `ppStory` [out, retval]

Type: **[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)****

The main story.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A rich edit control automatically includes the main story; a call to the [ITextDocument2::GetNewStory](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getnewstory) method is not required.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)