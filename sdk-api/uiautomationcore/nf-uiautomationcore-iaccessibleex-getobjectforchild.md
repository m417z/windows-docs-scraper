# IAccessibleEx::GetObjectForChild

## Description

Retrieves an [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) interface representing the specified child of this element.

## Parameters

### `idChild` [in]

Type: **long**

The identifier of the child element.

### `pRetVal` [out]

Type: **[IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex)****

Receives a pointer to the [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*pRetVal* returns **NULL** if this implementation does not use child IDs, or cannot provide an [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) interface for the specified child, or itself represents a child element.

*idChild* must represent an actual MSAA child element, not an object that has its own [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface.

## See also

[IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex)