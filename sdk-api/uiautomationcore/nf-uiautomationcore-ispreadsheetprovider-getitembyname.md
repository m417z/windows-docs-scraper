# ISpreadsheetProvider::GetItemByName

## Description

Exposes a UI Automation element that represents the spreadsheet cell that has the specified name.

## Parameters

### `name` [in]

Type: **LPCWSTR**

The name of the target cell.

### `pRetVal` [out, retval]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

Receives the element that represents the target cell.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A spreadsheet cell typically has a name such as “c5” or “a15”. A name can also apply to a range of cells.

## See also

[ISpreadsheetProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ispreadsheetprovider)