# ITextRow::GetAlignment

## Description

Gets the horizontal alignment of a row.

## Parameters

### `pValue` [out, retval]

Type: **long***

The horizontal alignment. It can be one of the following values.

[tomAlignLeft](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomAlignRight](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::SetAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setalignment)