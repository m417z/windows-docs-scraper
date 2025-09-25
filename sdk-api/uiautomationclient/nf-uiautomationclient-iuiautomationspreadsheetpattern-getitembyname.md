# IUIAutomationSpreadsheetPattern::GetItemByName

## Description

Retrieves a UI Automation element that represents the spreadsheet cell that has the specified name.

## Parameters

### `name` [in]

Type: **BSTR**

The name of the target cell.

### `element` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives the element that represents the target cell.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationSpreadsheetPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationspreadsheetpattern)