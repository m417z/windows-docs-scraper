# MMC_RESULT_VIEW_STYLE enumeration

## Description

The
**MMC_RESULT_VIEW_STYLE** enumeration defines the Win32 list view style (LVS_*) flags that can be used to set the view style in the MMC result view pane. They can be used in the *add* and *remove* parameters of the
[IResultData::ModifyViewStyle](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-modifyviewstyle) method.

## Constants

### `MMC_SINGLESEL:0x0001`

Allows only one item at a time to be selected. Without this view style, multiple items can be selected.

### `MMC_SHOWSELALWAYS:0x0002`

Always show the selection, if any, even if the control does not have the focus.

### `MMC_NOSORTHEADER:0x0004`

A value that specifies that column headers do not work like buttons. This style is useful if clicking a column header in report view does not carry out an action, such as sorting.

### `MMC_ENSUREFOCUSVISIBLE`