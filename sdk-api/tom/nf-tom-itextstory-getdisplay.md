# ITextStory::GetDisplay

## Description

Gets a new display for a story.

## Parameters

### `ppDisplay` [out, retval]

Type: **IUnknown****

The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for a display.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A story can be displayed by calling [ITextStory::SetActive](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstory-setactive)(**tomDisplayActive**). The **ITextStory::GetDisplay** method is included, in case it might be advantageous to have more than one display for a set of [ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory) interfaces.

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)