# ITextRow::SetCellWidth

## Description

Sets the active cell width in twips.

## Parameters

### `Value` [in]

Type: **long**

The width of the active cell.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The total width of the entire row must be less than 22 inches, or 1440×22.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::GetCellWidth](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-getcellwidth)