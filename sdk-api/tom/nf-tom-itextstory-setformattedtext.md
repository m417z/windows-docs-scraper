# ITextStory::SetFormattedText

## Description

Replaces a story’s text with specified formatted text.

## Parameters

### `pUnk` [in]

Type: **IUnknown***

The formatted text to replace the story’s text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This method calls [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for an [ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2) interface.

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)