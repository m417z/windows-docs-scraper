# IGridProvider::GetItem

## Description

Retrieves the Microsoft UI Automation provider for the specified cell.

## Parameters

### `row` [in]

Type: **int**

The ordinal number of the row of interest.

### `column` [in]

Type: **int**

The ordinal number of the column of interest.

### `pRetVal` [out, retval]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

Receives a pointer to a UI Automation provider for the specified cell or a null reference
(Nothing in Microsoft Visual Basic .NET) if the cell is empty.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Grid coordinates are zero-based with the upper left (or upper right cell depending on locale) having coordinates (0,0).

If a cell is empty a UI Automation provider must still be
returned in order to support the [ContainingGrid](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-igriditemprovider-get_containinggrid) property
for that cell. This is possible when the layout of child elements in the grid is similar to a ragged array.

Hidden rows and columns, depending on the provider implementation, may be loaded in the
UI Automation tree and will therefore be reflected in the [IGridProvider::RowCount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-igridprovider-get_rowcount)
and [IGridProvider::ColumnCount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-igridprovider-get_columncount) properties.
If the hidden rows and columns have not yet been loaded they should not be counted.

## See also

[IGridProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-igridprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)