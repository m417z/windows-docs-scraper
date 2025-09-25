# ITextRow::SetCellIndex

## Description

Sets the index of the active cell.

## Parameters

### `Value` [in]

Type: **long**

The cell index.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can get or set parameters for an active cell.

 If the cell index is greater than the cell count, and the cell index is less that 63 (the maximum cell count), then the cell count is increased to cell index + 1.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::GetCellCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-getcellcount)

[ITextRow::GetCellIndex](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-getcellindex)

[ITextRow::SetCellCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setcellcount)