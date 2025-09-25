# ITextDocument2::Range2

## Description

Retrieves a new text range for the active story of the document.

## Parameters

### `cpActive` [in]

Type: **long**

The active end of the new text range. The default value is 0; that is, the beginning of the story.

### `cpAnchor` [in]

Type: **long**

The anchor end of the new text range. The default value is 0.

### `ppRange` [out, retval]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)****

The new text range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)