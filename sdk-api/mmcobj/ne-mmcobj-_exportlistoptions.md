# _ExportListOptions enumeration

## Description

The
**ExportListOptions** enumeration is used by the
[View.ExportList](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-exportlist) method and specifies options when writing list view contents to a file. These values can be combined using a bitwise OR operation. This enumeration applies to the
[MMC 2.0 Automation Object Model](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-2-0-automation-object-model).

## Constants

### `ExportListOptions_Default:0`

Default list export option. If this is the only flag specified in the call to [View.ExportList](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-exportlist), then the list view contents are exported as comma-delimited ANSI text.

### `ExportListOptions_Unicode:0x1`

The list is exported as Unicode text.

### `ExportListOptions_TabDelimited:0x2`

The list is exported as tab-delimited text.

### `ExportListOptions_SelectedItemsOnly:0x4`

The exported list contains only currently selected items.

## See also

[View object](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-object)

[View.ExportList](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-exportlist)