# ITextDocument2::GetSelection2

## Description

Gets the active selection.

## Parameters

### `ppSel` [out, retval]

Type: **[ITextSelection2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection2)****

The active selection. This parameter is **NULL** if the rich edit control is not in-place active.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)