# IResultData::ModifyViewStyle

## Description

The **IResultData::ModifyViewStyle** method enables the snap-in to set the result pane's view style.

## Parameters

### `add` [in]

A value that specifies the view style (or styles) to be set in the result view pane. This value can be a valid combination of the following:

#### MMC_SINGLESEL

Allows only one item at a time to be selected. Without this view style, multiple items can be selected.

#### MMC_SHOWSELALWAYS

Always show the selection, if any, even if the control does not have the focus.

#### MMC_NOSORTHEADER

A value that specifies that column headers do not work like buttons. This style is useful if clicking on a column header in report view does not perform an operation, such as sorting.

These values are from the
[MMC_RESULT_VIEW_STYLE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_result_view_style) enumeration and correspond to the Win32 LVS_* flags of the same names.

### `remove` [in]

A value that specifies the view style (or styles) to be removed from the result view pane. This value can be a valid combination of the preceding flags shown for the add parameter. As described there, these values are from the
[MMC_RESULT_VIEW_STYLE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_result_view_style) enumeration and correspond to the Win32 LVS_* flags of the same names.

## Return value

This method can return one of these values.

## Remarks

This method provides the same functionality for both result view panes and virtual lists.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)