# ITextDocument2::GetStory

## Description

Retrieves the story that corresponds to a particular index.

## Parameters

### `Index` [in]

Type: **long**

The index of the story to retrieve.

### `ppStory` [out, retval]

Type: **[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)****

The story.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)