# ITextDocument2::SetDocumentFont

## Description

Sets the default character formatting for this instance of the Text Object Model (TOM) engine.

## Parameters

### `pFont` [in]

Type: **[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)***

The font object that provides the default character formatting.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can also set the default character formatting by calling [ITextFont::Reset(tomDefault)](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-reset).

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetDocumentFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getdocumentfont)

[ITextFont::Reset](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-reset)