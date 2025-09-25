# ITextRow::GetCellCountCache

## Description

Gets the count of cells cached for this row.

## Parameters

### `pValue` [out, retval]

Type: **long***

The cached cell count.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If all cells are identical, properties need to be cached only for the cell with index 0. If the cached count is less than the cell count, the cell parameters for index CellCountCache – 1 are used for cells with larger indices.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::SetCellCountCache](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setcellcountcache)