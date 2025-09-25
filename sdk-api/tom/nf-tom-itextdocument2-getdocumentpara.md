# ITextDocument2::GetDocumentPara

## Description

Gets an object that provides the default paragraph format information for this instance of the Text Object Model (TOM) engine.

## Parameters

### `ppPara` [out, retval]

Type: **[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)****

The object that provides the default paragraph format information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::SetDocumentPara](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setdocumentpara)