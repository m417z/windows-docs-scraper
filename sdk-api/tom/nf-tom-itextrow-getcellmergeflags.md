# ITextRow::GetCellMergeFlags

## Description

Gets the merge flags of the active cell.

## Parameters

### `pValue` [out, retval]

Type: **long***

The merge flag of the active cell. The flag can be one of the following:

#### tomHContCell

#### tomHStartCell

#### tomVLowCell

#### tomVTopCell

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::SetCellMergeFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-setcellmergeflags)