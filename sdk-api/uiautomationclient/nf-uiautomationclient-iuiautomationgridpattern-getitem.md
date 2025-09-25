# IUIAutomationGridPattern::GetItem

## Description

Retrieves a UI Automation element representing an item in the grid.

## Parameters

### `row` [in]

Type: **int**

The zero-based index of the row.

### `column` [in]

Type: **int**

The zero-based index of the column.

### `element` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the element representing the grid item.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationGridPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationgridpattern)