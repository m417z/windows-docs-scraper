# ITextRow::GetCellWidth

## Description

Gets the width of the active cell.

## Parameters

### `pValue` [out, retval]

Type: **long***

The width of the active cell, in twips.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The width of the cell, and/or the entire row, must be less than 22 inches (1440 x 22).

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::SetCellWidth](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setcellwidth)