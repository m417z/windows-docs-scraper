# ITextRow::GetCellShading

## Description

Gets the shading of the active cell.

## Parameters

### `pValue` [out, retval]

Type: **long***

The shading of the active cell. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The shading is given in hundredths of a percent, so full shading is given by the value 10000. The shading percentage determines the mix of the cell foreground and background colors to be used for the cell background. A shading of 0 uses the cell background color alone. A shading of 10000 (100%) uses the foreground color alone. Values in between mix the foreground and background colors, weighting the background with (10000 – CellShading)/1000 and the foreground with CellShading/1000. These ratios are applied to the red, green, and blue channels independently of one another.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::SetCellShading](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setcellshading)