# ITextDocument2::GetActiveStory

## Description

Gets the active story; that is, the story that receives keyboard and mouse input.

## Parameters

### `ppStory` [out, retval]

Type: **[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)****

The active story.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::SetActiveStory](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setactivestory)