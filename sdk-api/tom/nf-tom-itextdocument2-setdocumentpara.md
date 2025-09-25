# ITextDocument2::SetDocumentPara

## Description

Sets the default paragraph formatting for this instance of the Text Object Model (TOM) engine.

## Parameters

### `pPara` [in]

Type: **[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)***

The paragraph object that provides the default paragraph formatting

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can also set the default paragraph formatting by calling [ITextPara::Reset(tomDefault)](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-reset).

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetDocumentPara](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getdocumentpara)