# ITextRow::SetCellCountCache

## Description

Sets the count of cells cached for a row.

## Parameters

### `Value` [in]

Type: **long**

The cell count.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If all cells are identical, properties need to be cached only for the cell with index 0. If the cached count is less than the cell count, the cell parameters for index CellCountCache – 1 are used for cells with larger indices.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::GetCellCountCache](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-getcellcountcache)