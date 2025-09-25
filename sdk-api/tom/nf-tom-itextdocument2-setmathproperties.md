# ITextDocument2::SetMathProperties

## Description

Specifies the math properties to use for the document.

## Parameters

### `Options` [in]

Type: **long**

The math properties to set. For a list of possible properties, see [GetMathProperties](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getmathproperties).

### `Mask` [in]

Type: **long**

The math mask. For a list of possible masks, see [GetMathProperties](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getmathproperties)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetMathProperties](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getmathproperties)