# ITextDocument2::GetCaretType

## Description

Gets the caret type.

## Parameters

### `pValue` [out, retval]

Type: **long***

The caret type. It can be one of the following values:

#### tomKoreanBlockCaret

#### tomNormalCaret

#### tomNullCaret

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::SetCaretType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setcarettype)