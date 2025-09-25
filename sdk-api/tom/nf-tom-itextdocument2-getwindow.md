# ITextDocument2::GetWindow

## Description

Gets the handle of the window that the Text Object Model (TOM) engine is using to display output.

## Parameters

### `pHwnd` [out, retval]

Type: **__int64***

The handle of the window that the TOM engine is using.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A rich edit control doesn't need to own the window that the TOM engine is using. For example, the rich edit control might be windowless.

The Input Method Editor (IME) needs the handle of the window that is receiving keyboard messages. This method retrieves that handle.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)