# ITextDocument2::SetTypographyOptions

## Description

Specifies the typography options for the document.

## Parameters

### `Options` [in]

Type: **long**

The typography options to set. For a list of possible options, see [GetTypographyOptions](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-gettypographyoptions).

### `Mask` [in]

Type: **long**

A mask identifying the options to set. For example, to turn on **TO_ADVANCEDTYPOGRAPHY**, call **ITextDocument2::SetTypographyOptions (TO_ADVANCEDTYPOGRAPHY, TO_ADVANCEDTYPOGRAPHY)**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetTypographyOptions](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-gettypographyoptions)