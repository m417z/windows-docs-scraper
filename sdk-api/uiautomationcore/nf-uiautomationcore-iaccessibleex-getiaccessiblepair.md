# IAccessibleEx::GetIAccessiblePair

## Description

Retrieves the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface and child ID for this item.

## Parameters

### `ppAcc` [out]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)****

Receives a pointer to the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface for this object, or the parent object if this is a child element.

### `pidChild` [out]

Type: **long***

Receives the child ID, or CHILDID_SELF if this is not a child element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex)