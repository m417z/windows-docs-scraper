# ITextRow::SetCellMergeFlags

## Description

Sets the merge flags of the active cell.

## Parameters

### `Value` [in]

Type: **long**

The merge flag. It can be one of these values.

#### tomHContCell

#### tomHStartCell

#### tomVLowCell

#### tomVTopCell

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::GetCellMergeFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-getcellmergeflags)