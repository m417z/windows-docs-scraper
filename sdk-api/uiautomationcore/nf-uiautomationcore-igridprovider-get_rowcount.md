# IGridProvider::get_RowCount

## Description

Specifies the total number of rows in the grid.

This property is read-only.

## Parameters

## Remarks

Hidden rows and columns, depending on the provider implementation, may be loaded
in the logical tree and will therefore be reflected in the
**IGridProvider::RowCount** and
[IGridProvider::ColumnCount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-igridprovider-get_columncount) properties.
If the hidden rows and columns have not yet been loaded they will not be counted.

## See also

[IGridProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-igridprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)