# ITextDocument2::GetDocumentFont

## Description

Gets an object that provides the default character format information for this instance of the Text Object Model (TOM) engine.

## Parameters

### `ppFont` [out, retval]

Type: **[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)****

The object that provides the default character format information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::SetDocumentFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setdocumentfont)