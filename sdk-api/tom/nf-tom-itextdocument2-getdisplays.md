# ITextDocument2::GetDisplays

## Description

Gets the displays collection for this Text Object Model (TOM) engine instance.

## Parameters

### `ppDisplays` [out, retval]

Type: **[ITextDisplays](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdisplays)****

The displays collection.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The rich edit control doesn't implement this method.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)